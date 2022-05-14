#include <HCSR04.h>
#include <Arduino.h>

#define pino_trigger 4
#define pino_echo 3
int ledPin11 = 11, ledPin10 = 10, ledPin9 = 9, ledPin6 = 6, ledPin5 = 5;

long dist;
float sinVal;
int ledVal;
void chama(int vv);
HCSR04 hc4(pino_trigger, pino_echo);
void setup() 
{
  Serial.begin(9600);
  pinMode(ledPin11, OUTPUT);
  pinMode(ledPin10, OUTPUT);
  pinMode(ledPin9, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin5, OUTPUT);
}
 
void loop() 
{
   
   dist = hc4.getDistance();// ultrassom.Ranging(CM) retorna a distancia em
   Serial.print(dist); //imprime o valor da variável distancia
   Serial.println("cm");
   if(dist < 30) chama(ledPin11);
   if(dist < 25) chama(ledPin10);
   if(dist < 20) chama(ledPin9);
   if(dist < 15) chama(ledPin6);
   if(dist < 10) chama(ledPin5);
   delay(100);
  
}

void chama(int vv){
  for (int x=100; x<180; x++) { // converte graus para radianos e então obtém o valor do seno
    sinVal = (sin(x*(3.1412/180)));
    ledVal = int(sinVal*255);
    analogWrite(vv, ledVal);
    if(x==179) analogWrite(vv, LOW);
  }
}