#include <Servo.h>

/*
 * desc : global variables
 */
long  dist;
long  ldist;
long  rdist;
Servo servo_4;
long right2LeftRotationRatio;
long ultrasonicDetectDistSample;
long ultrasonicDetectDistMSPeroid;

/*
 * desc : engine response on global variables
 */
#include "Response.h"

/*
 * desc : define Input / Output
 * D2D3 : ultrasonic Send / Receive
 * D10 : right engine direction flag
 * ~5 : PWN right engine speed
 * D11 : left engine direction flag
 * ~6 : PWN left engine speed
 */
void InitIO() {
  // ultrasonic I/O
  pinMode(3 , OUTPUT);
  pinMode(2 , INPUT);

  // PWN engines
  pinMode(10, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(6, OUTPUT);
}

/*
 * desc : initialize global variables
 */
void InitGlobalVar() {
  // servo setting
  // attach in digit 4 and initial at 90 degree
  servo_4.attach(4);
  servo_4.write(90);

  // front, left and right distance
  dist = 0;
  ldist = 0;
  rdist = 0;

  // customized 
  right2LeftRotationRatio = 1;
  ultrasonicDetectDistSample = 5;
  ultrasonicDetectDistMSPeroid = 10;
}

/*
 * desc : initialization main body
 */
void setup() {
  InitIO();
  InitGlobalVar();
  delay(100);
}

/*
 * desc : main entry and it repeats to execute the code
 */
void loop()
{
    // calculate front distance
    dist = ultrasonic_distance();
    
    if (dist < 25) {
      stop();
      servo_4.write(150);
      delay(800);
      ldist = ultrasonic_distance_3_2( );
      servo_4.write(30);
      delay(800);
      rdist = ultrasonic_distance_3_2( );
      servo_4.write(90);
      delay(100);
      if (ldist < 25 && rdist < 25) {
        backward();
        delay(500);

      } else {
        if (ldist < rdist) {
          right();
          delay(420);

        } else {
          left();
          delay(420);

        }

      }

    } else {
      forward();
      delay(300);

    }

  left();

}
