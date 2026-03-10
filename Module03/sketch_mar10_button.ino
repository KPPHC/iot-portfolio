/*
  This code is created by merging:
  Input Pull-up Serial from https://docs.arduino.cc/built-in-examples/digital/InputPullupSerial/ by Scott Fitzgerald
  and
  Debouncing
  and
  simple_esp8266 from MQTTT

  An esp8266 is connected to a button via GND and D5
  It publishes to 192.168.14.1 on IOT14 wifi whenever the button is pressed via MQTT
*/

#include <ESP8266WiFi.h>
#include <espMqttClient.h>

#define WIFI_SSID "IOT14"
#define WIFI_PASSWORD "iotempire"

#define MQTT_HOST IPAddress(192, 168, 14, 1)
#define MQTT_PORT 1883

WiFiEventHandler wifiConnectHandler;
WiFiEventHandler wifiDisconnectHandler;
espMqttClient mqttClient;
bool reconnectMqtt = false;
uint32_t lastReconnect = 0;


// Variables will change:
int codeblueState = LOW;        // the current state of the output pin
int buttonState;            // the current reading from the input pin
int lastButtonState = HIGH;  // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers


void AnyaSubscriptions() {
  mqttClient.subscribe("station/alert/#", 1);
  mqttClient.subscribe("station/supplies/blood/temp", 1);
}

void DavidSubscriptions() {
  mqttClient.subscribe("station/announcements", 1);
  mqttClient.subscribe("station/alert/#", 1);
}

void connectToWiFi() {
  Serial.println("Connecting to Wi-Fi...");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
}

void connectToMqtt() {
  Serial.println("Connecting to MQTT...");
  if (!mqttClient.connect()) {
    reconnectMqtt = true;
    lastReconnect = millis();
    Serial.println("Connecting failed.");
  } else {
    reconnectMqtt = false;
  }
}

void onWiFiConnect(const WiFiEventStationModeGotIP& event) {
  (void) event;
  Serial.println("Connected to Wi-Fi.");
  connectToMqtt();
}

void onWiFiDisconnect(const WiFiEventStationModeDisconnected& event) {
  (void) event;
  Serial.println("Disconnected from Wi-Fi.");
}

void onMqttConnect(bool sessionPresent) {
  Serial.println("Connected to MQTT.");
  Serial.print("Session present: ");
  Serial.println(sessionPresent);
  uint16_t packetIdSub = mqttClient.subscribe("test/lol", 2);
  Serial.print("Subscribing at QoS 2, packetId: ");
  Serial.println(packetIdSub);
  mqttClient.publish("test/lol", 0, true, "test 1");
  Serial.println("Publishing at QoS 0");
  uint16_t packetIdPub1 = mqttClient.publish("test/lol", 1, true, "test 2");
  Serial.print("Publishing at QoS 1, packetId: ");
  Serial.println(packetIdPub1);
  uint16_t packetIdPub2 = mqttClient.publish("test/lol", 2, true, "test 3");
  Serial.print("Publishing at QoS 2, packetId: ");
  Serial.println(packetIdPub2);
}

void onMqttDisconnect(espMqttClientTypes::DisconnectReason reason) {
  Serial.printf("Disconnected from MQTT: %u.\n", static_cast<uint8_t>(reason));

  if (WiFi.isConnected()) {
    reconnectMqtt = true;
    lastReconnect = millis();
  }
}

void onMqttSubscribe(uint16_t packetId, const espMqttClientTypes::SubscribeReturncode* codes, size_t len) {
  Serial.println("Subscribe acknowledged.");
  Serial.print("  packetId: ");
  Serial.println(packetId);
  for (size_t i = 0; i < len; ++i) {
    Serial.print("  qos: ");
    Serial.println(static_cast<uint8_t>(codes[i]));
  }
}

void onMqttUnsubscribe(uint16_t packetId) {
  Serial.println("Unsubscribe acknowledged.");
  Serial.print("  packetId: ");
  Serial.println(packetId);
}

void onMqttMessage(const espMqttClientTypes::MessageProperties& properties, const char* topic, const uint8_t* payload, size_t len, size_t index, size_t total) {
  (void) payload;
  Serial.println("Publish received.");
  Serial.print("  topic: ");
  Serial.println(topic);
  Serial.print("  qos: ");
  Serial.println(properties.qos);
  Serial.print("  dup: ");
  Serial.println(properties.dup);
  Serial.print("  retain: ");
  Serial.println(properties.retain);
  Serial.print("  len: ");
  Serial.println(len);
  Serial.print("  index: ");
  Serial.println(index);
  Serial.print("  total: ");
  Serial.println(total);
}

void onMqttPublish(uint16_t packetId) {
  Serial.println("Publish acknowledged.");
  Serial.print("  packetId: ");
  Serial.println(packetId);
}


void setup() {
  //start serial connection
  Serial.begin(115200);
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(D2, INPUT_PULLUP);
  pinMode(13, OUTPUT);

  //wifi setup
  WiFi.setAutoConnect(false);
  WiFi.setAutoReconnect(true);

  wifiConnectHandler = WiFi.onStationModeGotIP(onWiFiConnect);
  wifiDisconnectHandler = WiFi.onStationModeDisconnected(onWiFiDisconnect);

  //mqtt client setup
  mqttClient.onConnect(onMqttConnect);
  mqttClient.onDisconnect(onMqttDisconnect);
  mqttClient.onSubscribe(onMqttSubscribe);
  mqttClient.onUnsubscribe(onMqttUnsubscribe);
  mqttClient.onMessage(onMqttMessage);
  mqttClient.onPublish(onMqttPublish);
  mqttClient.setServer(MQTT_HOST, MQTT_PORT);

  connectToWiFi();
}

void loop() {

  //mqtt looping
  static uint32_t currentMillis = 0;
  currentMillis = millis();

  mqttClient.loop();
  if (reconnectMqtt && currentMillis - lastReconnect > 5000) {
    connectToMqtt();
  }

  //read the pushbutton value into a variable
  int reading = digitalRead(D2);
  

  // Keep in mind the pull-up means the pushbutton's logic is inverted. It goes
  // HIGH when it's open, and LOW when it's pressed. Turn on pin 13 when the
  // button's pressed, and off when it's not:
  if (reading != lastButtonState) {
    lastDebounceTime = currentMillis;
  }

  if ((currentMillis - lastDebounceTime) > debounceDelay) {
    
    // 4. If the state actually changed
    if (reading != buttonState) {
      buttonState = reading;

      // 5. Handle the Press (LOW)
      if (buttonState == LOW) {
        Serial.println("Code Blue");
        mqttClient.publish("station/alert/emergency/wardB", 1, false, "Code Blue");
        digitalWrite(13, HIGH); // Turn on LED for feedback
      }

      // 6. Handle the Release (HIGH)
      if (buttonState == HIGH) {
        Serial.println("All OK!");
      }
    }
  }

  lastButtonState = reading;
}
