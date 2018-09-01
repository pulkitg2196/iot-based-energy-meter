#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2); 
#define pulse1 7
#define pulse2 6
#define pulse3 5
#define pulse4 4
#define pulse5 3
#define pulse6 2
int i = 0;
float Rupee=0,Unit=0;
float one_pulse=0.03125;

float f;
void setup()
{
 lcd.init();
 lcd.init(); 
  Serial.begin(9600);
 pinMode(A7,OUTPUT);
pinMode(pulse1, INPUT);
pinMode(pulse2, INPUT);
pinMode(pulse3, INPUT);
pinMode(pulse4, INPUT);
pinMode(pulse5, INPUT);
pinMode(pulse6, INPUT);
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
  
  delay(500);
  lcd.clear();
   analogWrite(A7,255);
   
  if(digitalRead(pulse1))
  { //Serial.println("a");
   //i++;
   Unit+=one_pulse/10;    
   Rupee=Unit*10;          
  }
  else
  {
    
  }
  if(digitalRead(pulse2))
  {
    //Serial.println("b");
   //i++;
   Unit+=one_pulse/10;    
   Rupee=Unit*10;          
   
  }
  else
  {
  }
  if(digitalRead(pulse3))
  {//Serial.println("c");
   //i++;   
   Unit+=one_pulse/10;                  
   Rupee=Unit*10;                        
   
  }
  else{}
  if(digitalRead(pulse4))
  {//Serial.println("d");
   //i++;   
   Unit+=one_pulse*2/10;                  
   Rupee=Unit*10;                             
   }
   else{}
    if(digitalRead(pulse5))
  {//Serial.println("e");
   //i++;   
   Unit+=one_pulse*4/10;                  
   Rupee=Unit*10;                             
   }
   else{}
    if(digitalRead(pulse6))
  {//Serial.println("f");
   //i++;   
   Unit+=one_pulse*4/10;                  
   Rupee=Unit*10;                             
   }
   else{}
  lcd.setCursor(0,0);
  lcd.print("Rs: ");
  lcd.print(Rupee);
  lcd.setCursor(0,1);
  lcd.print("Unit: ");
  lcd.print(Unit);
  Serial.println(Unit);
  
  Serial.println(Rupee);
  delay(500);
  analogWrite(A7,0);
}
