#define Led_HighBlow_RED 10
#define Led_LowBlow_RED 9
#define Led_LeftBlow_RED 8
#define Led_RightBlow_RED 7 

#define Led_attempt_ONE_RED 6
#define Led_attempt_TWO_RED 5 
#define Led_attempt_THREE_RED 4 
#define Led_attempt_FOUR_RED 3 
#define Led_attempt_FIVE_RED 2 


#define Switch_HighBlow_RED A0
#define Switch_LowBlow_RED A1
#define Switch_LeftBlow_RED A2
#define Switch_RightBlow_RED A3 


unsigned long previousMillis = 0; // el ancho de la variable, "unsigned" solo n° positivos
unsigned long currentMillis = 0; 
const long interval = 650;     
int Case;
bool Status; 
int Mistakes = 0; 
   
   
   void setup() 
{
   Serial.begin(9600);
  
  
   pinMode(Led_HighBlow_RED, OUTPUT);
   pinMode(Led_LowBlow_RED, OUTPUT);
   pinMode(Led_LeftBlow_RED, OUTPUT);
   pinMode(Led_RightBlow_RED, OUTPUT);
   pinMode(Led_attempt_ONE_RED, OUTPUT);
   pinMode(Led_attempt_TWO_RED, OUTPUT);
   pinMode(Led_attempt_THREE_RED, OUTPUT);
   pinMode(Led_attempt_FOUR_RED, OUTPUT);
   pinMode(Led_attempt_FIVE_RED, OUTPUT);
   

   pinMode(Switch_HighBlow_RED, INPUT);
   pinMode(Switch_LowBlow_RED, INPUT);
   pinMode(Switch_LeftBlow_RED, INPUT);
   pinMode(Switch_RightBlow_RED, INPUT);
}

   void loop() 
{  
    UpdateAttempts(Mistakes);
    ChangeLights(0);
    while (Mistakes < 5) 
  { 

    currentMillis = millis(); //funcion cronometro independeinte a la programación lineal. 
     if (currentMillis - previousMillis == interval)
   { 
      previousMillis = currentMillis;              // le decimos al previousMillis el tiempo anterior. 
      Case = random(1, 5);                        // el codigo eligé un Case
      ChangeLights(Case);                        // Ese Case enciende un led
      Status = SwitchesReading(Case);           // Invocamos la lectura del switch correspondiente y en consecuencía, nos da un true/false para Status 
        if (Status == true) 
      {
        Mistakes = ++Mistakes;
      }  else 
       {
         //it´s nothing. 
       }
   } 
  }
}

  void ChangeLights(int Condicion)                     
{
     switch (Condicion)
   {
    case 0: //Led_Off
      digitalWrite(Led_HighBlow_RED, LOW);
      digitalWrite(Led_LowBlow_RED, LOW);
      digitalWrite(Led_LeftBlow_RED, LOW);
      digitalWrite(Led_RightBlow_RED, LOW);
      
      //Serial.print("To Turn Off \n");
     break;
    case 1:  //Led_HighBlow_On
      digitalWrite(Led_HighBlow_RED, HIGH);
      digitalWrite(Led_LowBlow_RED, LOW);
      digitalWrite(Led_LeftBlow_RED, LOW);
      digitalWrite(Led_RightBlow_RED, LOW);

      //Serial.print("High Blow \n");
     break;
    case 2:  //Led_LowBlow_On
      digitalWrite(Led_HighBlow_RED, LOW);
      digitalWrite(Led_LowBlow_RED, HIGH);
      digitalWrite(Led_LeftBlow_RED, LOW);
      digitalWrite(Led_RightBlow_RED, LOW);

      //Serial.print("Low Blow \n");
     break;
    case 3:  //Led_LeftBlow_On
      digitalWrite(Led_HighBlow_RED, LOW);
      digitalWrite(Led_LowBlow_RED, LOW);
      digitalWrite(Led_LeftBlow_RED, HIGH);
      digitalWrite(Led_RightBlow_RED, LOW);

      //Serial.print("Left Blow \n");
     break;
    case 4:  //Led_RightBlow_On
      digitalWrite(Led_HighBlow_RED, LOW);
      digitalWrite(Led_LowBlow_RED, LOW);
      digitalWrite(Led_LeftBlow_RED, LOW);
      digitalWrite(Led_RightBlow_RED, HIGH);

      //Serial.print("Right Blow \n");
     break;
  }
}

  bool SwitchesReading(int condicion)
{
   bool variable; 
   int i = 0;
    switch (condicion)
  { 
      case 1: 
        while(i <= 5)
     {      
         variable = digitalRead(Switch_HighBlow_RED);           //Leo el switch, siendo esá mi lectura predeterminada.   
           if (variable == 0)                                
         {                                                // Siendo el 1 logico, mí lectura predeterminada, esta acción se ejecutara cuando lea un 0.  
           delay(200);                                   // Retardo antirebote para mí "Pull Down" 
           return true; 
           break;                                          
         }
           else 
         {
           delay(200);         
           i = ++i;
         }
           if (i == 5)
         {
           return false;
           i = ++i;  
         }
     }         
        break;
      case 2: 
        while(i <= 5)
     {      
         variable = digitalRead(Switch_LowBlow_RED);              
           if (variable == 0)                                
         {                                                
           delay(200);                                    
           return true; 
           break;                                          
         }
           else 
         {
           delay(200);         
           i = ++i;
         }
           if (i == 5)
         {
           return false;
           i = ++i;  
         }
     }         
      break;
      case 3: 
        while(i <= 5)
     {      
         variable = digitalRead(Switch_LeftBlow_RED);           //Leo el switch, siendo esá mi lectura predeterminada.   
           if (variable == 0)                                
         {                                                // Siendo el 1 logico, mí lectura predeterminada, esta acción se ejecutara cuando lea un 0.  
           delay(200);                                   // Retardo antirebote para mí "Pull Down" 
           return true; 
           break;                                          
         }
           else 
         {
           delay(200);         
           i = ++i;
         }
           if (i == 5)
         {
           return false;
           i = ++i;  
         }
     }         
        break;
      case 4: 
        while(i <= 5)
     {      
         variable = digitalRead(Switch_RightBlow_RED);           //Leo el switch, siendo esá mi lectura predeterminada.   
           if (variable == 0)                                
         {                                                // Siendo el 1 logico, mí lectura predeterminada, esta acción se ejecutara cuando lea un 0.  
           delay(200);                                   // Retardo antirebote para mí "Pull Down" 
           return true; 
           break;                                          
         }
           else 
         {
           delay(200);         
           i = ++i;
         }
           if (i == 5)
         {
           return false;
           i = ++i;  
         }
     }         
        break;
 }

}

  void UpdateAttempts(int Mistakes) 
{
    switch (Mistakes)
  {
     case 0:
       digitalWrite(Led_attempt_ONE_RED, HIGH); 
       digitalWrite(Led_attempt_TWO_RED, HIGH);
       digitalWrite(Led_attempt_THREE_RED, HIGH);
       digitalWrite(Led_attempt_FOUR_RED, HIGH);
       digitalWrite(Led_attempt_FIVE_RED, HIGH);      
      break;
     case 1:
       digitalWrite(Led_attempt_ONE_RED, LOW); 
       digitalWrite(Led_attempt_TWO_RED, HIGH);
       digitalWrite(Led_attempt_THREE_RED, HIGH);
       digitalWrite(Led_attempt_FOUR_RED, HIGH);
       digitalWrite(Led_attempt_FIVE_RED, HIGH);
      break;
     case 2: 
       digitalWrite(Led_attempt_ONE_RED, LOW); 
       digitalWrite(Led_attempt_TWO_RED, LOW);
       digitalWrite(Led_attempt_THREE_RED, HIGH);
       digitalWrite(Led_attempt_FOUR_RED, HIGH);
       digitalWrite(Led_attempt_FIVE_RED, HIGH);
      break;
     case 3: 
       digitalWrite(Led_attempt_ONE_RED, LOW); 
       digitalWrite(Led_attempt_TWO_RED, LOW);
       digitalWrite(Led_attempt_THREE_RED, LOW);
       digitalWrite(Led_attempt_FOUR_RED, HIGH);
       digitalWrite(Led_attempt_FIVE_RED, HIGH);
      break;
     case 4: 
       digitalWrite(Led_attempt_ONE_RED, LOW); 
       digitalWrite(Led_attempt_TWO_RED, LOW);
       digitalWrite(Led_attempt_THREE_RED, LOW);
       digitalWrite(Led_attempt_FOUR_RED, LOW);
       digitalWrite(Led_attempt_FIVE_RED, HIGH);
      break;
     case 5: 
       digitalWrite(Led_attempt_ONE_RED, LOW); 
       digitalWrite(Led_attempt_TWO_RED, LOW);
       digitalWrite(Led_attempt_THREE_RED, LOW);
       digitalWrite(Led_attempt_FOUR_RED, LOW);
       digitalWrite(Led_attempt_FIVE_RED, LOW);
      break;
  }
}
  
