## **Table Tennis Return Robot (Ultrasonic + Dual Servo System)**

This project is a simple table-tennis return robot built using an **ultrasonic distance sensor** and **two servo motors**. The system detects an approaching ping-pong ball and automatically swings a paddle to return the ball in one of three possible positions.


## **Features**

* Detects ball distance using **HC-SR04 ultrasonic sensor**
* Uses **two servo motors**:

  * **Position servo** — selects one of 3 hitting positions
  * **Kicker servo** — swings the paddle to hit the ball
* Simple and fast response for basic table-tennis ball returns
* Breadboard prototype with microcontroller + jumper wires

## **How It Works**

1. The ultrasonic sensor measures distance to the ball.
2. Based on the reading:

   * `< 6 cm` → Left hit
   * `< 8 cm` → Center hit
   * `< 10 cm` → Right hit
3. The position servo rotates into place.
4. The kicking servo swings the paddle forward and returns to rest.

This creates a basic reactive robot that sends the ball back automatically.

## **Hardware Used**

* HC-SR04 Ultrasonic Sensor
* 2x SG90 Micro Servo Motors
* ESP32 / Arduino (whichever board you're using)
* Breadboard
* Jumper wires
* 3D-printed or improvised paddle (yellow piece)


## **Circuit Overview**

* Ultrasonic **Trig** → Pin 5
* Ultrasonic **Echo** → Pin 4
* Servo 1 (kicker) → Pin 0
* Servo 2 (position) → Pin 2
* 5V power supply to servos
* Common ground shared with microcontroller

## **Code Summary**

The code:

* Continuously reads the ultrasonic distance
* Chooses one of 3 servo positions
* Executes a “kick” swing using controlled delays
* Avoids freezing by adding pulse timeouts

Main functions:

* `measureDistance()` → Gets distance
* `kickBall()` → Performs the hitting action


## **3D Model Preview**

A 3D rendered model of the complete setup is included to help visualize the build.

## **Future Improvements**

* Add ball-speed detection
* Use IR sensors for faster reaction time
* Improve paddle shape for better contact
* Add random return angles
* Add automatic play mode with timing prediction

If you'd like a **Markdown README.md** version instead (with formatting, bold titles, images, bullet styles), tell me and I'll generate it.
