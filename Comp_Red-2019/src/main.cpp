

#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// chute                motor         1               
// intake1              motor         19              
// left                 motor         20              
// right                motor         18              
// intake2              motor         12              
// intakeR2             motor         17              
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;

competition Competition;


void pre_auton(void) {
  vexcodeInit();
}


void autonomous(void) {
}


void usercontrol(void) {
  while (1) {


    Controller1.


    wait(20, msec);
  }
}

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
