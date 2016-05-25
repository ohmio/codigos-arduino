char dato;
void setup()
{
 Serial.begin(9600);            
 Serial1.begin(9600); 
}
void loop()
{
  if(Serial1.available())
  {
    dato = Serial1.read();
    Serial.print(dato);
  }
}
