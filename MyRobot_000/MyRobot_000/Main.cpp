#include <Arduino.h>

#include "Motors.h"
#include "NewPing.h"
#include "ServoTask.h"
#include "SerialTask.h"

#include "HAL.h"	//TODO Удалить, когда все пины будут определены в своих файлах

//====== Глобальные переменные



//====== SONAR (SR04) ========================================
#if (!defined (SONAR_TRIGGER_PIN)) || (!defined SONAR_ECHO_PIN)
#error "SONAR Pins not defined!"
#endif
#define SONAR_MAX_DISTANCE 200	// Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
NewPing sonar(SONAR_TRIGGER_PIN, SONAR_ECHO_PIN, SONAR_MAX_DISTANCE);
#define SONAR_PING_DELAY 50		// How frequently are we going to send out a ping (in milliseconds). 50ms would be 20 times a second.
unsigned long sonar_pingTimer;		// Holds the next ping time.
volatile int sonar_distance = 0;
//uint8_t sonar_distances[sizeof(servo_h_positions)];
//uint8_t sonar_distances[4];

extern boolean isSonarEchoChecked = true;
extern boolean isSonarStartMeasure = false;

//===== BarrierDetector ======================================
unsigned long barrierdetect_Timer;
#define BARRIERDETECT_DELAY 50
#define BARRIERDETECT_SPEED_MIN MOTOR_SPEED_MIN
#define BARRIERDETECT_SPEED_MID (MOTOR_SPEED_MAX+MOTOR_SPEED_MIN)/2
#define BARRIERDETECT_DISTANCE_MIN	50
#define BARRIERDETECT_DISTANCE_MAX	100

//====== Прототипы
// Задачи
void Task_SerialHandler(void);
void Task_SonarHandler(void);
void Task_ServoHandler(void);
void Task_BarrierDetection(void);

void sonar_echoCheck(void);
void serial_send_debug(void);


//=====================================================================================================================================
void setup()
{
	//wdt_disable();

	serial_init();
	

	pinMode(LED_BUILTIN, OUTPUT);

	pinMode(PIN_RESET, OUTPUT);
	digitalWrite(PIN_RESET, 1);

	motors_correctspeed(-3);

	/*
	servo_h.attach(SERVO_H_PIN);
	servo_h.write(servo_h_positions[servo_h_position] + SERVO_H_POS_CORRECTION);
	delay(200);
	servo_h.detach();
	isServoPositioned = true;
	*/

	servo_v.attach(SERVO_V_PIN);
	servo_v.write(60);		// 100 - max?
	delay(200);
	servo_v.detach();

	sonar_pingTimer = millis();
	servo_h_rotationTimer = millis();
	barrierdetect_Timer = millis();
}

void loop()
{
	Task_SerialHandler();
	Task_SonarHandler();
	Task_ServoHandler();
	Task_BarrierDetection();
}

//==============================================================


//==============================================================
void Task_BarrierDetection(void){

	if (millis() >= barrierdetect_Timer) {
		barrierdetect_Timer += BARRIERDETECT_DELAY;

		int sonar_distance_aver;
		sonar_distance = SONAR_MAX_DISTANCE;
		// Найдем минимальное значение
		for (uint8_t i=0;i<servo_positions_cnt();i++){
			if (servo_h_distances[i] < sonar_distance) sonar_distance = servo_h_distances[i];
		}

		if (sonar_distance >= BARRIERDETECT_DISTANCE_MAX){
			motors_set_max_speed(get_motors_max_speed(), false);
		}
		else if (sonar_distance < BARRIERDETECT_DISTANCE_MIN && get_motors_max_speed() > BARRIERDETECT_SPEED_MIN) {
			motors_set_max_speed(BARRIERDETECT_SPEED_MIN, true);
		}
		else if (sonar_distance < BARRIERDETECT_DISTANCE_MAX && get_motors_max_speed() > BARRIERDETECT_SPEED_MID) {
			motors_set_max_speed(BARRIERDETECT_SPEED_MID, true);
		}
	}
}

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
		// В библиотеке доработка - возврат из check_timer() с true при таймауте с возвратом ping_result
		servo_h_distances[servo_h_position] = sonar.ping_result / US_ROUNDTRIP_CM;
		//isSonarEchoChecked = true;
		//isSonarStartMeasure = false;
		servo_doRotate = true;

		Serial.print(F("Sonar distance: "));
		Serial.println(String(sonar_distance) + F("cm"));
	}
}




<<<<<<< HEAD
=======
		//-------------------------------------
		if (isRCEnabled){
			// Bluetooth Remote Control commands
			if (Cmd=='F'){			// Forward command
				motors_go_forward();
			}
			else if (Cmd=='G'){		// Forward Left command
				motors_go_forward_and_left();
			}

			else if (Cmd=='I'){		// Forward Right command
				motors_go_forward_and_right();
			}

			else if (Cmd=='B'){		// Backward command
				motors_go_backward();
			}

			else if (Cmd=='H'){		// Backward Left command
				motors_go_backward_and_left();
			}

			else if (Cmd=='J'){		// Backward Right command
				motors_go_backward_and_right();
			}

			else if (Cmd=='L'){		// Left command
				motors_go_left();
			}

			else if (Cmd=='R'){		// Right command
				motors_go_right();
			}

			//else if (Cmd=='L'){
			//motors_correctspeed(-1);
			//}
			//else if (Cmd=='R'){
			//motors_correctspeed(1);
			//}

			else if (Cmd == 'S'){
				motors_speed_down(MOTORS_STOP_STEP,MOTORS_STOP_STEP);
			}

			//-----------------------------------------
			else if (Cmd=='W'){		// Front lights on
			}
			else if (Cmd=='w'){		// Front lights off
			}

			else if (Cmd=='U'){		// Back lights on
			}
			else if (Cmd=='u'){		// Back lights off
			}

			else if (Cmd=='V'){		// Horn sound play
			}
			else if (Cmd=='v'){		// Horn sound stop
			}


			//---- команды изменения скорости ---------
			else if ((Cmd>='0' && Cmd<='9') || Cmd == 'q'){		// Speed 0/4
				uint8_t newspeed;
				if (Cmd == 'q') newspeed = 10;
				else newspeed = (uint8_t)(Cmd - '0');
				motors_set_max_speed(newspeed*(MOTOR_SPEED_MAX-MOTOR_SPEED_MIN)/10 + MOTOR_SPEED_MIN, false);
			}
			else{
				motors_speed_down(20,20);	// если обнаружена неизвестная команда, то останавливаемся, чтобы не продолжать движение без соответствующей команды.
			}

		}	//isRCEnabled

		lastCmd = Cmd;
		SendInfos();
	}
}

//=================================================================================
void SendInfos(void){
	//Serial.println("Directions: " + String(motor_right.get_direction() + " " + String(motor_left.get_direction()));

	//Serial.print(F(" Speeds: "));		Serial.println(String(motor_right.get_speed()) + F(" ") + String(motor_left.get_speed()));
	//Serial.print(F(" RealSpeeds: "));	Serial.println(String(motor_right.get_realspeed()) + F(" ") + String(motor_left.get_realspeed()));
	//Serial.print(F(" Max Speeds: "));	Serial.println(String(motor_right.get_max_speed()) + F(" ") + String(motor_left.get_max_speed()));
}

>>>>>>> parent of d5ea779... motors_get_*_string

//=================================================================================	