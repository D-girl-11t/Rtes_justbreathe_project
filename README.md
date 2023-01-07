**Embedded Challenge Fall 2022**

Group

[Anupam Tiwari ](mailto:ast9885@nyu.edu) ast9885, 
[Dhana Laxmi Sirigireddy ](mailto:ds6992@nyu.edu)ds6992,
[Lakshitha Vivekananda](mailto:lv2218@nyu.edu)lv2218, 
[Divya Sai Tirumalasetty](mailto:dt2482@nyu.edu)dt2482

**Objective :**

Embedded system design focuses on gathering useful data, processing that data, and providing a useful representation of information. Real-time embedded signal information is often used to provide extremely important medical information that may be lifesaving. This information is usually gathered using wearable sensors that communicate to an app providing a patient or the caregiver insight to the patient’s health.

In the case of Sudden Infant Death Syndrome (SIDS), a baby less than 1 year old experiences a sudden and unexpected death during sleep. There are no indications of illness, no prior symptoms, and occurs in otherwise healthy infants. Unfortunately, the direct cause of SIDS is unknown.

The objective of this semester’s embedded challenge is to build an embedded system that can determine if a person has stopped breathing for more than 10 seconds, after which, a trigger is activated as a notification or an “alert” that something is wrong.

**Things used to perform the experiment :**

STM32F429 microcontroller ,

Thin flim Pressure Sensor,

Jumper cables,

Belt,

PlatformIO to execute the code that interfaces STM microcontroller and Sensor

**Experiment Procedure :**

1. The connections - Connect the STM32 microcontroller with the pressure sensor using jumper cables. The pressure sensor works in an open circuit with infinite resistance. Connect the STM32 board with your laptop using the mini cable .

GND of STM32  => one of the pin of the sensor

VCC of STM32  => other pin of the sensor

2. The Code - We wrote Cpp code that allows the STM32 microcontroller to receive data, in this case, it is the  voltage difference caused by pressure variations acting on the sensor.
3. The thin flim pressure sensor is fitted around the diaphragm of the body of the observation. When the infant breathes in and out, the resistance across the sensor

varies, causing a pressure difference. This pressure difference is transferred to electrical impulses which generates corresponding voltage difference.

4. The diaphragm expands while inhaling and contracts while exhaling. A threshold of 2.1 V is kept to avoid the needless pressure difference which was found during inhaling and exhaling. While the infant exhales, the voltage difference is less than 2.1 V, but it surpasses 2.1 V when inhaling.
4. Alert - If the infant is breathing normally , (inhaling and exhaling regularly), then the screen on the STM32 board indicates "Baby is safe".

Upon 10 seconds of no inhaling , the LCD on the microcontroller shows "Baby in danger".

**Results and Conclusion :**

- The experiment is performed on one of our group members. We tried to hold the breath for more than 10 seconds to check the “Baby in danger” case.
- Baby’s breathing rate is faster than normal human average breathing rate. So , the threshold can be modified according to the body of the observation.

**Scope of Improvement :**

- SIDS has no symptoms or warning signs. Babies who die of SIDS seem healthy before being put to bed. They show no signs of struggle and are often found in the same position as when they were placed in the bed.
- We, in this experiment, used a pressure sensor placed across the diaphragm of the body. But, this alone data is not enough to decide whether the baby died of SIDS. Necessarily , oxygen levels , heart beat levels , Eye movement (close and open) , breathing rate , humidity of breath and many more has to be monitored and yet SIDS is unpredictable.
