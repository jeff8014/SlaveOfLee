#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>

int led = 7;
int bt = 2;//txd
int br = 3;

LiquidCrystal_I2C lcd(0x20,16,2);

SoftwareSerial my(br,bt);
void setup()
{
  Serial.begin(9600);
  my.begin(9600);
  pinMode(led, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("LED Controll!!");
}

   

void loop()
{
  char data;
  if(my.available()){
    data = my.read();

    if(data == 'H'){
      digitalWrite(led, HIGH);

      lcd.setCursor(0,1);
      lcd.print("LED On!!");
    }
    if(data == 'L'){
      digitalWrite(led, LOW);

      lcd.setCursor(0,1);
      lcd.print("LED Off!!");
    }
  }
}
