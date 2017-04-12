#include <Arduino.h>

#include "Motors.h"
//#include "NewPing.h"
#include "ServoTask.h"
#include "SerialTask.h"
#include "SonarTask.h"

#include "HAL.h"	//TODO Удалить, когда все пины будут определены в своих файлах

//====== Глобальные переменные
int sonar_distance = 0;



//===== BarrierDetector ======================================
unsigned long barrierdetect_Timer;
#define BARRIERDETECT_DELAY 50
#define BARRIERDETECT_SPEED_MIN MOTOR_SPEED_MIN
#define BARRIERDETECT_SPEED_MID (MOTOR_SPEED_MAX+MOTOR_SPEED_MIN)/2
#define BARRIERDETECT_DISTANCE_MIN	50
#define BARRIERDETECT_DISTANCE_MAX	100

//====== Прототипы
// Задачи
//void Task_SerialHandler(void);
//void Task_SonarHandler(void);
//void Task_ServoHandler(void);
void Task_BarrierDetection(void);


//void serial_send_debug(void);


//=====================================================================================================================================
void setup()
{
	//wdt_disable();

	pinMode(LED_BUILTIN, OUTPUT);
	pinMode(PIN_RESET, OUTPUT);
	digitalWrite(PIN_RESET, 1);

	// Инициализация оборудования
	serial_init();
	motors_correctspeed(-3);
	//servo_go_park();
	/*
	servo_h.attach(SERVO_H_PIN);
	servo_h.write(servo_h_positions[servo_h_position] + SERVO_H_POS_CORRECTION);
	delay(200);
	servo_h.detach();
	isServoPositioned = true;
	*/

	/*
	servo_v.attach(SERVO_V_PIN);
	servo_v.write(60);		// 100 - max?
	delay(200);
	servo_v.detach();
	*/

	// Инициализация таймеров
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
void Task_BarrierDetection(void){

	if (millis() >= barrierdetect_Timer) {
		barrierdetect_Timer += BARRIERDETECT_DELAY;

		int sonar_distance_aver;
		sonar_distance = SONAR_MAX_DISTANCE;
		
		// Найдем минимальное значение
		// TODO перенести расчет sonar_distance в модуль sonar или servo
		for (uint8_t i=0;i<servo_positions_cnt();i++){
			if (servo_h_distances[i] < sonar_distance) sonar_distance = servo_h_distances[i];
		}
		Serial.print(F("Sonar distance: "));
		Serial.println(String(sonar_distance) + F("cm"));

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



//=================================================================================	