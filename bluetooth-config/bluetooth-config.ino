// Este codigo utiliza un modulo Bluetooth HC-06
#include <SoftwareSerial.h>

const int led = 13;
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
  pinMode(led, OUTPUT);
  mySerial.begin(9600);
  // Antes de iniciar la configuracion del arduino, apagamos
  // el led en el pin 13, esto para encenderlo una ves que acabe
  digitalWrite(led, LOW);
  //--------------------------------

  // El comando:
  //             AT+NAMEwxyz
  // cambia el nombre del dispositivo a wxyz, podria ser 
  // algun otro nombre, por ejemplo EQUIPO1, EQUIPO2, etc..
  //
  // El comando:
  //             AT+PIN1234
  // cambia el nombre del dispositivo a 1234, este puede ser
  // algun otro, pero siempre de 4 digitos y solo  numeros.
  mySerial.println("AT");
  delay(2000);
  mySerial.println("AT+NAMEwxyz");
  delay(2000);
  myserial.println("AT+PIN1234");
  delay(2000);
  //--------------------------------
  // Al finalizar la configuracion el LED del arduino encendera
  // y posteriormente parpadeara.
  digitalWrite(led, HIGH);
}
void loop()
{
  // Parpadeamos indefinidamente...
  digitalWrite(led, HIGH);
  delay(200);
  digitalWrite(led, LOW);
  delay(200);
}
