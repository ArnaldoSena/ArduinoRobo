#include <SoftwareSerial.h> //INCLUSÃO DE BIBLIOTECA
 
const int pinoRX = 2; //PINO DIGITAL 2 (RX)
const int pinoTX = 3; //PINO DIGITAL 3 (TX)
const int pinoLed = 12; //PINO DIGITAL UTILIZADO PELO LED
int dadoBluetooth = 0; //VARIÁVEL QUE ARMAZENA O VALOR ENVIADO PELO BLUETOOTH
boolean loopLED = false; //VARIÁVEL BOOLEANA QUE FAZ O CONTROLE DE ATIVAÇÃO DO LOOP DO LED
 
SoftwareSerial bluetooth(pinoRX, pinoTX); //PINOS QUE EMULAM A SERIAL, ONDE
//O PINO 2 É O RX E O PINO 3 É O TX
 
void setup(){
  Serial.begin(9600); //INICIALIZA A SERIAL
  bluetooth.begin(9600); //INICIALIZA A SERIAL DO BLUETOOTH
  bluetooth.print("$"); //IMPRIME O CARACTERE
  bluetooth.print("$"); //IMPRIME O CARACTERE
  bluetooth.print("$"); //IMPRIME O CARACTERE
  delay(100); //INTERVALO DE 100 MILISSEGUNDOS
  pinMode(pinoLed, OUTPUT); //DEFINE O PINO COMO SAÍDA
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  Serial.println("Pronto!");
}
 
void loop(){
  if(bluetooth.available()){ //SE O BLUETOOTH ESTIVER HABILITADO, FAZ
       dadoBluetooth = bluetooth.read(); //VARIÁVEL RECEBE O VALOR ENVIADO PELO BLUETOOTH
 
    if(dadoBluetooth == '1'){ //SE O VALOR RECEBIDO FOR IGUAL A 1, FAZ
      Serial.println("X"); //IMPRIME O TEXTO NA SERIAL
      //digitalWrite(pinoLed, HIGH); //LIGA O LED
    }
    if(dadoBluetooth == '2'){ //SE O VALOR RECEBIDO FOR IGUAL A 0, FAZ
      Serial.println("O"); //IMPRIME O TEXTO NA SERIAL
    }
    if(dadoBluetooth == '3'){ //SE O VALOR RECEBIDO FOR IGUAL A 1, FAZ
      Serial.println("#"); //IMPRIME O TEXTO NA SERIAL
    }
    if(dadoBluetooth == '4'){ //SE O VALOR RECEBIDO FOR IGUAL A 0, FAZ
      Serial.println("^"); //IMPRIME O TEXTO NA SERIAL
    }
    if(dadoBluetooth == 'u'){ //SE O VALOR RECEBIDO FOR IGUAL A 1, FAZ
      Serial.println("Para cima"); //IMPRIME O TEXTO NA SERIAL
      //digitalWrite(pinoLed, HIGH); //LIGA O LED
    }
    if(dadoBluetooth == 'd'){ //SE O VALOR RECEBIDO FOR IGUAL A 0, FAZ
      Serial.println("Para baixo"); //IMPRIME O TEXTO NA SERIAL
    }
    if(dadoBluetooth == 'l'){ //SE O VALOR RECEBIDO FOR IGUAL A 1, FAZ
      Serial.println("Para esquerda"); //IMPRIME O TEXTO NA SERIAL
    }
    if(dadoBluetooth == 'r'){ //SE O VALOR RECEBIDO FOR IGUAL A 0, FAZ
      Serial.println("Para direita"); //IMPRIME O TEXTO NA SERIAL
    }
    if(dadoBluetooth == 'M'){ //SE O VALOR RECEBIDO FOR IGUAL A 1, FAZ
      Serial.println("Function one"); //IMPRIME O TEXTO NA SERIAL
    }
    if(dadoBluetooth == 'N'){ //SE O VALOR RECEBIDO FOR IGUAL A 0, FAZ
      Serial.println("Function two"); //IMPRIME O TEXTO NA SERIAL
    }
    if(dadoBluetooth == 'm'){ //SE O VALOR RECEBIDO FOR IGUAL A 1, FAZ
      Serial.println("Function one off"); //IMPRIME O TEXTO NA SERIAL
    }
    if(dadoBluetooth == 'n'){ //SE O VALOR RECEBIDO FOR IGUAL A 0, FAZ
      Serial.println("Function two off"); //IMPRIME O TEXTO NA SERIAL
    }

    if(dadoBluetooth == 'o'){ //SE O VALOR RECEBIDO FOR IGUAL A 1, FAZ
      Serial.println("solto oh"); //IMPRIME O TEXTO NA SERIAL
    }
    if(dadoBluetooth == '0'){ //SE O VALOR RECEBIDO FOR IGUAL A 0, FAZ
      Serial.println("solto zero"); //IMPRIME O TEXTO NA SERIAL
    }
    
  }

  //left  comando(0,180,180,0)
  //right comando(180,0,0,180)
  //back  comando(0,180,0,180)
  //forw  comando(180,0,180,0)
  //stop  comando(0,0,0,0)
  void comando(int p1, int p2, int p3, int p4) {
    analogWrite(motorPin1, p1);
    analogWrite(motorPin2, p2);
    analogWrite(motorPin3, p3);
    analogWrite(motorPin4, p4);
    delay(300);
    moveForward();
} 
  
}
