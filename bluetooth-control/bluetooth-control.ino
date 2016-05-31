// Este codigo utiliza un modulo Bluetooth HC-06
#include <SoftwareSerial.h>

// Este programa puede ser probado con la aplicacion para 
// Android llamada Blueterm. Antes de utilizar la aplicacion
// conectarse desde el celular (en la configuracion de bluetooth)
// al modulo bluetooth con la contrasena.
// Si los datos que tiene son los predeterminados (de fabrica)
// su nombre sera HC-06 o linvor, y la password sera 1234
// En caso de haber cambiado su nombre, y la contrasena, buscar
// el otro nombre entre los dispositivos cercanos e ingresar la
// contrasena que se establecio.
// Una vez que se hizo el "pairing" desde android hacia el modulo
// entonces abrir blueterm y conectarse al modulo para mandarle
// las letras necesarias.

char dato;
const int ledpin = 13;
// mySerial sera una conexion "serie" hacia el bluetooth
// se establece que el pin RX (receptor) y TX (transmisor)
// del puerto creado sera el pin 10 y el pin 11
// como se muestra en las lineas de abajo
const int rx = 10;
const int tx = 11;
SoftwareSerial mySerial(rx, tx); // RX, TX

// La conexion del modulo bluetooth es la siguiente:
//
//  Bluetooth -> Arduino
// *   VCC    ->   5V
// *   GND    ->  GND
// *   RX     ->   11
// *   TX     ->   10
//
// Como se puede observar, estan "al reves" el TX y RX
// del arduino y del bluetooth, esto es por que el transmisor
// de uno va al receptor del otro...
// Asi como el sonido de nuestra boca (transmisor, tx) llega
// a nuestros oidos (receptor, rx) y en el otro sentido se 
// da en el mismo orden, siempre va de un transmisor a un receptor

void setup()
{
  pinMode(ledpin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  // Serial.available() nos dice si hay algun dato en el puerto
  // serie por ser leido, y en la condicion "if" nos dice:
  // "si hay datos en el puerto serie, entonces haz lo siguiente..."

  //---------------------------------------------------------------------------
  //---------------------------------------------------------------------------
  // NOTA: En el caso de querer mandar mas datos, solo agregar mas condiciones
  //---------------------------------------------------------------------------
  //---------------------------------------------------------------------------
  if( Serial.available() )
  {
    // Leemos un dato recibido por bluetooth
    dato = Serial.read();
    // Si el dato recibido es 'a' (es decir, la letra "a") entonces
    // haremos algo, en este caso se puede poner dentro del "if" lo que
    // se quiera que haga el arduino.
    //---------------------------------------------------------------------------
    // NOTA: Utilizar unicamente una letra por condicion para mayor facilidad
    //---------------------------------------------------------------------------
    if( dato == 'a' )
    {
      // Si el dato es 'a' enviaremos por bluetooth el mensaje "Encendido LED"
      // y luego encenderemos el pin 13 (led del arduino)
      Serial.println("Encendido LED");
      digitalWrite(ledpin, HIGH);
      
    }
    if ( rxChar == 'b' )
    { 
      // Si el dato es 'b' enviaremos por bluetooth el mensaje "Apagado LED"
      // y luego apagaremos el pin 13 (led del arduino)
      digitalWrite(ledpin, LOW);
      Serial.println("Apagado LED");
    }
    if( dato == 'c' )
    {
      // Si el dato es 'c' enviaremos por bluetooth el mensaje "Parpadeando LED"
      // y luego haremos parpadear el pin 13 (led del arduino)
      Serial.println("Parpadeando LED");
      for(int i=1; i<=5; i++)
      {
        digitalWrite(ledpin, HIGH);
        delay(500);
        digitalWrite(ledpin, LOW);
        delay(500);
      }
    }
  }
}
