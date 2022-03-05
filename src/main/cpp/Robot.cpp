// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <fmt/core.h>

#include <frc/smartdashboard/SmartDashboard.h>


void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
}

/**
 * This function is called every 20 ms, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  fmt::print("Auto selected: {}\n", m_autoSelected);

  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::AutonomousPeriodic() {
  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::TeleopInit() {

}

void Robot::TeleopPeriodic() {

  //Sets Up Left Drive
  //If statement creates a 10% deadband
  //leftDrive0.Set(ControlMode::ModeGoesHere, Controller.GetRawAxis(Button))
  if( driverController.GetRawAxis(1) > .10){
    leftDrive0.Set(ControlMode::PercentOutput, driverController.GetRawAxis(1));
    leftDrive1.Set(ControlMode::PercentOutput, driverController.GetRawAxis(1));
  }
  else{
    leftDrive0.Set(ControlMode::PercentOutput, 0);
    leftDrive1.Set(ControlMode::PercentOutput, 0);
  }

  //Sets Right Drive
  if( driverController.GetRawAxis(1) > .10){
    rightDrive0.Set(ControlMode::PercentOutput, driverController.GetRawAxis(5));
    rightDrive1.Set(ControlMode::PercentOutput, driverController.GetRawAxis(5));
  }
  else{
    rightDrive0.Set(ControlMode::PercentOutput, 0);
    rightDrive1.Set(ControlMode::PercentOutput, 0);
  }

  //Intake Motor Logic
  //IF Statement - if Trigger is not pressed and eject is, then run motor in reverse
  //ELSE - Run the motor according to the trigger state
  if (driverController.GetRawAxis(2) == 0 && driverController.GetRawButton(4) == true){
    intakeMotor.Set(-.60);
  }
  else{
    intakeMotor.Set(driverController.GetRawAxis(2));
  }


  //Intake Lift Logic
  //IF - Intake OR Eject are pressed, Bring Down Intake Lift
  //ELSE - Bring UP Intake Lift
  if( driverController.GetRawAxis(2) > .10 || driverController.GetRawButton(4) == true){
    intakeLift.Set(frc::DoubleSolenoid::Value::kForward);
  }
  else{
    intakeLift.Set(frc::DoubleSolenoid::Value::kReverse);
  }

  //Setup Conveyor Motor
  //IF - Trigger is pressed conveyor will move
  //ELSE - conveyor will not move
  if( gunnerController.GetRawAxis(3) > .10){
    conveyorMotor.Set(ControlMode::PercentOutput, gunnerController.GetRawAxis(3));
  }
  else{
    conveyorMotor.Set(ControlMode::PercentOutput, 0);
  }

  if( driverController.GetRawAxis(3) > .10){
    shooterMotor0.Set(ControlMode::PercentOutput, driverController.GetRawAxis(3));
    shooterMotor1.Set(ControlMode::PercentOutput, driverController.GetRawAxis(3));
  }
  else{
    shooterMotor0.Set(ControlMode::PercentOutput, 0);
    shooterMotor1.Set(ControlMode::PercentOutput, 0);
  }

  if( driverController.GetRawAxis(1) > .10){
    climberMotor0.Set(ControlMode::PercentOutput, driverController.GetRawAxis(1));
    climberMotor1.Set(ControlMode::PercentOutput, driverController.GetRawAxis(1));
  }
  else{
    climberMotor0.Set(ControlMode::PercentOutput, 0);
    climberMotor1.Set(ControlMode::PercentOutput, 0);
  }



}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

void Robot::SimulationInit() {}

void Robot::SimulationPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
