#include <Arduino.h>

#define ledPin 13
int counter = 0;
void setup()
{
  pinMode(ledPin, OUTPUT);
  // Configuração do timer1
  TCCR1A = 0; //confira timer para operação normal
  TCCR1B = 0; //limpa registrador
  TIMSK1 |= (1 << TOIE1); // habilita a interrupção do T1
TCCR1B= (1<<CS12)|(0<<CS11)|(1 << CS10);
  TCNT1= 24955;
  counter = 0;

}

void loop(){
  delay(20);
} //loop principal. a manipulação do led é feita na ISR}

ISR(TIMER1_OVF_vect) //interrupção do TIMER1
{
      TCNT1 = 0; // Renicia TIMER 
      counter++;
      if(counter == 34){
                  digitalWrite(ledPin, digitalRead(ledPin) ^ 1);
                  counter=0;
       }
}
