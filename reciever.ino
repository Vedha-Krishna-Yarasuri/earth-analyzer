#include <SPI.h>
#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>
#include <Servo.h>

void sendvals();

Servo servo;

RF24 radio(7, 8); // CSN, CE
const byte addresses[][6] = {"00001", "00002"};
int servo_pin = 9;
int sensor_pin=A0;
int output_value;

void setup() {
  Serial.begin(9600);
  radio.begin();
  servo.attach (servo_pin ) ;
  radio.openWritingPipe(addresses[0]); // 00001
  radio.openReadingPipe(1, addresses[1]); // 00002
  radio.setPALevel(RF24_PA_MIN);
  radio.setChannel(87);
  radio.setDataRate(RF24_250KBPS);
  sendvals();
  delay(10);
  radio.startListening();
}
int pos;
void loop() {
  if (radio.available()) {
    radio.read(&pos, sizeof(pos));
    Serial.println(pos);
    if(pos==100)
    {
    digitalWrite(6,LOW);
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
    digitalWrite(3,LOW);
  //   Serial.println("gk0");
    }
    else if (pos==200){
    digitalWrite(6,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(3,LOW);
    delay(10);
    // Serial.println("gk1");
    }
     else if (pos==300){
    digitalWrite(6,LOW);
    digitalWrite(5,HIGH );
    digitalWrite(4,LOW);
    digitalWrite(3,HIGH);
     delay(10);
   // Serial.println("gk2");
    }
    else if (pos==400){
    digitalWrite(6,LOW);
    digitalWrite(5,HIGH );
    digitalWrite(4,HIGH);
    digitalWrite(3,LOW);
    delay(10);
   //  Serial.println("gk3");
    }
     else if (pos== 500){
    digitalWrite(6,HIGH);
    digitalWrite(5,LOW );
    digitalWrite(4,LOW);
    digitalWrite(3,HIGH);
     delay(10);
    //  Serial.println("gk5");
    }
    else if (pos== 600){
     servo.write(90);
     delay(10);    
    //  Serial.println("gk6");
    }
     else if (pos== 700){
     servo.write(180);
     delay(10);
    //  Serial.println("gk7");
    }
  }
  else
  {
    Serial.println("connection lost");  
  }
 
}

void sendvals()
{
  // this function is to send the temp values to make a dataset...
  radio.stopListening();
  int i=0;
  for(i=0;i<3000;i++){
   // write the code for lm35 to take input of temp sensor
   // radio.write(&temprature, sizeof(temperature));
   // delay(10);
  }
  
}
