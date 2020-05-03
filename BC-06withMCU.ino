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
int motor_speed;
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
  motor_speed = 60;
  comando(LOW,LOW,LOW,LOW, motor_speed);
}
void comando(int p1, int p2, int p3, int p4, int ms) {
    digitalWrite(motorPin1, p1);
    digitalWrite(motorPin2, p2);
    digitalWrite(motorPin3, p3);
    digitalWrite(motorPin4, p4);
    analogWrite(EN_A, ms);
    analogWrite(EN_B, ms);
    delay(300);
  }
void loop(){
  if(bluetooth.available()){
      dadoBluetooth = bluetooth.read();
      if(motor_speed > 220) motor_speed = 220;
      if(motor_speed < 60) motor_speed = 60;
      switch (dadoBluetooth) {
        case 'u':
          comando(LOW,HIGH,HIGH,LOW, motor_speed);
        break;
        case 'r':
          comando(HIGH,LOW,HIGH,LOW, motor_speed);
        break;
        case 'l':
          comando(LOW,HIGH,LOW,HIGH, motor_speed);
        break;
        case 'd':
          comando(HIGH,LOW,LOW,HIGH, motor_speed);          
        break;
        case '3'://#
          comando(LOW,LOW,LOW,LOW, motor_speed);
          motor_speed = 60; 
        break;
        case '1': //x
          motor_speed = motor_speed + 20;
        break;
        case '2': //o
          //do something when var equals 2
        break;
        case '4'://tri
          motor_speed = motor_speed - 20;
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
