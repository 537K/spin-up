#include "vex.h"

#include "kalium/subsystems.h"
#include "kalium/autonomous.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LeftDriveMotorA = motor(PORT20, ratio18_1, true);
motor LeftDriveMotorB = motor(PORT19, ratio18_1, true);
motor_group LeftDriveMotors = motor_group(LeftDriveMotorA, LeftDriveMotorB);
motor RightDriveMotorA = motor(PORT12, ratio18_1, false);
motor RightDriveMotorB = motor(PORT13, ratio18_1, false);
motor_group RightDriveMotors = motor_group(RightDriveMotorA, RightDriveMotorB);
drivetrain Drivetrain = drivetrain(LeftDriveMotors, RightDriveMotors, 319.19, 381, 215.89999999999998, mm, 1);
motor CatapultMotorA = motor(PORT14, ratio36_1, false);
motor CatapultMotorB = motor(PORT17, ratio36_1, true);
motor_group catapultMotors = motor_group(CatapultMotorA, CatapultMotorB);
kalium::subsystems::Roller intakeMotor = kalium::subsystems::Roller(PORT11, ratio18_1, false);
controller Controller = controller(primary);
kalium::subsystems::Roller rollerMotor = kalium::subsystems::Roller(PORT18, ratio18_1, false);

digital_out Expansion = digital_out(Brain.ThreeWirePort.H);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool ControllerLeftShoulderControlMotorsStopped = true;
bool ControllerRightShoulderControlMotorsStopped = true;
bool ControllerUpDownButtonsControlMotorsStopped = true;
bool DrivetrainLNeedsToBeStopped_Controller = true;
bool DrivetrainRNeedsToBeStopped_Controller = true;



