/*
 * SonarTask.cpp
 *
 * Created: 12.04.2017 9:15:01
 *  Author: soan1006
 */ 

#include <Arduino.h>
#include "SonarTask.h"
#include "ServoTask.h"

NewPing sonar(SONAR_TRIGGER_PIN, SONAR_ECHO_PIN, SONAR_MAX_DISTANCE);
boolean isSonarEchoChecked = true;
boolean isSonarStartMeasure = false;
unsigned long sonar_pingTimer;		// Holds the next ping time.

void sonar_echoCheck(void);

//==============================================================
void Task_SonarHandler(void){

	if (millis() >= sonar_pingTimer && servo_isWaiting) {
		sonar_pingTimer += SONAR_PING_DELAY;
		//isSonarStartMeasure = false;
		//isSonarEchoChecked = false;
		servo_doRotate = false;
		sonar.ping_timer(sonar_echoCheck); // Send out the ping, calls "sonar_echoCheck" function every 24uS where you can check the ping status.
	}

}

void sonar_echoCheck(void) { // Timer2 interrupt calls this function every 24uS where you can check the ping status.
	if (sonar.check_timer()) {
		// � ���������� ��������� - ������� �� check_timer() � true ��� �������� � ��������� ping_result
		servo_h_distances[servo_h_position] = sonar.ping_result / US_ROUNDTRIP_CM;
		//isSonarEchoChecked = true;
		//isSonarStartMeasure = false;
		servo_doRotate = true;
	}
}