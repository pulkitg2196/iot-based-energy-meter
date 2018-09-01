#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2); 
#define pulse1 7
#define pulse2 6
#define pulse3 5
#define pulse4 4
#define pulse5 3
int i = 0;
float Rupee=0,Unit=0;
float one_pulse=0.03125;

float f;
void setup()
{
 lcd.init();
 lcd.init(); 
  Serial.begin(9600);
pinMode(pulse1, INPUT);
pinMode(pulse2, INPUT);
pinMode(pulse3, INPUT);
pinMode(pulse4, INPUT);
pinMode(pulse5, INPUT);
lcd.backlight();
lcd.setCursor(0,0);
lcd.print("SmartElectricity");
lcd.setCursor(0,1);
lcd.print("     Meter");
delay(2000);
lcd.clear();

}

void loop()
{
  lcd.clear();
  
  if(digitalRead(pulse1) && digitalRead(pulse2) && digitalRead(pulse3) && digitalRead(pulse4)&&digitalRead(pulse5))
  {
   i+=5;
   Unit=one_pulse*i/10;    
   Rupee=Unit*10;          
  
  }
  else if((digitalRead(pulse1) && digitalRead(pulse2) && digitalRead(pulse3) && digitalRead(pulse4))||(digitalRead(pulse1) && digitalRead(pulse2) && digitalRead(pulse3) && digitalRead(pulse5))||(digitalRead(pulse1) && digitalRead(pulse2) && digitalRead(pulse4) && digitalRead(pulse5) ))
  {
   i+=3;
   Unit=one_pulse*i/10;    
   Rupee=Unit*10;          
   
  }
  else if((digitalRead(pulse1) && digitalRead(pulse2) && digitalRead(pulse3))||(digitalRead(pulse1) && digitalRead(pulse2) && digitalRead(pulse4))||(digitalRead(pulse1) && digitalRead(pulse2) && digitalRead(pulse5))||(digitalRead(pulse2) && digitalRead(pulse3) && digitalRead(pulse4))||(digitalRead(pulse2) && digitalRead(pulse3) && digitalRead(pulse5))||(digitalRead(pulse3) && digitalRead(pulse4) && digitalRead(pulse5)))
  {
   i+=2;   
   Unit=one_pulse*i/10;                  
   Rupee=Unit*10;                        
   
  }
  else if((digitalRead(pulse1) && digitalRead(pulse2))||(digitalRead(pulse1) && digitalRead(pulse3))||(digitalRead(pulse1) && digitalRead(pulse4))||(digitalRead(pulse2) && digitalRead(pulse3))||(digitalRead(pulse2) && digitalRead(pulse4))||(digitalRead(pulse3) && digitalRead(pulse4)))
  {
   i+=2;   
   Unit=one_pulse*i/10;                  
   Rupee=Unit*10;                        
   
  }
  else if(digitalRead(pulse1)||digitalRead(pulse2)||digitalRead(pulse3)||digitalRead(pulse4)||digitalRead(pulse5))
  {
   i+=1;   
   Unit=one_pulse*i/10;                  
   Rupee=Unit*10;                             
   }
   else
   {}
  lcd.setCursor(0,0);
  lcd.print("Rs: ");
  lcd.print(Rupee);
  lcd.setCursor(0,1);
  lcd.print("Unit: ");
  lcd.print(Unit);
  Serial.println(Unit);
  //Serial.println("\n");
  Serial.println(Rupee);
  delay(1000);
}
