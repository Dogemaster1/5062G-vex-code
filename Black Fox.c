#pragma config(Sensor, in1,    Slift,          sensorPotentiometer)
#pragma config(Sensor, in2,    Mlift,          sensorPotentiometer)
#pragma config(Sensor, in3,    Blift,          sensorPotentiometer)
#pragma config(Sensor, dgtl1,  Ldrive,         sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  broken,         sensorNone)
#pragma config(Sensor, dgtl4,  broken,         sensorNone)
#pragma config(Sensor, dgtl5,  Rdrive,         sensorQuadEncoder)
#pragma config(Motor,  port1,           R1Dr,          tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           L1Dr,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           SliftL,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           SliftR,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           BliftR,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           BliftL,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           Mlift,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           Intake,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           L2Dr,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          R2Dr,          tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int count = 0;
//int c = 0;

//int D = 70;
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Move LCD to remote control                            */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)


// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
/*void drivetrain (int power)
{
	  motor[R1Dr] = power;
	  motor[R2Dr] = power;
	  motor[L1Dr] = power;
	  motor[L2Dr] = power;
}
void Dogego (int power, int dist)
{
	SensorValue[Ldrive] = 0;
	SensorValue[Rdrive] = 0;
	while((abs(SensorValue[Rdrive]) < dist) || (abs(SensorValue[Ldrive]) < dist))
	{
		motor[R1Dr] = power;
	  motor[R2Dr] = power;
	  motor[L1Dr] = power;
	  motor[L2Dr] = power;
	}
		motor[R1Dr] = 0;
	  motor[R2Dr] = 0;
	  motor[L1Dr] = 0;
	  motor[L2Dr] = 0;
}
void Dogeleft (int power, int dist)
{
	SensorValue[Ldrive] = 0;
	SensorValue[Rdrive] = 0;
	while((abs(SensorValue[Rdrive]) < dist) || (abs(SensorValue[Ldrive]) < dist))
	{
		motor[R1Dr] = power;
	  motor[R2Dr] = power;
	  motor[L1Dr] = -power;
	  motor[L2Dr] = -power;
	}
		motor[R1Dr] = 0;
	  motor[R2Dr] = 0;
	  motor[L1Dr] = 0;
	  motor[L2Dr] = 0;
}
void Dogeright (int power, int dist)
{
	SensorValue[Ldrive] = 0;
	SensorValue[Rdrive] = 0;
	while((abs(SensorValue[Ldrive]) < dist) || (abs(SensorValue[Ldrive]) < dist))
	{
		motor[R1Dr] = -power;
	  motor[R2Dr] = -power;
	  motor[L1Dr] = power;
	  motor[L2Dr] = power;
	}
		motor[R1Dr] = 0;
	  motor[R2Dr] = 0;
	  motor[L1Dr] = 0;
	  motor[L2Dr] = 0;
}
void resetblift (int power, int dist)
{
	SensorValue[Ldrive] = 0;
	SensorValue[Rdrive] = 0;
	while((abs(SensorValue[Blift]) > dist))
	{
	  motor[BliftL] = power;
	  motor[BliftR] = power;
	}
		motor[BliftL] = 0;
		motor[BliftR] = 0;

}
void resetslift (int power, int dist)
{
	SensorValue[Ldrive] = 0;
	SensorValue[Rdrive] = 0;
	while((abs(SensorValue[Slift]) > dist))
	{
	  motor[SliftL] = power;
	  motor[SliftR] = power;
	}
		motor[SliftL] = 0;
		motor[SliftR] = 0;

}
void fieldgrab (int power, int dist)
{
	SensorValue[Ldrive] = 0;
	SensorValue[Rdrive] = 0;
	motor[BliftL] = -power;
	motor[BliftR] = -power;
	motor[Intake] = power;
	wait1Msec(200);
	motor[SliftL] = 0;
	motor[SliftR] = 0;
	motor[Intake] = 30;
	while((abs(SensorValue[Slift]) > dist))
	{
		motor[SliftL] = power;
	  motor[SliftR] = power;
	  motor[BliftL] = power;
	  motor[BliftR] = power;
	}
		motor[Intake] = -power;
		wait1Msec(100);
		motor[Intake] = 0;
		while((abs(SensorValue[Slift]) > dist))
	{
	  motor[SliftL] = power;
	  motor[SliftR] = power;
	}
		motor[SliftL] = 0;
		motor[SliftR] = 0;
		while((abs(SensorValue[Blift]) > dist))
	{
	  motor[BliftL] = power;
	  motor[BliftR] = power;
	}
		motor[BliftL] = 0;
		motor[BliftR] = 0;



}
void Matchload (int power, int distS, int distB)
{
	SensorValue[Ldrive] = 0;
	SensorValue[Rdrive] = 0;
	motor[BliftL] = -power;
	motor[BliftR] = -power;
	motor[Intake] = power;
	wait1Msec(50);
	motor[SliftL] = 0;
	motor[SliftR] = 0;
	motor[Intake] = 30;
	while((abs(SensorValue[Slift]) > distS)||(abs(SensorValue[Blift]) < distB))
	{
		motor[SliftL] = power;
	  motor[SliftR] = power;
	  motor[BliftL] = power;
	  motor[BliftR] = power;
	}
		motor[Intake] = -power;
		wait1Msec(100);
		motor[Intake] = 0;
		while((abs(SensorValue[Slift]) > 1000))
	{
	  motor[SliftL] = power;
	  motor[SliftR] = power;
	}
		motor[SliftL] = 0;
		motor[SliftR] = 0;
		while((abs(SensorValue[Blift]) > 1000))
	{
	  motor[BliftL] = power;
	  motor[BliftR] = power;
	}
		motor[BliftL] = 0;
		motor[BliftR] = 0;



}
*/


