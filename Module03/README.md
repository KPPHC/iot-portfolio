
# Module 3
## UNESCO biosphere
IN Quebec, data collection, communication overhead. A team of 20 people, biologists etc, managing a cartography system. Showed one example of data, where it shows fire hazard. Showed collab with industry - paper industry. 

A key problem is erosion, collab with an organization that makes projection. On the map it shows erosion and the residences at risk. Mainly the ocean is available, but not river and the lake. But the issue is, that the currents/water/soil/sand/clay on riverbanks are a bit unpredicatble - hard to know where/when this is moving. Specifically, the changes in ocean currents due to climate change are one of the causes, why this is unpredictable. -- perhaps a network of turbidity sensors across the banks, and some fancy modelling of the signals - perhaps this can show the shifting of the sedimentation.

Another problem is that there are more and more cruise ships brought. This is causing noise. How much noise? When is it too much? Measuring this underwater is key information for policymakers. -- naive solution is to just take a bunch of microphones and put them somehow into the water.

Another problem is that fire causes ash to get into the water. -- pH sensors (ashes make water alkaline); CO2/CO sensor for detecting the greenhouse gases of active fires

Much cooperation b/w artists and scientists.

## Renato
# Intranet vs Internet vs LAN vs WAN


# [Common communication hardware and terminology](https://www.geeksforgeeks.org/computer-networks/network-devices-hub-repeater-bridge-switch-router-gateways/)
**Intranet** - is a very classic system, and the hint is in the name. It is a net of computers, that is happening inside (intra) some organization/institute. An addition to this is _extranet_, that allows partners and customers to also interface with this. The difference from internet is that intranet/extranet is high security access.
**Internet** - so now, the network is between these organization.
**LAN** - local area network
**WAN** - widely accessed network
**Router** - Connects multiple networks (your home LAN to the internet WAN), using IP addresses to determine the best path for data packets to travel, maintaining a Routing table. Routers stop broadcast traffic, isolating networks from each other.
**Switch** - connects devices in a LAN. Unlike a hub, a Switch learns MAC address of every connected device and sends data only to the specific port where the destination device is connected
**Bridge** - connects two separate LAN segments to make them appear as one. Filters traffic based on MAC addresses to keep local traffic local, reducing congestion. Largely replaced by Switches (which are essentially multi-port bridges).
**Access Point** - creates a WLAN, acting as a bridge b/w wired Ethernet and wireless WiFi. It only provides WiFi signal, but does not route traffic or assigne IP Addresses (unless it is a "wireless router")
**DNSmasq** - domain name service, meaning it gives the IP addresses a human readable name (instead of 8.8.8.8 we have google.com)
**DHCP** - a system that assigns IP addresses. we talked about localhost (196.168.xx.xx). The ports at the end are given as a lease. The way to recognize a previous device is the MAC address, those are unique and permanent for each device.
**Server**
**ISP**
**Modem**

2.4 GHz vs 5 GHz - these are different bands that are used. each person is given rental / limited access to a specific wavelength of the band (channel). All the communication is happening within that wavelength - if it is crowded, then may cause noise and issues. The channels are numbered. In Estonia 14 is illegal to use and is reserved for military.

We are using a Mango pocket router.

How many clients it can handle? - stable up to 5

Frequencies that the Mango can do? - 2.4GHz

What OS? - OpenWRT, based on Linux

# OpenWrt
Embedded Linux
It's modules are standardized, meaning it is stable, well-tested, and should be compatible with even old equipment.
It touts it's security, is kept up-to-date.
Open-source, community support

