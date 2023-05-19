#include <Arduino.h>
#include "lib/control_key.h"
// put function declarations here:
Servo servo;
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  servo.attach(27);
  // init_control();
}

void loop()
{
  for (int i= 0;i<=180;i++){
    servo.write(i);
    delay(10);
  }
  // if (Serial.available() > 0)
  // {
  //   char data_control = Serial.read();
  //   digitalWrite(32,HIGH);
  //   control_keyboard(data_control);
  // }


}
