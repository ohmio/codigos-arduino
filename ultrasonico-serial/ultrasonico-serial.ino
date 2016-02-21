//
//      OHMIO ELECTRONICS!
//
/*
  Para conectar el sensor ultrasonico HC-SR04 se hace:
    VCC   - 5V  del arduino
    GND   - GND del arduino
    TRIG  - Pin configurado en la variable trigPin (11 en el ejemplo) del arduino
    ECHO  - Pin configurado en la variable echoPin (12 en el ejemplo) del arduino
*/

// Variables para utilizar el sensor ultrasonico
int trigPin = 11;             // Pin de "Trigger" del Ultrasonico (HC-SR04)
int echoPin = 12;             // Pin de "Echo" del Ultrasonico (HC-SR04)
long duracion, distancia;     // Variables de duracion medida y distancia calculada


// Funcion de configuracion (solo se ejecuta al inicio)
void setup()
{
  Serial.begin(9600);           // Se configura el puerto serie a 9600 baudios (velocidad)
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

  // Mostramos la informacion en el puerto serie
  //
  //      NOTA: Luego de cargarle el programa al arduino hacer lo siguiente:
  //            En el editor de Arduino presionar el icono de una LUPA, en la esquina superior derecha...
  //            En esta ventana podra verse lo que se envia con la instruccion Serial.print()
  //
  Serial.print ("Distancia: ");     // Escribe un mensaje (Serial.print)
  Serial.print(distancia);          // Escribe el valor de la variable en modo texto (ASCII) (Serial.print)
  Serial.println("cm");             // Escribe un mensaje pero agrega un salto de linea al final (Serial.println)
  delay(200);                       // Un retardo para que no llene tan rapido la ventana
}

