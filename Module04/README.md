# Module 4
## Crashes
1) nullpointer dereference
´´´
char* super_message;
´´´

3) memory issues
memory leak:
```cpp
char* msg = new char[512]
```
we allocate some variables, but dont delete. so if we have a function 

memory fragmentation: memory keeps growing and reallocating, heap becomes "many small holes", so big allocations fail
```cpp
static String extend_msg;
extend_msg += msg;
```
At the beginning we had 100 bytes allocated, but as we extend, then this 100 bytes is released, and a larger memory is still given. This problem is unclear for me. How can

For debugging you can use memory prints:
```cpp
Serial.println(ESP.getFreeHeap());
```

3) interrupts
ISR - Interrupt Service Routine
small function that runs immediately when an interrup happens (like CTRL+C, a timer, an event etc)
should be in a very short time (seconds)

## Buses
1) PWM for smooth flashing
PWM is for a modulated output
```cpp
analogWrite(ledPin, brigthness);
```
Brightness depends on the duty cycle (the percentage of time it's on).

2) UART communication (Universal Asynchronous Receiver-Transmitter)
Simple wired communication for sending data one byte at a time.
It has three connections:
- TX
- RX
- GND
Both devices must use the same baud rate.
On ESP32, there is two kinds of UART:
- Serial = UART0 -> USB, upload, serial monitor
- HardwareSerial(2) = UART2 -> this is something that you would need to use when communicating between two ESP32 (how about between ESP32 and ESP8266?)

# Task1
Broken code prints
```
11:12:55.300 -> 3fffffc0:  feefeffe feefeffe 3fffdab0 40100d95  
11:12:55.300 -> <<<stack<<<
11:12:55.300 -> 
11:12:55.300 -> --------------- CUT HERE FOR EXCEPTION DECODER ---------------
11:12:55.319 -> 
11:12:55.319 ->  ets Jan  8 2013,rst cause:2, boot mode:(3,6)
11:12:55.319 -> 
11:12:55.319 -> load 0x4010f000, len 3424, room 16 
11:12:55.319 -> tail 0
11:12:55.319 -> chksum 0x2e
11:12:55.319 -> load 0x3fff20b8, len 40, room 8 
11:12:55.319 -> tail 0
11:12:55.319 -> chksum 0x2b
11:12:55.356 -> csum 0x2b
11:12:55.356 -> v000459f0
11:12:55.356 -> ~ld
11:12:55.395 -> ��n�r��n|�l�l`bbrl�nb�nl`�rl�l��
11:12:55.427 -> Connecting to IOT14
11:12:56.015 -> .......
11:12:59.754 -> WiFi connected
11:12:59.754 -> IP address: 
11:12:59.754 -> 192.168.14.182
11:12:59.754 -> Attempting MQTT connection...connected
11:12:59.754 -> Publish message: hello world #1
```

Fixed code prints
```
11:20:10.452 -> Publish message: hello world #8
11:20:11.095 -> Something special coming up...
11:20:11.138 -> The following:A
11:20:11.138 -> Message arrived [inTopic] test
11:20:12.419 -> Publish message: hello world #9
```

## Task 2
Broken code prints
```
11:24:22.760 -> >>>stack>>>
11:24:22.760 -> 
11:24:22.760 -> ctx: cont
11:24:22.760 -> sp: 3ffffe60 end: 3fffffd0 offset: 0150
11:24:22.760 -> 3fffffb0:  3fffdad0 00000000 3ffee744 402041e8  
11:24:22.760 -> 3fffffc0:  feefeffe feefeffe 3fffdab0 40100d95  
11:24:22.792 -> <<<stack<<<
11:24:22.792 -> 
11:24:22.792 -> --------------- CUT HERE FOR EXCEPTION DECODER ---------------
11:24:22.792 -> 
11:24:22.792 ->  ets Jan  8 2013,rst cause:2, boot mode:(3,6)
11:24:22.792 -> 
11:24:22.792 -> load 0x4010f000, len 3424, room 16 
11:24:22.792 -> tail 0
11:24:22.841 -> chksum 0x2e
11:24:22.841 -> load 0x3fff20b8, len 40, room 8 
11:24:22.841 -> tail 0
11:24:22.841 -> chksum 0x2b
11:24:22.841 -> csum 0x2b
11:24:22.841 -> v000459c0
11:24:22.841 -> ~ld
11:24:22.883 -> ��n�r��n|�l�l`bbrl�nb�nl`�rl�l��
11:24:22.919 -> Connecting to IOT14
11:24:23.516 -> .......
11:24:27.230 -> WiFi connected
11:24:27.230 -> IP address: 
11:24:27.230 -> 192.168.14.182
11:24:27.230 -> Attempting MQTT connection...connected
11:24:27.230 -> Publish message: hello world #9 - division 111
```


