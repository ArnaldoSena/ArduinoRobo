#include <SoftwareSerial.h> //INCLUSÃO DE BIBLIOTECA
 
const int pinoRX = 2; //PINO DIGITAL 2 (RX)
const int pinoTX = 3; //PINO DIGITAL 3 (TX)
int dadoBluetooth = 0; //VARIÁVEL QUE ARMAZENA O VALOR ENVIADO PELO BLUETOOTH
boolean loopLED = false; //VARIÁVEL BOOLEANA QUE FAZ O CONTROLE DE ATIVAÇÃO DO LOOP DO LED
//Motor A
const int motorPin1 = 11;
const int motorPin2 = 10;
//Motor B
const int motorPin3 = 6;
const int motorPin4 = 5; 
SoftwareSerial bluetooth(pinoRX, pinoTX); //PINOS QUE EMULAM A SERIAL, ONDE
//O PINO 2 É O RX E O PINO 3 É O TX
 
void setup(){
  Serial.begin(9600); //INICIALIZA A SERIAL
  bluetooth.begin(9600); //INICIALIZA A SERIAL DO BLUETOOTH
  bluetooth.print("$"); //IMPRIME O CARACTERE
  bluetooth.print("$"); //IMPRIME O CARACTERE
  bluetooth.print("$"); //IMPRIME O CARACTERE
  delay(100); //INTERVALO DE 100 MILISSEGUNDOS
  comando(0,0,0,0);
  Serial.println("Pronto!");
}
void comando(int p1, int p2, int p3, int p4) {
    analogWrite(motorPin1, p1);
    analogWrite(motorPin2, p2);
    analogWrite(motorPin3, p3);
    analogWrite(motorPin4, p4);
    delay(300);
  }
/*
  switch (var) {
  case 1:
    //do something when var equals 1
    break;
  case 2:
    //do something when var equals 2
    break;
  default:
    // if nothing else matches, do the default
    // default is optional
    break;
}
 */
void loop(){
  if(bluetooth.available()){
       dadoBluetooth = bluetooth.read();
 
    if(dadoBluetooth == '1'){
      Serial.println("X");
    }
    if(dadoBluetooth == '2'){
      Serial.println("O");
    }
    if(dadoBluetooth == '3'){
      Serial.println("#");
      comando(0,0,0,0);
    }
    if(dadoBluetooth == '4'){
      Serial.println("^");
    }
    if(dadoBluetooth == 'u'){
      comando(0,180,180,0);//F
    }
    if(dadoBluetooth == 'd'){
      comando(180,0,0,180); //BK
    }
    if(dadoBluetooth == 'l'){
      comando(0,180,0,180);//L
    }
    if(dadoBluetooth == 'r'){
      comando(180,0,180,0);
    }
    if(dadoBluetooth == 'M'){
      Serial.println("Function one");
    }
    if(dadoBluetooth == 'N'){
      Serial.println("Function two");
    }
    if(dadoBluetooth == 'm'){
      Serial.println("Function one off");
    }
    if(dadoBluetooth == 'n'){
      Serial.println("Function two off");
    }

    if(dadoBluetooth == 'o'){
      Serial.println("solto oh");
    }
    if(dadoBluetooth == '0'){
      Serial.println("solto zero");
    }
    
  }
} 
