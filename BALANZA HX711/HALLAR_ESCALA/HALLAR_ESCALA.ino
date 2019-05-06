//PARA HALLAR LA ESCALA DE LA BALANZA
/*
   - Conexiones del transmisor de celda de carga HX711:
     - ALIMENTACIÓN:
       - Pin VCC del HX711 --> +5V de Arduino.
       - Pin GND del HX711 --> GND de Arduino.
     - ENTRADAS:
       - Pin E+ del HX711 --> Cable Rojo de la celda de carga
       - Pin E- del HX711 --> Cable Negro de la celda de carga
       - Pin A- del HX711 --> Cable Blanco de la celda de carga
       - Pin A+ del HX711 --> Cable Verde de la celda de carga
     - SALIDAS:
       - Pin SCK del HX711 --> Pin analógico A0 de Arduino.
       - Pin DT del HX711 --> Pin Analógico A1 de Arduino.
*/
// Librería para utilizar el transmisor de celda de carga HX711
#include "HX711.h"
#define DT  A1
#define SCK  A0
// Creación del objeto para el transmisor de celda de carga HX711
HX711 balanza(DT, SCK);
//Programa principal
void setup()
{
  Serial.begin(9600);
  Serial.print("Lectura del valor del ADC:t");
  Serial.println(balanza.read());//Muestro por serial la lectura de la balanza digital
  Serial.println("No ponga ningun  objeto sobre la balanza");
  Serial.println("Destarando...");
  balanza.set_scale();//La escala por defecto es 1
  balanza.tare(20);//El peso actual es considerado Tara.
  Serial.println("Coloque un peso conocido:");
}

void loop()
{
  Serial.print("Valor de lectura: t");
  Serial.println(balanza.get_value(10), 0); // Se obtiene el valor necesario para calcular la ESCALA
  delay(100);
}
