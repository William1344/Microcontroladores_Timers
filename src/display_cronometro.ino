#include <Arduino.h>
#include <LiquidCrystal.h>

//define nome dos pinos
#define Int1 2
#define Int2 3
#define pin4 4
//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 7, 8, 9, 10);
int cont = 0, timer = 0;
boolean test;
// para tratar interrupção por timers
ISR(TIMER2_OVF_vect){
  TCNT2 = 0; // reinicia #reg
  cont++;
  if(cont == 66) 
  {
    timer++;
    cont = 0;
  }
  if(timer == 100) timer = 0; // reinicia após 

}

void setup()
{
  TCCR2A = 0;
  TCCR2B = 7;
  TCNT2 = 0;
  TIMSK2 = 1;
  pinMode(Int1, INPUT);
  pinMode(Int2, INPUT);
  pinMode(pin4, INPUT);
  lcd.begin(16, 2);
}
void loop()
{
  test = digitalRead(Int1);
  lcd.clear();
  if(test != LOW){
    lcd.setCursor(3,0);
    lcd.println("Cronometro");
    lcd.setCursor(6,1);
    lcd.println(timer);
    
  }
  else{
    lcd.setCursor(3,0);
    lcd.println("Cronometro");
    lcd.setCursor(6,1);
    lcd.println("OFF");
    timer = 0; // zera o cronometro
  }
  delay(950);
}


