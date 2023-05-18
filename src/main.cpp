#include <Arduino.h>
#include "lib/control_key.h"
// put function declarations here:

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  init_control();
}

void loop()
{
  int servoPosition;
  servoPosition = servoPins[0].servo.read();
  // Serial.println(servoPosition);
  // Serial.println(servoPosition+1);
  // Serial.println(servoPosition-1);

  if (Serial.available() > 0)
  {
    char data_control = Serial.read();
    digitalWrite(32,HIGH);
    control_keyboard(data_control);
  }
    digitalWrite(27,LOW);
    digitalWrite(26,LOW);

    digitalWrite(25,LOW);

    digitalWrite(33,LOW);

}
