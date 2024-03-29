/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/moveSquare.h"
#include "Robot.h"
#include "commands/TankDrive.h"
#include "commands/Turn.h"

moveSquare::moveSquare() {
  // Add Commands here:
  // e.g. AddSequential(new Command1());
  //      AddSequential(new Command2());
  // these will run in order.
  AddSequential(new TankDrive(5));
  AddSequential(new Turn(1024));
  AddSequential(new TankDrive(5));
  AddSequential(new Turn(1024));
  AddSequential(new TankDrive(5));
  AddSequential(new Turn(1024));
  AddSequential(new TankDrive(5));
  AddSequential(new Turn(1024));
  // To run multiple commands at the same time,
  // use AddParallel()
  // e.g. AddParallel(new Command1());
  //      AddSequential(new Command2());
  // Command1 and Command2 will run in parallel.

  // A command group will require all of the subsystems that each member
  // would require.
  // e.g. if Command1 requires chassis, and Command2 requires arm,
  // a CommandGroup containing them would require both the chassis and the
  // arm.
}