void left () // auton1
{

}
void right () // auton2
{

}
void normal () // auton3
{

}

void pre_auton()
{
			clearLCDLine(0);
			clearLCDLine(1);
			displayLCDCenteredString(0, "Pre_auton");
			displayLCDCenteredString(1, "starting");
			wait1Msec(200);
			//Clear LCD
		clearLCDLine(0);
		clearLCDLine(1);
		bLCDBacklight = true;
		//Loop while center button is not pressed
		while(vexRT[Btn8U] != 1)
		{
			//Switch case that allows the user to choose from 4 different options
			switch(count){
			case 0:
				//Display first choice
				displayLCDCenteredString(0, "Right");
				displayLCDCenteredString(1, " 		 Enter		 ");

				//Increment or decrement "count" based on button pressed
				if(vexRT[Btn8R] == 1)
				{
					wait1Msec(200);
					count = 2;
				}
				else if(vexRT[Btn7L] == 1)
				{
					wait1Msec(200);
					count++;
				}
				break;
			case 1:
				//Display first choice
				displayLCDCenteredString(0, "Left");
				displayLCDCenteredString(1, "<		 Enter		>");

				//Increment or decrement "count" based on button press
				if(vexRT[Btn8R] == 1)
				{
					wait1Msec(200);
					count--;
				}
				else if(vexRT[Btn7L] == 1)
				{
					wait1Msec(200);
					count++;
				}
				break;
			case 2:
				//Display first choice
				displayLCDCenteredString(0, "Normal");
				displayLCDCenteredString(1, "<		 Enter		>");
				//Increment or decrement "count" based on button press
				if(vexRT[Btn8R] == 1)
				{
					wait1Msec(200);
					count--;
				}
				else if(vexRT[Btn7L] == 1)
				{
					wait1Msec(200);
					count++;
				}
				break;
			default:
				count = 0;
				break;
			}
			}
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;
	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/


task autonomous()
{
	//Clear LCD
	clearLCDLine(0);
	clearLCDLine(1);
	//Switch Case that actually runs the user choice from pre_auton.
	switch(count){
	case 0:
		//If count = 0, run the code correspoinding with choice 1
		displayLCDCenteredString(0, "Right");
		displayLCDCenteredString(1, "is running!");
		right();
		break;
	case 1:
		//If count = 1, run the code correspoinding with choice 2
		displayLCDCenteredString(0, "Left");
		displayLCDCenteredString(1, "is running!");
		left();
		break;
	case 2:
		displayLCDCenteredString(0, "Normal");
		displayLCDCenteredString(1, "is running!");
		normal();
		break;
	default:
		displayLCDCenteredString(0, "No valid choice");
		displayLCDCenteredString(1, "was made!");
		break;
	}

}


/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
  // User control code here, inside the loop
	while(true)
	{
	  motor[R1Dr] = vexRT[Ch2Xmtr2];
	  motor[R2Dr] = vexRT[Ch2Xmtr2];
	  motor[L1Dr] = vexRT[Ch3Xmtr2];
	  motor[L2Dr] = vexRT[Ch3Xmtr2];
 	if (vexRT[Btn6UXmtr2] == 1)
		 {
		   int c = 100;

		   motor[Mlift] = c; //extend mobile goal intake
	 }
	else if (vexRT[Btn6DXmtr2] == 1)
		 {
		   int c = 100;

		   motor[Mlift] = -c; //retract mobile goal intake
	 }
	else
     {
       int L = 0;

       motor[Mlift] = L; //MG intake stops
	}
  if (vexRT[Btn6U] == 1)
		 {
		   int c = 100;

		   motor[BliftR] = c; //Raise scissorlift
		   motor[BliftL] = c;
	 }
	else if (vexRT[Btn6D] == 1)
 		 {
		   int c = -100;

		   motor[BliftR] = c; //Lower scissorlift
		   motor[BliftL] = c;
	 }
	else
     {
       int L = 5;

       motor[BliftR] = L; //Scissorlift stops
       motor[BliftL] = L;
  }

  if (vexRT[Btn5D] == 1) //Rollers intake up

  	  {
		       int Y = 100;
		       motor[Intake] = Y;
		}
 	else if (vexRT[Btn5U] == 1) //Rollers eject
		     {
		       int Y = 100;
		       motor[Intake] = -Y;
		}
	else // Stop spinning
  	 {
  	   int L = 0;
  	   motor[Intake] = L;
  }

	if (vexRT[Btn7L] == 1) //4bar goes up

  	  {
		       int Y = 100;
		       motor[SliftL] = Y;
		       motor[SliftR] = Y;
		 }
	else if (vexRT[Btn8R] == 1) //4 bar goes down
		     {
		       int Y = 100;
		       motor[SliftL] = -Y;
		       motor[SliftR] = -Y;
		   }
	else // 4 bar stops
  	 {
  	   int L = 0;
  	   motor[SliftL] = L;
  	   motor[SliftR] = L;
     }

  }
}
  	// This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................
    // Remove this function call once you have "real" code.
    //UserControlCodePlaceholderForTesting();
