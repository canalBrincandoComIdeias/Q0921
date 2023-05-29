/*
  Q0922-Teste para módulo relê LC Tecnology ESP8266 Relay (http://www.lctech.cc)

  IMPORTANTE: 1- Ao ligar o módulo, manter o botão S1 apertado. Com isso, o módulo irá ligar com o LED vermelho aceso e o verde piscando.
              2- Caso o módulo esteja com o LED azul aceso, desligar e repetir o passo anterior.
              Não apertar o botão S1 enquanto o módulo estiver ligado. Caso ele seja apertado, desligar o módulo e executar o passo 1.

  Comandos do Módulo (em Hexadecimal):
              Close 1st relay: A0 01 00 A1
              Open  1st relay: A0 01 01 A2 
              Close 2nd relay: A0 02 00 A2
              Open  2nd relay: A0 02 01 A3
              Close 3rd relay: A0 03 00 A3
              Open  3rd relay: A0 03 01 A4 
              Close 4th relay: A0 04 00 A4
              Open  4th relay: A0 04 01 A5              
*/

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   
  set_rele(1, HIGH); 
  delay(100);         
  set_rele(2, LOW); 
  delay(100);              

  digitalWrite(LED_BUILTIN, LOW);    
  set_rele(1, LOW); 
  delay(500);  
  set_rele(2, HIGH); 
  delay(500);                     
}

//**************************************************
// Função para envio do comando via porta serial.
//
// byte rele   - define o módulo relé para executar o comando (1 ao 4).
// bool estado - estado para ligar (HIGH) ou desligar (LOW) o relé.
//**************************************************
void set_rele(byte rele, bool estado) {

  Serial.write(0xA0);

  if (estado) {
    //open
    switch (rele) {
      case 1: {
          Serial.write(0x01);
          Serial.write(0x01);
          Serial.write(0xA2);
          break;
        }
      case 2: {
          Serial.write(0x02);
          Serial.write(0x01);
          Serial.write(0xA3);
          break;
        }
      case 3: {
          Serial.write(0x03);
          Serial.write(0x01);
          Serial.write(0xA4);
          break;
        }
      case 4: {
          Serial.write(0x04);
          Serial.write(0x01);
          Serial.write(0xA5);
          break;
        }
    }

  } else {
    //close
    switch (rele) {
      case 1: {
          Serial.write(0x01);
          Serial.write(0x00);
          Serial.write(0xA1);
          break;
        }
      case 2: {
          Serial.write(0x02);
          Serial.write(0x00);
          Serial.write(0xA2);
          break;
        }  
      case 3: {
          Serial.write(0x03);
          Serial.write(0x00);
          Serial.write(0xA3);
          break;
        }  
      case 4: {
          Serial.write(0x04);
          Serial.write(0x00);
          Serial.write(0xA4);
          break;
        }  
    }
    Serial.write('\n');
  }
}
