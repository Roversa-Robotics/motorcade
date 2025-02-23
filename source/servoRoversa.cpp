
#include "MicroBit.h"

extern MicroBit uBit;

const int stop_us=1500;
const int min_us=700;
const int max_us=2300;
const int frequency = 50;
const int period = 1000000 / frequency;

const int max_input = 100;                                     //can be changed to suit values from another device - 100 is 100% CCW
const int min_input = -100;                                    //can be changed to suit values from another device - -100 is 100% CW

long mapRange(long x, long in_min, long in_max, long out_min, long out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

// drive(100,100); forward
// drive(-100,-100); reverse
// drive(-100,100); left
// drive(100,-100); right

void drive(int speedL, int speedR) {                            //-100-100 each function will take care of wheel direction - 0 is neutral
    int angleSpeedL = mapRange(speedL,min_input,max_input,0,180);          //user decides direction of motor L motor is CCW for forward
    int angleSpeedR = mapRange(speedR,min_input,max_input,180,0);          //user decides direction of motor R motor is CW for forward
    uBit.io.P1.setServoPulseUs(period);                         //set left motor period for analog
    uBit.io.P2.setServoPulseUs(period);                         //set right motor period for analog
    uBit.io.P1.setServoValue(angleSpeedL, max_us, stop_us);       //left motor
    uBit.io.P2.setServoValue(angleSpeedR, max_us, stop_us);     //right motor
}

void forward(int speedL, int speedR) {                          //0-100 values with directions preset i.e. CCW, CW for each side
    int angleSpeedL = mapRange(speedL,(max_input+min_input),max_input,90,180);            //left motor CCW
    int angleSpeedR = mapRange(speedR,(max_input+min_input),max_input,90,0);              //right motor CW
    uBit.io.P1.setServoPulseUs(period);                         //set left motor period for analog
    uBit.io.P2.setServoPulseUs(period);                         //set right motor period for analog
    uBit.io.P1.setServoValue(angleSpeedL, max_us, stop_us);
    uBit.io.P2.setServoValue(angleSpeedR, max_us, stop_us);
}

void reverse(int speedL, int speedR) {
    int angleSpeedL = mapRange(speedL,(max_input+min_input),max_input,90,0);              //left motor CW
    int angleSpeedR = mapRange(speedR,(max_input+min_input),max_input,90,180);            //right motor CCW
    uBit.io.P1.setServoPulseUs(period);                         //set left motor period for analog
    uBit.io.P2.setServoPulseUs(period);                         //set right motor period for analog
    uBit.io.P1.setServoValue(angleSpeedL, max_us, stop_us);       
    uBit.io.P2.setServoValue(angleSpeedR, max_us, stop_us);     
}

void left(int speedL, int speedR) {
    int angleSpeedL = mapRange(speedL,(max_input+min_input),max_input,90,0);              //left motor CW
    int angleSpeedR = mapRange(speedR,(max_input+min_input),max_input,90,0);              //right motor CW
    uBit.io.P1.setServoPulseUs(period);                         //set left motor period for analog
    uBit.io.P2.setServoPulseUs(period);                         //set right motor period for analog
    uBit.io.P1.setServoValue(angleSpeedL, max_us, stop_us);       
    uBit.io.P2.setServoValue(angleSpeedR, max_us, stop_us); 
}

void right(int speedL, int speedR){
    int angleSpeedL = mapRange(speedL,(max_input+min_input),max_input,90,180);            //left motor CCW
    int angleSpeedR = mapRange(speedR,(max_input+min_input),max_input,90,180);            //right motor CCW
    uBit.io.P1.setServoPulseUs(period);                         //set left motor period for analog
    uBit.io.P2.setServoPulseUs(period);                         //set right motor period for analog
    uBit.io.P1.setServoValue(angleSpeedL, max_us, stop_us);       
    uBit.io.P2.setServoValue(angleSpeedR, max_us, stop_us); 
}

void stop() {
    uBit.io.P1.setDigitalValue(0);                              //left motor GPIO low - no signal to motor
    uBit.io.P2.setDigitalValue(0);                              //right motor GPIO low - no signal to motor
    uBit.io.P1.setServoPulseUs(period);                         //set left motor period for analog
    uBit.io.P2.setServoPulseUs(period);                         //set right motor period for analog
}

void neutral() {
    uBit.io.P1.setServoPulseUs(period);                         //set left motor period for analog
    uBit.io.P2.setServoPulseUs(period);                         //set right motor period for analog
    uBit.io.P1.setServoValue(0, max_us, stop_us);       
    uBit.io.P2.setServoValue(0, max_us, stop_us); 
}
