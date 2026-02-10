# Module 1




In this module we are introduced to the IoT course, the team behind it, and a little bit about what is IoT itself. Definitely a highlight is the teaching philosophy behind the IoT course, involving of course some techniques (open-concept classroom, ungrading), but also the overall mentality guiding these techniques - we are here to learn and teach, not for giving grades or passing exams. One of the most difficult tasks (thus far into the day) has been thinking of a challenge, that we would like to overcome - there are ideas that I can bring from my own PhD projects, that are in dire need of additional help.

## Task Inspirations

- The mentality behind teaching guides what techniques to use. Who or what is a teacher? What is the goal?
- To be filled in later in more detail (if I don't forget), but excellence in implementation, derived from repeated cycles of trial-failure-reflection.

## Task Personal Profile
1. what programming experience? what type of experience?
    1. All the experience I have is from just trying to clobber up whatever solutions I can for the projects I am working on, with no formal training. I do very heavily rely on AI to get my stuff done, but am slowly-slowly learning.
2. who knows microcontrollers? what have you done with microcontrollers? which ones have you used?
    1. I have worked with M5Sticks
3. who has worked with single board computers? which have you used (Pi, Beaglebone, Labrador)?
    1. RPi-s
    2. at one point RPi was very central infrastructure, but this has changed
4. who is a maker or part of a maker community, knows i.e. 3D printing? what do you like or would you like about it? how could it relate to this class?
    1. making, repairing.
5. who already thinks to have an idea what IoT is? what do you already know about IoT?
    1. It might be a stretch to say
    2. ulno hopes for us to give context
6. what are your expectations on this class?


## Task What is IoT
**Domains and included areas:**
- Wearables - my own homefield
- Smart cities
- Environmental monitoring

**Commonly used (data) protocols:**
- MQTT - "the most important", lightweight, operating on pub/sub, where clients sub to a topic pub'd by the server
- WebSocket - I have used this before, but might not be the most suitable for IoT, as requiring a browser is a bit heavy. Ulno here said more about HTTP as the second most common.

**Typical devices (appliance or micro controller):**
- Raspberry Pi
- M5Stick

**Challenges:**
- Improving SEASHELL - how to fit multi-spectral light sensing on a smart-ring form factor?
- Potential improvements for SWAN? Additional modalities can be one, integrating them together, but this is a bit leaning too much into data processing and analysis. I believe there has to be a more attractive, and concrete, angle for improving SWAN. More thoughts needed.

## Notes pasted from Notion
90% of IoT is connectivity - a running joke.
https://video.iotempower.us
ungrading? - not giving grades (problem with erasmus students)
short introduction of self, and the team

**who are we: into our portfolio:**
1. what programming experience? what type of experience?
    1. All the experience I have is from just trying to clobber up whatever solutions I can for the projects I am working on, with no formal training. I do very heavily rely on AI to get my stuff done, but am slowly-slowly learning.
2. who knows microcontrollers? what have you done with microcontrollers? which ones have you used?
    1. I have worked with M5Sticks
3. who has worked with single board computers? which have you used (Pi, Beaglebone, Labrador)?
    1. RPi-s
    2. at one point RPi was very central infrastructure, but this has changed
4. who is a maker or part of a maker community, knows i.e. 3D printing? what do you like or would you like about it? how could it relate to this class?
    1. making, repairing.
5. who already thinks to have an idea what IoT is? what do you already know about IoT?
    1. It might be a stretch to say
    2. ulno hopes for us to give context
6. what are your expectations on this class?

Be here! Ulno tries to make this interesting, valuable and meaningful for us to come here.
The class is not easy. Those that are really experience, maybe can finish within the class time, but probably have as much time outside the classroom, especially at the latter parts.
Once you start teaming up, make sure you have time to have the chance to meet up with your teammates outside tha class.
At the end of your class think of your own challenge, that you want to work on.

**Ungrading**
“A teacher who cares about teaching, should always avoid giving grades. Grading makes you do less work.”
A lot of this is about failing - the grades would stop that.

**Grading**
20 points total + 5 points extra (a point per week for 15 weeks, and points for reflections). Pity-lenient for giving the points.

**Format**
Looking through the syllabus:
[Syllabus IoT Intro UT 2026 - Google Docs](https://docs.google.com/document/d/1-C1gFRqfS6kaYtcHPSgm8UYLD_CgUBj1X6s2aBSM924/edit?tab=t.0)
The tasks workbook: 
[IoT Workbook 2026 - Google Docs](https://docs.google.com/document/d/1412jrNT1CTWUsnEwqp1IGEA6AjrsfRwe06ogvfTVqWU/edit?tab=t.0)
**Discord:** https://discord.com/invite/9gq8Q9p6r3 

On the next day in Moodle there is the personal reflection log. This is the first artefact to be submitted after class. It is not repetition of what was told in class, but what you engaged and what you remember of it. Look into the tasks workbook to see some good tips for this. But maybe the gist of it is, if you want to give some information to yourself to before you started working on it.
The task is also, and that is evaluated in the next class / a little before.

DISCLAIMER: this teaching material is open - feel free to even teach it yourself!

**Questions and exercise:**
1. What does IoT entail?
    1. 3 domains: wearables, smart cities, environmental monitoring
    2. 2 commonly used data protocols: 
        1. MQTT (Message Queue Telemtry Transport) - lightweight, publish/subscrive architecture: brokers make the data available, and clients read the available information after subscribing by accessing the corresponding URL. specifically, the MQTT clients subsribe to a specific topic
        ![image.png](attachment:7c3f9010-e3aa-4db1-bdb9-446b3103028c:image.png)
        
        2. WebSocket - similar to HTTP protocol, establishes a TCP connection between a browser and a server, allowing them to exchange information until connection is closed. usually very heavy
        ![image.png](attachment:0a220a92-44de-44de-9395-c966f4d77227:image.png)
       [IoT Communication Protocols—IoT Data Protocols - Technical Articles](https://www.allaboutcircuits.com/technical-articles/internet-of-things-communication-protocols-iot-data-protocols/)
    3. 2 typical devices: RPi, M5Stick
    4. what does IoT have to do with coffee - Ulno drinks 
    
    Noone mentioned AI/Big Data.
    IoT is the tech that gives the data to be used in AI. W/o IoT there would be no data (ofcourse apart from language).

    Arthur electronica centre.
    During the demo he has the dashboard there, that shows the IMU axis.    
    node-red is something that is used. the dashboard for the wand is made in node-red (we can have this
    IoT-Empower. The idea is one line of code per device. however, this can line can be really long.

**Small exercise**
Task: Think about challenge-based education (CBE). Come up with your main personal challenge, that you could potentially solve or address in this class. First 15 minutes make the portfolio, and then discuss the challenges.
Exercise of IoT architecture (slides 040)
Define these things:
Taxonomy:
1. Communication
    1. Internet - 
        1. global system of interconnected computer networks using the internet protocol suite (TCP/IP) to communicate networks and devices. It is a network of networks.
    2. [Server](https://en.wikipedia.org/wiki/Server_(computing))
        1. a server is a computer or software that provides data, resources or services to other computer clients over a network
    3. [Nodes](https://en.wikipedia.org/wiki/Node_(networking))
        1. an even more abstract and more-encompassing concept, that is harder to define than it is to understand instinctively. it encompasses data communication equipment (modem, hub, bridge, switch) and data terminal equipment). more abstractly it is a redistribution point or communication endpoint within a network. a physical network node is an electronic device attached to a network, capable of creating, receiving, and/or transmitting information over a communication channel. an interesting thing, is that some things are not considered a node - these are passive distribution points, such as [distribution frames](https://en.wikipedia.org/wiki/Distribution_frame) or [patch panels](https://en.wikipedia.org/wiki/Patch_panel)

Cloud (-computing)-
Edge (-computing)
Swarm
Things
Gateway
Nodes
Devices

Demo
## Reflection 1
[Reflection 1](/Reflections/ref01.md)