Fixed code prints
```
11:30:56.436 -> Publish message: hello world #1 - division 1000
11:30:58.406 -> Warning: Attempted division by zero avoided!
11:30:58.406 -> Publish message: hello world #0 - division UNDEFINED
11:31:00.435 -> Publish message: hello world #-1 - division -1000
```

## Task 3
Broken code prints
```
11:48:56.425 -> Publish message: hello world #74
11:49:01.575 -> 
11:49:01.575 -> User exception (panic/abort/assert)
11:49:01.575 -> --------------- CUT HERE FOR EXCEPTION DECODER ---------------
11:49:01.611 -> 
11:49:01.611 -> Unhandled C++ exception: OOM
11:49:01.611 -> 
11:49:01.611 -> >>>stack>>>
11:49:01.611 -> 
11:49:01.611 -> ctx: cont
11:49:01.611 -> sp: 3fffff60 end: 3fffffd0 offset: 0010
11:49:01.611 -> 3fffff70:  0000000c 00008546 00000200 40203fcc  
11:49:01.611 -> 3fffff80:  00000000 3ffee620 3ffee658 402012ef  
11:49:01.611 -> 3fffff90:  00000000 00000000 3ffee658 3ffee7a8  
11:49:01.611 -> 3fffffa0:  3fffdad0 3ffee620 3ffee658 402013be  
11:49:01.611 -> 3fffffb0:  3fffdad0 00000000 3ffee77c 402042ec  
11:49:01.643 -> 3fffffc0:  feefeffe feefeffe 3fffdab0 40100d95  
11:49:01.643 -> <<<stack<<<
11:49:01.643 -> 
11:49:01.643 -> last failed alloc call: 402012EF(512)
11:49:01.643 -> 
11:49:01.643 -> --------------- CUT HERE FOR EXCEPTION DECODER ---------------
11:49:01.643 -> 
11:49:01.643 -> last failed alloc caller: 0x402012ef
11:49:01.643 -> 
11:49:01.643 ->  ets Jan  8 2013,rst cause:2, boot mode:(3,6)
11:49:01.643 -> 
11:49:01.643 -> load 0x4010f000, len 3424, room 16 
11:49:01.685 -> tail 0
11:49:01.685 -> chksum 0x2e
11:49:01.685 -> load 0x3fff20b8, len 40, room 8 
11:49:01.685 -> tail 0
11:49:01.685 -> chksum 0x2b
11:49:01.685 -> csum 0x2b
11:49:01.685 -> v00045ad0
11:49:01.685 -> ~ld
11:49:01.720 -> ��n�r��n|�l�l`bbrl�nb�nl`�rl�l��
11:49:01.757 -> Connecting to IOT14
11:49:02.374 -> .......
11:49:06.076 -> WiFi connected
11:49:06.076 -> IP address: 
11:49:06.076 -> 192.168.14.182
11:49:06.076 -> Attempting MQTT connection...connected
11:49:06.124 -> Publish message: hello world #1
```

OOM broken prints:
```
11:46:54.062 -> Publish message: hello world #93
11:46:59.583 -> Publish message: hello world #94
11:47:04.618 -> 
11:47:04.618 -> User exception (panic/abort/assert)
11:47:04.650 -> --------------- CUT HERE FOR EXCEPTION DECODER ---------------
11:47:04.650 -> 
11:47:04.650 -> Unhandled C++ exception: OOM
11:47:04.650 -> 
11:47:04.650 -> >>>stack>>>
11:47:04.650 -> 
11:47:04.650 -> ctx: cont
11:47:04.650 -> sp: 3fffff60 end: 3fffffd0 offset: 0010
11:47:04.650 -> 3fffff70:  0000000c 000082f1 00000200 40203fd4  
11:47:04.650 -> 3fffff80:  00000000 3ffee620 3ffee658 402012ef  
11:47:04.650 -> 3fffff90:  00000000 00000000 3ffee658 3ffee7a8  
11:47:04.650 -> 3fffffa0:  3fffdad0 3ffee620 3ffee658 402013c6  
11:47:04.687 -> 3fffffb0:  3fffdad0 00000000 3ffee77c 402042f4  
11:47:04.687 -> 3fffffc0:  feefeffe feefeffe 3fffdab0 40100d95  
11:47:04.687 -> <<<stack<<<
11:47:04.687 -> 
11:47:04.687 -> last failed alloc call: 402012EF(512)
11:47:04.687 -> 
11:47:04.687 -> --------------- CUT HERE FOR EXCEPTION DECODER ---------------
11:47:04.687 -> 
11:47:04.687 -> last failed alloc caller: 0x402012ef
11:47:04.687 -> 
11:47:04.687 ->  ets Jan  8 2013,rst cause:2, boot mode:(3,6)
11:47:04.728 -> 
11:47:04.728 -> load 0x4010f000, len 3424, room 16 
11:47:04.728 -> tail 0
11:47:04.728 -> chksum 0x2e
11:47:04.728 -> load 0x3fff20b8, len 40, room 8 
11:47:04.728 -> tail 0
11:47:04.728 -> chksum 0x2b
11:47:04.728 -> csum 0x2b
11:47:04.728 -> v00045ae0
11:47:04.728 -> ~ld
11:47:04.803 -> ��n�r��n|�l�l`bbrl�nb�nl`�rl�l��
11:47:04.803 -> Connecting to IOT14
11:47:05.417 -> .......
11:47:09.139 -> WiFi connected
11:47:09.139 -> IP address: 
11:47:09.139 -> 192.168.14.182
11:47:09.139 -> Attempting MQTT connection...connected
11:47:09.139 -> Publish message: hello world #1
11:47:09.373 -> Publish message: hello world #2
11:47:09.579 -> Publish message: hello world #3
11:47:09.774 -> Publish message: hello world #4
```


