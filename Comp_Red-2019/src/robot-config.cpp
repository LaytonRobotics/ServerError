#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor chute = motor(PORT1, ratio18_1, false);
motor intake1 = motor(PORT19, ratio18_1, false);
motor left = motor(PORT20, ratio18_1, false);
motor right = motor(PORT18, ratio18_1, false);
motor intake2 = motor(PORT12, ratio18_1, false);
motor intakeR2 = motor(PORT17, ratio18_1, false);

// VEXcode generated functions
// define variables used for controlling motors based on controller inputs
bool Controller1LeftShoulderControlMotorsStopped = true;
bool Controller1RightShoulderControlMotorsStopped = true;
bool Controller1XBButtonsControlMotorsStopped = true;

// define a task that will handle monitoring inputs from Controller1
int rc_auto_loop_callback_Controller1() {
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {
    // check the ButtonL1/ButtonL2 status to control intake2
    if (Controller1.ButtonL1.pressing()) {
      intake2.spin(forward);
      Controller1LeftShoulderControlMotorsStopped = false;
    } else if (Controller1.ButtonL2.pressing()) {
      intake2.spin(reverse);
      Controller1LeftShoulderControlMotorsStopped = false;
    } else if (!Controller1LeftShoulderControlMotorsStopped) {
      intake2.stop();
      // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
      Controller1LeftShoulderControlMotorsStopped = true;
    }
    // check the ButtonR1/ButtonR2 status to control intake1
    if (Controller1.ButtonR1.pressing()) {
      intake1.spin(forward);
      Controller1RightShoulderControlMotorsStopped = false;
    } else if (Controller1.ButtonR2.pressing()) {
      intake1.spin(reverse);
      Controller1RightShoulderControlMotorsStopped = false;
    } else if (!Controller1RightShoulderControlMotorsStopped) {
      intake1.stop();
      // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
      Controller1RightShoulderControlMotorsStopped = true;
    }
    // check the X/B buttons status to control chute
    if (Controller1.ButtonX.pressing()) {
      chute.spin(forward);
      Controller1XBButtonsControlMotorsStopped = false;
    } else if (Controller1.ButtonB.pressing()) {
      chute.spin(reverse);
      Controller1XBButtonsControlMotorsStopped = false;
    } else if (!Controller1XBButtonsControlMotorsStopped){
      chute.stop();
      Controller1XBButtonsControlMotorsStopped = true;
    }
    // wait before repeating the process
    wait(20, msec);
  }
  return 0;
}

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  task rc_auto_loop_task_Controller1(rc_auto_loop_callback_Controller1);
}