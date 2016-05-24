#include <DHT11.h>
#include <LiquidCrystal.h>
/*
  Para este ejemplo, las conexiones son las siguientes:
    Arduino   - Pantalla LCD
      2     -     RS
      3   -     EN
      4   -   D4
      5   -   D5
      6   -   D6
      7   -   D7

  Para el constraste:
    * Potenciometro (o resistencia a tierra) al V0 de la LCD

  Para el brillo:
    * Resistencia de 330 ohms de VCC al anodo de la LCD (A)
    * Puente del catodo (K) de la lcd a GND
*/

// Pines a conectar del Arduino hacia la LCD
//                RS, EN, D4, D5, D6, D7
LiquidCrystal lcd(3 , 4,  5,  6,  7,  8);

// Variables DHT11
// El DHT11 se conecta al pin 2 del arduino
int pin = 2;
DHT11 dht11(pin); 
int err;
float temp, humi;

void setup() 
{
  lcd.begin(16, 2);         // Establece el tamano de la pantalla 16x2
  //lcd.begin(20, 4);         // Establece el tamano de la pantalla 20x4
}
//-------------------------------------------------

void loop()
{
  leerDHT11();
  mostrarInfoLCD();
  delay(100);
  lcd.clear();
//------------------------------------------------------
}
void leerDHT11()
{
  if((err=dht11.read(humi, temp))==0)
  {
    Serial.print("temperature:");
    Serial.print(temp);
    Serial.print(" humidity:");
    Serial.print(humi);
    Serial.println();
  }
  else
  {
    Serial.println();
    Serial.print("Error No :");
    Serial.print(err);
    Serial.println();    
  }
  delay(DHT11_RETRY_DELAY); //delay for reread
}
void mostrarInfoLCD( void )
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.setCursor(0,1);
  lcd.print("Hume: ");
  lcd.print(humi);
}
