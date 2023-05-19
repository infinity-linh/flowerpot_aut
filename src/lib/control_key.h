#include <ESP32Servo.h>
#include <vector>

const int SERVO_FORWARD_STEP_ANGLE = 1;
const int SERVO_BACKWARD_STEP_ANGLE = -1;

struct ServoPins
{
    Servo servo;
    int servoPin;
    String servoName;
    int initialPosition;
};
std::vector<ServoPins> servoPins =
    {
        {Servo(), 27, "Base", 20},
        {Servo(), 26, "Shoulder", 90},
        {Servo(), 25, "Elbow", 10},
        {Servo(), 33, "Gripper", 90},
};

void init_control()
{
    pinMode(32, OUTPUT);
    for (int i = 0; i < servoPins.size(); i++)
    {
        servoPins[i].servo.attach(servoPins[i].servoPin);
        // servoPins[i].servo.write(servoPins[i].initialPosition);
    }
}

void writeServoValues(int servoIndex, int servoMoveStepSize, bool setvalue = false)
{
    int servoPosition;
    int positioncurrent;
    if (setvalue)
    {
        servoPosition = servoMoveStepSize;
    }
    else
    {
        servoPosition = servoPins[servoIndex].initialPosition;
        // positioncurrent = servoPins[servoIndex].servo.read();
        Serial.println(servoPosition);
        // Serial.println(positioncurrent);
        servoPosition = servoPosition + servoMoveStepSize;
    }
    if (servoPosition > 180 || servoPosition < 0)
    {
        return;
    }
    // if (abs(positioncurrent - servoPosition) <= 2)
    // {

        servoPins[servoIndex].servo.write(servoPosition);
    // }
    servoPins[servoIndex].initialPosition = servoPosition;
    // }
    //   delay(10);
}

void control_keyboard(char data_control)
{
    if (data_control == 'a')
    {
        writeServoValues(0, SERVO_BACKWARD_STEP_ANGLE);
    }
    else if (data_control == 'd')
    {
        writeServoValues(0, SERVO_FORWARD_STEP_ANGLE);
    }

    if (data_control == 'w')
    {
        writeServoValues(1, SERVO_BACKWARD_STEP_ANGLE);
    }
    else if (data_control == 's')
    {
        writeServoValues(1, SERVO_FORWARD_STEP_ANGLE);
    }

    if (data_control == 'u')
    {
        writeServoValues(2, SERVO_BACKWARD_STEP_ANGLE);
    }
    else if (data_control == 'b')
    {
        writeServoValues(2, SERVO_FORWARD_STEP_ANGLE);
    }

    if (data_control == 'l')
    {
        writeServoValues(3, SERVO_BACKWARD_STEP_ANGLE);
    }
    else if (data_control == 'r')
    {
        writeServoValues(3, SERVO_FORWARD_STEP_ANGLE);
    }
    // }
}