# MQTT protocol
So basically, what it consists of is clients and brokers. Clients publish to a broker on the topic, and the broker distributes to whatever clients have subscribed to the topic. An example of pub-sub is Slack: a topic would be the Delta Centre, then subtopic are the specific channels inside there (could also have sub-subgroups).
How hard it is to create a topic? Not really that difficult.
Wildcard (this symbol #) is used to signify that you want to subscribe into any topic within that hierarchy: e.g. instructions/#

# Workbook - https://docs.google.com/document/d/1412jrNT1CTWUsnEwqp1IGEA6AjrsfRwe06ogvfTVqWU/edit?tab=t.h5nxjadzs77g#heading=h.x73np36g16zd

# Do you wanna play a game? MQTT to the rescue
**Scenario** - In many countries many need help. Infrastructure is damaged. In Langtang, a volunteer rescue team is set up for first-aid administration. They knew that communication could help save lives in time-critical situations, such as getting essential supplies to where they were needed and calling in personnel (doctors and nurses) to attend to an emergency. 
**Equipment** - A mango, and one Ethernet cable with internet access (allowed to DL applications and dependencies)
**Task** - Deploy a DIY LAN for the First-Aid Station. It has to work locally and be stand-alone. Your team should set up a Local Area Network (LAN) with a Wi-Fi access point and an MQTT broker to establish a simple communication system within the station. You must accomplish this using the router.


**Team name:** Crocodile
**Mango number:** 14
**Mango LUCI username:** root
**Mango LUCI passowrd:** network123
**Mango SSID:** IOT14
**Mango WiFi password:** iotempire
1) For the class purposes, we downloaded MyMQTT application on our phones. We connected our phones to MARIA NETWORK, with the password _iotempire_. Once connected, we connected to a the broker 192.168.14.1, and subscribed to topics _instructions/#_, which meant we got all next instructions from there as published by the instructor.
2) We connected our router to the power socket and via ethernet (LAN) to one of the laptops. We figured out the routers IP (in cmd ipconfig for Windows). Our routers IP: 192.168.1.1.
3) In the MyMQTT application, for the class purposes we also published our team name by writing to _phase1/verification/Crocodile_ with the message of the routers original IP address 
4) Using the IP written into a browser, we connected with LUCI (the router's interface), navigated to Interfaces, and there changed the LAN IP to be the same as the gateway's IP (192.168.14.1). Save & Apply (unchecked!). Disconnect and Reconnect the ethernet cable.
5) Using the new IP, we now re-entered into the LUCI. Successfully entering confirmed the IP address change
6) We now setup the Mango as a WiFi accesspoint. We first scanned using Channel Analyzer to find out what channels are not crowded (we decided on channel 9) - NB! Channel 14 is reserved for the military in Estonia.
7) Secondly, we navigated again to interfaces, and setup the WiFi. Set the channel to 9, SSID IOT14, and security to WPA2-PSK with the password _iotempire_.
8) We now disconnected the ethernet cable from our laptop, and connected our router with the ethernet cable (WAN) to a switch to download dependencies.
9) We connected our laptop with the router over WiFi (IOT14).
10) We checked the connection by writing into cmd _ping openwrt.org_
11) We re-opened LUCI, and navigated to the Software menu, and updated the list of packages available.
12) We found and installed each of the following packages: mosquitto-ssl,  luci-app-mosquitto and luci-app-commands
13) We went into Services -> Mosquitto and configured the Mosquitto broker: a) check the box for use this LuCI configuration; b) enable Allow anonymous connections; c) add a Listener with Port 1883 and under it's protocol set to MQTT
14) We navigated Services -> Custom Commands, and created a command that runs _netstat -tulpn_. Save the command
15) We navigated back to the Dashboard, ran the created command, and confirmed the PID of the mosquitto process to confirm it is running (we saw 0.0.0.0.0:1883, LISTENING at 3930/mosquitto (PID/mosquitto)).
16) To test whether it is working, we disconnected our phones from MARIA NETWORK, and connected to our own IOT14 WiFi.
17) One of the phones subscribed to topic Crocodile/mqtt/#, and the other published a test message separately on Crocodile/mqtt/test1 and Crocodile/mqtt/test2. Screenshots below.


# Extra optional task
1) We first installed the dependency: **kmod-usb-net-rndis**
2) We created new interface **usb0**, the device **eth1** chose the firewall **wan wan6**
3) It works when we pinged openwrt.org, even after removing the connection to our switch.

## Reflection 3
[Reflection 3](/Reflections/ref03.md)