## Task 4
```
12:41:45.483 -> Hello, I am alive and counting: 317
12:41:45.593 -> Hello, I am alive and counting: 318
12:41:45.593 -> Interrupt occurred!
12:41:45.701 -> Hello, I am alive and counting: 319
12:41:45.772 -> Hello, I am alive and counting: 320
```

When commenting out the delay(1000); inside the ISR, then it stopped crashing. In the lecture it was mentioned, that ISRs are really short. The reason from [Arduino docs](https://docs.arduino.cc/language-reference/en/functions/external-interrupts/attachInterrupt/):
"Generally, an ISR should be as short and fast as possible. If your sketch uses multiple ISRs, only one can run at a time; Other interrupts will be executed after the current one finishes, in an order that depends on their priority. millis() relies on interrupts to count, so it will never increment inside an ISR. Since delay() requires interrupts to work, it will not function if called inside an ISR. micros() works initially but starts behaving erratically after 1-2 ms. delayMicroseconds() does not use a counter, so it will work as usual."


## Task 5
Getting PlatformIO to work through WSL generally is rather feeble. However, it is possible. For that, you need to make USB forwarding, and for OverTheAir, you need to mirror the IP address to WSL.

### Forwarding the USB
First, you need to get WSL USB manager ([GitHub repo](https://github.com/nickbeth/wsl-usb-manager)), and forward the port to your WSL. To check whether it works you can run in WSL:
```
lsusb
dmesg | grep tty
```
And you should see something like: 
```
_Bus 001 Device 003: ID 1a86:7523 QinHeng Electronics CH340 serial converter_
[  205.315951] usb 1-1: ch341-uart converter now attached to ttyUSB0
```
Ideally, VSCode PlatformIO should pick up that port automatically, but you can also specify it via _upload_port_ and _monitor_port_ in the _platformio.ini_
```
[env:d1_mini]
platform = espressif8266
board = d1_mini
framework = arduino

upload_port = /dev/ttyUSB0

monitor_port = /dev/ttyUSB0
monitor_speed = 115200
```
If you can Upload from VSCode, then the USB forwarding should be working properly.

### Making the OTA
#### 1. Setting up WSL mirroring config
In PowerShell:
```
notepad %USERPROFILE%\.wslconfig
```
And make a new file if it prompts you to make. Then copy inside the following:
```
[wsl2]
networkingMode=mirrored
```
After that restart your PC.

```
hostname -I
```
And you should see something here:
```
192.168.14.138 172.18.0.1 172.17.0.1 fd39:f229:307c::a59 fd39:f229:307c:0:de93:2887:9e3a:c42b fd39:f229:307c:0:cdcc:e233:9d40:7425
```
Where the 192.168.14.138 for my case was the IP address of my Windows. Seeing this in WSL, this confirms that mirroring is successful.


#### 2. Verify the upload_port
Use the [ESP8266 example provided](https://raw.githubusercontent.com/esp8266/Arduino/refs/heads/master/libraries/ArduinoOTA/examples/BasicOTA/BasicOTA.ino)
And flash it on via USB port to check what is the IP address of the MCU in the WiFi subnet.
The IP address will be printed in the Serial Monitor - for me it was 192.168.14.182.
Add it to _platformio.ini_:
```
upload_port = 192.168.14.182
```


#### 3. Making the firewall exceptions
In PowerShell you have to make a windows firewall exception.
```
New-NetFirewallRule -DisplayName "PlatformIO_OTA_Static" -Direction Inbound -Action Allow -Protocol TCP -LocalPort 8266
```


#### 4. Making sure the ports are reachable
And in _platformio.ini_:
```
upload_flags = 
    --auth=iotempower
    --host_ip=192.168.14.138
    --host_port=8266
```

#### 5. Running the upload
Unfortunately, this still only works via PlatformIO CLI, not through the VSCode IDE extension. But you should be able to run with this command on WSL:
```
pio run -e d1_mini_ota -t upload
```




