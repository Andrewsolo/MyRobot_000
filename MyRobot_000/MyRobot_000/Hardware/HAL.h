/*
 * HAL.h
 *
 * Created: 09.04.2017 18:48:36
 *  Author: ANSO
 */


#ifndef HAL_H_
#define HAL_H_


#define MOTOR_L_DIR_PIN	4	// IN1
#define MOTOR_L_SPD_PIN	5	// ENA (pwm)
#define MOTOR_R_DIR_PIN	7	// IN3
#define MOTOR_R_SPD_PIN	6	// ENB (pwm)

// ��� ��� ���������� Servo �������� ������1, �� PWM �� ������� 9 � 10 ������������ �� �������. ������� ��������� �� ��� ��������������
#define SERVO_H_PIN	9
#define SERVO_V_PIN	10

// ���������� NewPing (��� ������ � ��������) ������ ����������� ������ PWM �� 3 � 11 �������
#define SONAR_TRIGGER_PIN   A2
#define SONAR_ECHO_PIN      A1

//======= OTHERS =============================================
#define PIN_RESET 14	//A0


#endif /* HAL_H_ */