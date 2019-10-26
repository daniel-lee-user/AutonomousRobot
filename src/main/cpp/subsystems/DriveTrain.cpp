/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveTrain.h"

DriveTrain::DriveTrain() : Subsystem("ExampleSubsystem"), left(new TalonSRX(2)), right(new TalonSRX(3)), navx(new AHRS(frc::I2C::Port::kMXP)), ultra(new Ultrasonic(1, 2)) {
  left->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Absolute, 0, 0);
  left->SetSelectedSensorPosition(0, 0, 0);
  left->SetInverted(false);
  right->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Absolute, 0, 0);
  right->SetSelectedSensorPosition(0, 0, 0);
  right->SetInverted(false);
  ultra->SetAutomaticMode(true);
}

void DriveTrain::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void DriveTrain::resetEncoders() {
  right->SetSelectedSensorPosition(0);
  left->SetSelectedSensorPosition(0);
}
double DriveTrain::getEncoders() {
  double rP = right->GetSelectedSensorPosition(0);
  double lP = left->GetSelectedSensorPosition(0);
  return (rP+lP)/2;
}
double DriveTrain::getGyroAngle() {
  return navx->GetYaw();
}
void DriveTrain::resetGyro() {
  navx->ZeroYaw();
}
double DriveTrain::getDistance() {
  return ultra->GetRangeInches();
}
void DriveTrain::tankDrive (double l, double r) {
  left->Set(ControlMode::PercentOutput, l);
  right->Set(ControlMode::PercentOutput, r);
}