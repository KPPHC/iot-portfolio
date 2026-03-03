
# Module 3
## UNESCO biosphere
IN Quebec, data collection, communication overhead. A team of 20 people, biologists etc, managing a cartography system. Showed one example of data, where it shows fire hazard. Showed collab with industry - paper industry. 

A key problem is erosion, collab with an organization that makes projection. On the map it shows erosion and the residences at risk. Mainly the ocean is available, but not river and the lake. But the issue is, that the currents/water/soil/sand/clay on riverbanks are a bit unpredicatble - hard to know where/when this is moving. Specifically, the changes in ocean currents due to climate change are one of the causes, why this is unpredictable. -- perhaps a network of turbidity sensors across the banks, and some fancy modelling of the signals - perhaps this can show the shifting of the sedimentation.

Another problem is that there are more and more cruise ships brought. This is causing noise. How much noise? When is it too much? Measuring this underwater is key information for policymakers. -- naive solution is to just take a bunch of microphones and put them somehow into the water.

Another problem is that fire causes ash to get into the water. -- pH sensors (ashes make water alkaline); CO2/CO sensor for detecting the greenhouse gases of active fires

Much cooperation b/w artists and scientists.

## Renato
# Intranet vs Internet vs LAN vs WAN
Intranet - is a very classic system, and the hint is in the name. It is a net of computers, that is happening inside (intra) some organization/institute. An addition to this is _extranet_, that allows partners and customers to also interface with this. The difference from internet is that intranet/extranet is high security access.
Internet - so now, the network is between these organization.
LAN - local area network
WAN - widely accessed network

# Mango router - [https://www.geeksforgeeks.org/computer-networks/network-devices-hub-repeater-bridge-switch-router-gateways/](https://www.geeksforgeeks.org/computer-networks/network-devices-hub-repeater-bridge-switch-router-gateways/)
**Router** - Connects multiple networks (your home LAN to the internet WAN), using IP addresses to determine the best path for data packets to travel, maintaining a Routing table. Routers stop broadcast traffic, isolating networks from each other.
**Switch** - connects devices in a LAN. Unlike a hub, a Switch learns MAC address of every connected device and sends data only to the specific port where the destination device is connected
**Bridge** - connects two separate LAN segments to make them appear as one. Filters traffic based on MAC addresses to keep local traffic local, reducing congestion. Largely replaced by Switches (which are essentially multi-port bridges).
**Access Point** - creates a WLAN, acting as a bridge b/w wired Ethernet and wireless WiFi. It only provides WiFi signal, but does not route traffic or assigne IP Addresses (unless it is a "wireless router")
**DNSmasq**
**DHCP** - a system that assigns IP addresses. we talked about localhost (196.168.xx.xx). The ports at the end are given as a lease. The way to recognize a previous device is the MAC address, those are unique and permanent for each device.
**Server**
**ISP**
**Modem**

So now returning to the mango, what is here.
How many clients it can handle - stable up to 5
Frequencies that the mango can do - 2.4GHz
OS - OpenWRT, based on Linux

# OpenWrt
Embedded Linux
It's modules are standardized, meaning it is stable, well-tested, and should be compatible with even old equipment.
It touts it's security, is kept up-to-date.
Open-source, community support

# MQTT protocol
So basically, what it consists of is clients and brokers. Clients publish to a broker on the topic, and the broker distributes to whatever clients have subscribed to the topic. An example of pub-sub is Slack: a topic would be the Delta Centre, then subtopic are the specific channels inside there (could also have sub-subgroups).

How hard it is to create a topic? Not really that difficult.

# Workbook - https://docs.google.com/document/d/1412jrNT1CTWUsnEwqp1IGEA6AjrsfRwe06ogvfTVqWU/edit?tab=t.h5nxjadzs77g#heading=h.x73np36g16zd

# Do you wanna play a game? MQTT to the rescue
**Scenario** - In many countries many need help. Infrastructure is damaged. In Langtang, a volunteer rescue team is set up for first-aid administration. They knew that communication could help save lives in time-critical situations, such as getting essential supplies to where they were needed and calling in personnel (doctors and nurses) to attend to an emergency. 
**Equipment** - A mango, and one Ethernet cable with internet access (allowed to DL applications and dependencies)
**Task** - Deploy a DIY LAN for the First-Aid Station. It has to work locally and be stand-alone. Your team should set up a Local Area Network (LAN) with a Wi-Fi access point and an MQTT broker to establish a simple communication system within the station. You must accomplish this using the router.


Crocodile
Got 
Our routers IP: http://192.168.1.1/
Router 14 password: network123
made the lan gateway to be 192.168.14.1
made the wifi SSID IOT14, -PSK, and the password iotempire
then we connected to the large gateway, connected via wifi to the router luci,
downloaded dependencies: mosquitto-ssl, luci-app-mosquitto, luci-app-commands
in system - custom commands, we made running services that makes the commant netstat -tulpn
when we ran that, we saw 0.0.0.0.0:1883, LISTENING at 3930/mosquitto (PID/mosquitto)

we subscribed to topics Crocodile/mqtt/#. On one phone we published a test message separately on Crocodile/mqtt/test1 and Crocodile/mqtt/test2. Screenshot below.

# Extra optional task
kmod-usb-net-rndis

## Reflection 3
[Reflection 3](/Reflections/ref03.md)
