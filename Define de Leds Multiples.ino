#include <math.h>

//const caca = 0; 
int CantidadDeLeds = 90;
 //char MiLed[] = "LED";  
 long Resultado; 
 long resultado; 
 

  void setup()
{
  Serial.begin(9600);

  

}

  void loop() 
{
    for (int i = 0; i < CantidadDeLeds + 1; i++)
  {
     Serial.print("const");
     Serial.print("LED_"); 
     Serial.print(i); 
     Serial.print(" = ");  
     Resultado = pow(2,i);
      resultado = Resultado + 1; 
     Serial.print(resultado);
     Serial.print(";\n");
     
  } 
}
