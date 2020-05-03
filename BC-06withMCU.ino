#include <SoftwareSerial.h> //INCLUSÃO DE BIBLIOTECA
 
const int pinoRX = 2; //PINO DIGITAL 2 (RX)
const int pinoTX = 3; //PINO DIGITAL 3 (TX)
int dadoBluetooth = 0; //VARIÁVEL QUE ARMAZENA O VALOR ENVIADO PELO BLUETOOTH
boolean loopLED = false; //VARIÁVEL BOOLEANA QUE FAZ O CONTROLE DE ATIVAÇÃO DO LOOP DO LED
//Motor A
const int EN_A = 9;
const int motorPin1 = 11;
const int motorPin2 = 10;
//Motor B
const int EN_B = 5;
const int motorPin3 = 7;
const int motorPin4 = 6; 
//speed
int motor_speed = 0;
int p1 = LOW;
int p2 = LOW;
int p3 = LOW;
int p4 = LOW;
SoftwareSerial bluetooth(pinoRX, pinoTX); //PINOS QUE EMULAM A SERIAL, ONDE
//O PINO 2 É O RX E O PINO 3 É O TX
 
void setup(){
  bluetooth.begin(9600); //INICIALIZA A SERIAL DO BLUETOOTH
  bluetooth.print("$"); //IMPRIME O CARACTERE
  bluetooth.print("$"); //IMPRIME O CARACTERE
  bluetooth.print("$"); //IMPRIME O CARACTERE
  delay(100); //INTERVALO DE 100 MILISSEGUNDOS
  pinMode(EN_A,OUTPUT);
  pinMode(motorPin1,OUTPUT);
  pinMode(motorPin2,OUTPUT);
  pinMode(EN_B,OUTPUT);
  pinMode(motorPin3,OUTPUT);
  pinMode(motorPin4,OUTPUT);
  comando(p1,p2,p3,p4,motor_speed);
}
void comando(int r1, int r2, int r3, int r4, int velocity) {
    digitalWrite(motorPin1, r1);
    digitalWrite(motorPin2, r2);
    digitalWrite(motorPin3, r3);
    digitalWrite(motorPin4, r4);
    analogWrite(EN_A, velocity);
    analogWrite(EN_B, velocity);
    delay(300);
}
void loop(){
  if(bluetooth.available()){
      dadoBluetooth = bluetooth.read();
      if(motor_speed > 220) motor_speed = 220;
      if(motor_speed < 50) motor_speed = 50;
      switch (dadoBluetooth) {
        case 'u':
          p1 = LOW; p2 = HIGH; p3 = HIGH; p4 = LOW;  
          comando(p1,p2,p3,p4,motor_speed);
        break;
        case 'r':
          p1 = HIGH; p2 = LOW; p3 = HIGH; p4 = LOW;  
          comando(p1,p2,p3,p4,motor_speed);
        break;
        case 'l':
          p1 = LOW; p2 = HIGH; p3 = LOW; p4 = HIGH;  
          comando(p1,p2,p3,p4, motor_speed);
        break;
        case 'd':
          p1 = HIGH; p2 = LOW; p3 = LOW; p4 = HIGH;  
          comando(p1,p2,p3,p4,motor_speed);          
        break;
        case '3'://#
          p1 = LOW; p2 = LOW; p3 = LOW; p4 = LOW;  
          comando(p1,p2,p3,p4,motor_speed);
          motor_speed = 0; 
        break;
        case '1': //x
          motor_speed = motor_speed + 10;
          comando(p1,p2,p3,p4,motor_speed);
        break;
        case '2': //o
          //do something when var equals 2
        break;
        case '4'://tri
          motor_speed = motor_speed - 10;
          comando(p1,p2,p3,p4,motor_speed);
        break;
        case 'M'://F1
        //do something when var equals 2
        break;
        case 'N'://f2
        //do something when var equals 2
        break;
        case 'm'://f1
        //do something when var equals 2
        break;
        case 'n'://f2
        //do something when var equals 2
        break;
        case 'o':
        //do something when var equals 2
        break;
 //       case '0':
        //do something when var equals 2
//        break;
        default:
        // if nothing else matches, do the default
        // default is optional
        break;
    } 
  }
  
} 
