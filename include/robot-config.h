using namespace vex;

extern brain Brain;

// VEXcode devices
extern drivetrain Drivetrain;
extern motor LeftDriveSmart;
extern motor RightDriveSmart;
extern motor_group catapultMotors;
extern motor intakeMotor;
extern controller Controller1;
extern motor rollerMotor;
extern limit limitSwitch;
extern optical opticalSensor;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );