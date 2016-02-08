//
//			OHMIO ELECTRONICS!
//

// Libreria necesaria para usar la pantalla LCD
#include <LiquidCrystal.h>
/*
	Para este ejemplo, las conexiones son las siguientes:
		Arduino		-	Pantalla LCD
			2 		- 		RS
			3		- 		EN
			4		-		D4
			5		-		D5
			6		-		D6
			7		-		D7

	Para el constraste:
		* Potenciometro (o resistencia a tierra) al V0 de la LCD

	Para el brillo:
		* Resistencia de 330 ohms de VCC al anodo de la LCD (A)
		* Puente del catodo (K) de la lcd a GND
*/

// Pines a conectar del Arduino hacia la LCD
//								RS, EN, D4, D5, D6, D7
LiquidCrystal lcd( 2,  3,  4,  5,  6,  7);	// Configuracion de los
											// pines del Arduino

// Funcion de configuracion (solo se ejecuta al inicio)
void setup()
{
	lcd.begin(16, 2);					// Establece el tamano de la pantalla 16x2
	//lcd.begin(20, 4);					// Establece el tamano de la pantalla 20x4
}

// Ciclo principal (se ejecuta indefinidamente)
void loop()
{
	lcd.print("Primera linea"); 		// Escribimos un mensaje
	lcd.setCursor(0,1);        			// Nos movemos a la segunda linea
	lcd.print("Segunda linea"); 		// Escribimos un mensaje

	delay(2000);						// Esperamos 2 segundos (2000ms)
	lcd.clear();						// Borramos la pantalla
										// Automaticamente regresa a la posicion inicial

	lcd.print("Nuevo mensaje");			// Escribimos un mensaje
	lcd.setCursor(0,1);         		// Nos movemos a la segunda linea
	lcd.print("Otro mensaje");  		// Escribimos un mensaje

	delay(2000);						// Esperamos 2 segundos (2000ms)
	lcd.clear();						// Borramos la pantalla
										// Automaticamente regresa a la posicion inicial
}


/*
	Mayor informacion en:
		https://www.arduino.cc/en/Tutorial/HelloWorld
*/
