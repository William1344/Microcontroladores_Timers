#include <Arduino.h>
#include <LiquidCrystal.h>

//define nome dos pinos
#define Int1 2
#define Int2 3
#define Int3 4
//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 7, 8, 9, 10);
// declarations
void ISR1();
void ISR2();
void Timer();

int cont = 0;
int setC = 0;
int setT = 0;
// para tratar interrupção por timers
ISR(TIMER2_OVF_vect){
  TCNT2 = 0; // reinicia #reg
  setT++;
  if(setT == 9) setT = 0;

}
void ISR1() 
{
   setC++;
}
void ISR2()
{
  setC--;
}

void setup()
{
  pinMode(Int3, INPUT);
  lcd.begin(16, 2);
  attachInterrupt(digitalPinToInterrupt(Int1), ISR1, RISING);
  attachInterrupt(digitalPinToInterrupt(Int2), ISR2, RISING);
}

void Timer(){
  TCCR2A = 0;
  TCCR2B = 7;
  TCNT2 = 0;
  TIMSK2 = 1;
  
  while(digitalRead(Int3) != HIGH){
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.println("Por Timer");
  lcd.setCursor(setT, 1);
  lcd.println("Hello AT328P");  
  delay(500);
  }
}
void loop()
{
  if(digitalRead(Int3) != HIGH)Timer();
  lcd.clear();
  lcd.setCursor(setC,0);
  lcd.println("Hello AT328P");
  delay(500);
}


