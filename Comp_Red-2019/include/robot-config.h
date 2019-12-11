using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor chute;
extern motor intake1;
extern motor left;
extern motor right;
extern motor intake2;
extern motor intakeR2;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );