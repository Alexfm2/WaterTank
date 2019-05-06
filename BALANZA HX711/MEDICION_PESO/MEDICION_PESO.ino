// Librería para utilizar el transmisor de celda de carga HX711
#include "HX711.h"
#define DT  A1
#define SCK  A0
// Creación del objeto para el transmisor de celda de carga HX711
HX711 balanza(DT, SCK);
// Programa principal
int ESCALA=100934/250;// ESCALA=(Valor de lectura)/(Peso real)
void setup()
{
  Serial.begin(9600);
  Serial.print("Lectura del valor del ADC:t");
  Serial.println(balanza.read()); // Comienzo de la lectura de la balanza digital
  Serial.println("No ponga ningun objeto sobre la balanza");
  Serial.println("Destarando...");
  Serial.println("...");
  balanza.set_scale(ESCALA); // Establecemos la ESCALA calculada anteriormente
  balanza.tare(20); // El peso actual es considerado Tara.
  Serial.println("BALANZA DIGITAL, LISTO PARA PESAR");
  delay(5000);  // Esperamos 5 segundos para comenzar a pesar
}

void loop()
{
  Serial.print("Peso: ");
  Serial.print(balanza.get_units(20), 0); // Se obtiene el valor real del peso en Kg del elemento
  Serial.println("g");
}
