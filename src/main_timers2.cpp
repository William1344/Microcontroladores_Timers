#include <Arduino.h>

#define verd 9
#define amam 8
#define verm 10
#define ama 13
#define potPin 0

//para ISR
int val = 0;
int count = 0;
int toc = 0;
//para potenc.
int pot = 0, aux1 = 0;


ISR(TIMER2_OVF_vect) 
{
  TCNT2 = 0; 
  if(count == 100){
      val++;
      if(val == 1) digitalWrite(verm, HIGH);
      if(val == 2) {
        digitalWrite(verm, LOW); 
        digitalWrite(verd, HIGH);
      }  
      if(val == 3) {
        digitalWrite(verd, LOW);
        digitalWrite(amam, HIGH);
      }
      if(val == 4){
        digitalWrite(amam, LOW);
        digitalWrite(verm, HIGH);
        
      }
      count =0;
      
      if(val == 4) val = 0;
  }
  count++;
}

void setup(){
  pinMode(verd, OUTPUT);     
  pinMode(verm, OUTPUT);       
  pinMode(amam, OUTPUT);
  pinMode(ama, OUTPUT);

  
}

void loop()
{
  TCCR2A  = 0; 
  TCNT2   = 0; 
  TIMSK2  = 1;
  TCCR2B  = 7;
  delay(1000);
  pot = analogRead(potPin); 
  if(pot < 146) aux1 = 1;
  if(pot > 146 && pot < 293) aux1 = 2;
  if(pot > 293 && pot < 438) aux1 = 3;
  if(pot > 438 && pot < 585) aux1 = 4;
  if(pot > 585 && pot < 730) aux1 = 5;
  if(pot > 730 && pot < 876) aux1 = 6;
  if(pot > 876 && pot < 1023) aux1 = 7;

  TCCR2A  = 0; 
  TCNT2   = 0; 
  TIMSK2  = 1;
  TCCR2B  = aux1;
  delay(4000);


}