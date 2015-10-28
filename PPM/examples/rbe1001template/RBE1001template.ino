/* This is the RBE 1001 Template as of 12/4/12. This Template 
is designed to run the autonomous and teleop sections of the final 
competition. Write and test your autonomous and teleop code on your
own, then simply copy paste your code into the appropriate section 
and make sure the time passed to each function corresponds with the
time in seconds that each set of code should run. IE 
autonomous(20); will run for 20 seconds after the transmitter is 
turned on.The code will not start until the controller is turned on
There are print statements commented out that were used to test */

#include <PPM.h> // includes the PPM library 
// This library has an active watchdog timer that will reset the program 
// if the controller is off for more than 4 seconds

PPM ppm(2); // initializes a PPM object named ppm onto pin #2


void setup() {
Serial.begin(9600); // starts the serial port
// put your setup code here, to run once:
Serial.println("start");

}




void autonomous(volatile unsigned long time) // function definition
{
while(0==ppm.getChannel(1)){ // waits for controller to be turned on
 }
 
unsigned long startTime=millis(); // sets start time of autonomous
time=time * 1000;  // modifies milliseconds to seconds
Serial.println(ppm.getChannel(6));
while ((millis()-startTime<=time) && (ppm.getChannel(6) <= 150))// compares start time to time entered in the autonomous function and 
{					        // sets up channel 6, bottom button as an autonomous skip 
 
// Enter Autonomous User Code Here

Serial.println("Autonomous"); //prints Autonomous over serial (usb com port)
delay(50); //delay to prevent spamming the serial port 
 
}
}

void teleop(unsigned long time){ // function definition
unsigned long startTime2=millis(); // sets start time of teleop
time=time * 1000; // modifies milliseconds to seconds
while(millis()-startTime2<=time) // compares start time to time entered in the teleop function
{
 
// Enter Teleop User Code Here

Serial.println("TeleOp"); //prints Teleop over serial (usb com port)
delay(50); //delay to prevent spamming the serial port 

}
exit(0); // exits program
}


void loop() {
 
autonomous(20); //time in seconds to run autonomous code
 
teleop(180); //time in seconds that teleop code will run
 
}