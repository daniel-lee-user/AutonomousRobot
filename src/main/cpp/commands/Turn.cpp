/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Turn.h"
#include "Robot.h"
Turn::Turn(double angle) {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::drive);
  setAngle = angle;
}

// Called just before this Command runs the first time
void Turn::Initialize() {
  Robot::drive->resetGyro();
}

// Called repeatedly when this Command is scheduled to run
void Turn::Execute() {
  if(setAngle<0) {
    Robot::drive->tankDrive(0.5,-0.5);
  } else {
    Robot::drive->tankDrive(-0.5,0.5);
  }
}

// Make this return true when this Command no longer needs to run execute()
bool Turn::IsFinished() { 
    if(setAngle<0) {
      return Robot::drive->getGyroAngle() < setAngle;
    } else {
      return Robot::drive->getGyroAngle() > setAngle;
    }
  }

// Called once after isFinished returns true
void Turn::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Turn::Interrupted() {}
