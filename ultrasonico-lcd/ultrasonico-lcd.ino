//
//      OHMIO ELECTRONICS!
//

// Libreria necesaria para usar la pantalla LCD
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

  Para conectar el sensor ultrasonico HC-SR04 se hace:
    VCC   - 5V  del arduino
    GND   - GND del arduino
    TRIG  - Pin configurado en la variable trigPin (11 en el ejemplo) del arduino
    ECHO  - Pin configurado en la variable echoPin (12 en el ejemplo) del arduino
*/

// Pines a conectar del Arduino hacia la LCD
//                RS, EN, D4, D5, D6, D7
LiquidCrystal lcd( 2,  3,  4,  5,  6,  7);  // Configuracion de los
                                            // pines del Arduino


// Variables para utilizar el sensor ultrasonico
int trigPin = 11;             // Pin de "Trigger" del Ultrasonico (HC-SR04)
int echoPin = 12;             // Pin de "Echo" del Ultrasonico (HC-SR04)
long duracion, distancia;     // Variables de duracion medida y distancia calculada


// Funcion de configuracion (solo se ejecuta al inicio)
void setup()
{
  lcd.begin(16, 2);             // Establece el tamano de la pantalla 16x2
  //lcd.begin(20, 4);           // Establece el tamano de la pantalla 20x4

  pinMode (trigPin, OUTPUT);    // Configuramos como salida  el pin trigger del ultrasonico
  pinMode (echoPin, INPUT);     // Configuramos como entrada el pin echo del ultrasonico
}

// Ciclo principal (se ejecuta indefinidamente)
void loop()
{
  digitalWrite(trigPin, LOW);         // Apagamos el trigger
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);        // Mandamos el pulso ultrasonico
  delayMicroseconds(10);              // Le damos una corta duracion al pulso
  digitalWrite(trigPin, LOW);         // Detenemos el pulso ultrasonico
  duracion = pulseIn (echoPin, HIGH); // Esperamos que el pin de Echo detecte el regreso de la senal enviada
  distancia = (duracion/58.2);        // Calculamos la distancia en base al tiempo que tardo en volver

  // Mostramos la informacion en la pantalla LCD
  lcd.print ("Distancia: ");
  lcd.print(distancia);
  lcd.print("cm");
  delay(200);               // Un retardo para que no se escriba "tan rapido" la pantalla y se pueda apreciar
  lcd.clear();
}

