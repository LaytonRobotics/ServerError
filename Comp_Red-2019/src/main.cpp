

#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// chute                motor         1               
// intake1              motor         19              
// intake2              motor         12              
// intakeR2             motor         17              
// LM                   motor         18              
// RM                   motor         20              
// intakeL2             motor         15              
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;

competition Competition;


void pre_auton(void) {
  vexcodeInit();
}

void auto1(){

LM.spin(fwd,100,pct);
RM.spin(fwd,100,pct);


}

void auto2(){

}

void autonomous(void) {
  auto1();
}


void usercontrol(void) {
  while (1) {
    LM.spin(fwd, Controller1.Axis3.position(pct), pct);
    RM.spin(fwd, Controller1.Axis2.position(pct), pct);

    if(Controller1.ButtonR1.pressing()){
      intake1.spin(fwd, 100,pct);
      intake2.spin(fwd, 100,pct);
      intakeL2.spin(fwd,100,pct);
      intakeR2.spin(fwd,100,pct);
    }
    else if(Controller1.ButtonR2.pressing()){
      intake1.spin(reverse, 100,pct);
      intake2.spin(reverse, 100,pct);
      intakeL2.spin(reverse, 100,pct);
      intakeR2.spin(reverse, 100,pct);
    }
    else{
      intake1.spin(fwd, 0, pct);
      intake2.spin(fwd, 0, pct);
      intakeL2.spin(fwd, 0, pct);
      intakeR2.spin(fwd, 0, pct);
      intake1.setStopping(hold);
      intake2.setStopping(hold);
      intakeR2.setStopping(hold);
      intakeL2.setStopping(hold);


    }



    wait(20, msec);
  }
}
//BLUE MID(block->tower->stack main.)
int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  RM.spin(fwd,100,pct);
  LM.spin(fwd,100,pct);
  intake1.spin(reverse, 100,pct);
  intake2.spin(reverse, 100,pct);
  
 


  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);

  }
}