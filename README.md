# Embedded_System_Lab9

Basic 1:

Control a RGB LED using a photoresistor, an ultrasonic sensor, and a microphone.

Measure the light using the photoresistor at 1 Hz to set the red input to the RGB LED accordingly.

Measure the sound intensity using the microphone at 2.5 Hz to set the green input to the RGB LED.

Measure the distance of an object using the ultrasonic sensor at 0.4 Hz to set the blue input to the RGB LED.

1) Implement the operations using the Arduino loop()

2) Implement the operations with FreeRTOS by creating three tasks to handle the three sensors

Basic 2:

Design a door security system using a stepper motor, an ultrasonic sensor and a photoresistor. 

While the door is open, use the photoresistor every 0.5 second to detect whether an object is coming close. 

If so, then control the stepper motor to close the door.

How long does it take to close the door?

While the door is closed, use an ultrasonic sensor every 0.3 second to detect whether the object is at least 5 cm away.

If so, control the stepper motor to open the door. 

When the open is opening, will you miss the deadline of checking the ultrasonic sensor every 0.3 second?

Implement all functionalities using freeRTOS tasks.