// define a task that will handle monitoring inputs from Controller
int rc_auto_loop_function_Controller() {
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {
    if(RemoteControlCodeEnabled) {
      // calculate the drivetrain motor velocities from the controller joystick axies
      // left = Axis3 + Axis1
      // right = Axis3 - Axis1
      int drivetrainLeftSideSpeed = Controller.Axis3.position() + Controller.Axis1.position();
      int drivetrainRightSideSpeed = Controller.Axis3.position() - Controller.Axis1.position();
      
      // check if the value is inside of the deadband range
      if (drivetrainLeftSideSpeed < 5 && drivetrainLeftSideSpeed > -5) {
        // check if the left motor has already been stopped
        if (DrivetrainLNeedsToBeStopped_Controller) {
          // stop the left drive motor
          LeftDriveMotors.stop();
          // tell the code that the left motor has been stopped
          DrivetrainLNeedsToBeStopped_Controller = false;
        }
      } else {
        // reset the toggle so that the deadband code knows to stop the left motor nexttime the input is in the deadband range
        DrivetrainLNeedsToBeStopped_Controller = true;
      }
      // check if the value is inside of the deadband range
      if (drivetrainRightSideSpeed < 5 && drivetrainRightSideSpeed > -5) {
        // check if the right motor has already been stopped
        if (DrivetrainRNeedsToBeStopped_Controller) {
          // stop the right drive motor
          RightDriveMotors.stop();
          // tell the code that the right motor has been stopped
          DrivetrainRNeedsToBeStopped_Controller = false;
        }
      } else {
        // reset the toggle so that the deadband code knows to stop the right motor next time the input is in the deadband range
        DrivetrainRNeedsToBeStopped_Controller = true;
      }
      
      // only tell the left drive motor to spin if the values are not in the deadband range
      if (DrivetrainLNeedsToBeStopped_Controller) {
        LeftDriveMotors.setVelocity(drivetrainLeftSideSpeed, percent);
        LeftDriveMotors.spin(forward);
      }
      // only tell the right drive motor to spin if the values are not in the deadband range
      if (DrivetrainRNeedsToBeStopped_Controller) {
        RightDriveMotors.setVelocity(drivetrainRightSideSpeed, percent);
        RightDriveMotors.spin(forward);
      }

      // // check the ButtonL1/ButtonL2 status to control intakeMotor
      // if (Controller.ButtonL1.pressing()) {
      //   intakeMotor.spin(forward);
      //   ControllerLeftShoulderControlMotorsStopped = false;
      // } else if (Controller.ButtonL2.pressing()) {
      //   intakeMotor.spin(reverse);
      //   ControllerLeftShoulderControlMotorsStopped = false;
      // } else if (!ControllerLeftShoulderControlMotorsStopped) {
      //   intakeMotor.stop();
      //   // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
      //   ControllerLeftShoulderControlMotorsStopped = true;
      // }
      // check the ButtonR1/ButtonR2 status to control catapultMotors
      if (Controller.ButtonR1.pressing()) {
        catapultMotors.spin(forward);
        ControllerRightShoulderControlMotorsStopped = false;
      } else if (Controller.ButtonR2.pressing()) {
        catapultMotors.spin(reverse);
        ControllerRightShoulderControlMotorsStopped = false;
      } else if (!ControllerRightShoulderControlMotorsStopped) {
        catapultMotors.stop();
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        ControllerRightShoulderControlMotorsStopped = true;
      }
      // // check the ButtonUp/ButtonDown status to control rollerMotor
      // if (Controller.ButtonX.pressing()) {
      //   rollerMotor.spin(forward);
      //   ControllerUpDownButtonsControlMotorsStopped = false;
      // } else if (Controller.ButtonB.pressing()) {
      //   rollerMotor.spin(reverse);
      //   ControllerUpDownButtonsControlMotorsStopped = false;
      // } else if (!ControllerUpDownButtonsControlMotorsStopped) {
      //   rollerMotor.stop();
      //   // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
      //   ControllerUpDownButtonsControlMotorsStopped = true;
      // }


      // Intake roller
      if (Controller.ButtonL1.pressing() && !intakeMotor.ranLast) {
        intakeMotor.direction = forward;
        intakeMotor.mustRun = !intakeMotor.mustRun;
        intakeMotor.ranLast = true;
      } else if (!Controller.ButtonL1.pressing()) {
        intakeMotor.ranLast = false;
      }
       if (Controller.ButtonL2.pressing() && !intakeMotor.ranLast) {
      intakeMotor.direction = reverse;
      intakeMotor.mustRun = !intakeMotor.mustRun;
      intakeMotor.ranLast = true;
      } else if (!Controller.ButtonL2.pressing()) {
        intakeMotor.ranLast = false;
      }

      if (intakeMotor.mustRun) {
        intakeMotor.spin(intakeMotor.direction);
      } else if (!intakeMotor.mustRun) {
        intakeMotor.stop();
      }

      // Field Roller
      if (Controller.ButtonX.pressing() && !rollerMotor.ranLast) {
        rollerMotor.direction = forward;
        rollerMotor.mustRun = !rollerMotor.mustRun;
        rollerMotor.ranLast = true;
      } else if (!Controller.ButtonX.pressing()) {
        rollerMotor.ranLast = false;
      }
      if (Controller.ButtonB.pressing() && !rollerMotor.ranLast) {
        rollerMotor.direction = reverse;
        rollerMotor.mustRun = !intakeMotor.mustRun;
        rollerMotor.ranLast = true;
      } else if (!Controller.ButtonB.pressing()) {
        rollerMotor.ranLast = false;
      }

      if (rollerMotor.mustRun) {
        rollerMotor.spin(rollerMotor.direction);
      } else if (!rollerMotor.mustRun) {
        rollerMotor.stop();
      }

      if (Controller.ButtonRight.pressing()) {
        Expansion.set(false);
      }
      if (Controller.ButtonLeft.pressing()) {
        Expansion.set(true);
      }
    }
    // wait before repeating the process
    wait(20, msec);
  }
  return 0;
}

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  task rc_auto_loop_task_Controller(rc_auto_loop_function_Controller);
}