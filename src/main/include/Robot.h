// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>

#include <frc/Joystick.h>

#include <frc/DoubleSolenoid.h>

//Includes CTRE support, used for VictorSPX Motor Controllers
#include <ctre/Phoenix.h>

//Includes Rev Library Support, used for Spark Max Motor Controllers
#include "rev/CANSparkMax.h"

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;
  void SimulationInit() override;
  void SimulationPeriodic() override;

 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;

    //Setup joysticks 
  frc::Joystick driverController{0};
  frc::Joystick gunnerController{1};


  //Left Drive CAN ID's
  VictorSPX leftDrive0 = {0};
  VictorSPX leftDrive1 = {1};

  //Right Drive CAN ID's
  VictorSPX rightDrive0 = {2};
  VictorSPX rightDrive1 = {3};


  //intake motor CAN ID's
  rev::CANSparkMax intakeMotor{4, rev::CANSparkMax::MotorType::kBrushless};

  //Conveyor Motor CAN ID
  VictorSPX conveyorMotor = {5};

  //Shooter Motor CAN ID's
  VictorSPX shooterMotor0 = {6};
  VictorSPX shooterMotor1 = {7};

  //Climber Motor CAN ID's
  VictorSPX climberMotor0 = {8};
  VictorSPX climberMotor1 = {9};


  //Set Up Intake Solenoid
  frc::DoubleSolenoid intakeLift{frc::PneumaticsModuleType::CTREPCM, 0, 1};
};
