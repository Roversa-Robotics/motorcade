Simple library for basic controls of Roversa using [codal-microbit-v2](https://github.com/lancaster-university/microbit-v2-samples)

add:
`#include "servoRoversa.h"`
to main.cpp to use the basic driving functions of Roversa.

For example in main.cpp:
```
#include "MicroBit.h"
#include "servoRoversa.h"

MicroBit uBit;

main(){
    uBit.init();
    while(1){
        drive(100,100);      //drive forward at 100% speed
        uBit.sleep(1000);
        drive(-100,-100);    //drive backward at 100% speed
        uBit.sleep(1000);
        forward(100,100);    //forward at 100% speed
        uBit.sleep(1000);
        reverse(100,100);    //reverse at 100% speed
        uBit.sleep(1000);
        left(100,100);       //left turn at 100% speed
        uBit.sleep(1000);
        right(100,100);      //right turn at 100% speed
        uBit.sleep(1000);
        drive(50,50);        //drive forward at 50% speed
        uBit.sleep(1000);
        reverse(50,50);      drive backwards at 50% speed
        uBit.sleep(1000);
    }
}
```
drive function takes on two integers from -100 to 100 as a percent to control direction and speed in each motor. The first parameter is the left motor speed and the second is th right motor speed. This allows you to move a motor forward and backward ranging all speeds. 100% moves each motor in the forward direction or left motor CCW and right motor CW. -100% moves each motor in the backwards direction or left motor CW and right motor CCW.
`drive(int,int);`
