#define Led_HighBlow 13
#define Led_LowBlow 12
#define Led_LeftBlow 11
#define Led_RightBlow 10
#define Led_Green 9
#define Led_Red 8

#define Switch_HighBlow 7
#define Switch_LowBlow 6
#define Switch_LeftBlow 5
#define Switch_RightBlow 4 
  
unsigned long previousMillis = 0; // el ancho de la variable, "unsigned" solo n° positivos
unsigned long currentMillis = 0; 
const long interval = 1000;     

int Case; 
bool Status;

  void setup() 
{
  Serial.begin(9600);
  
  
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);

  pinMode(7, INPUT);
  pinMode(6, INPUT);
  pinMode(5, INPUT);
  pinMode(4, INPUT);

}

  void loop() 
{
  currentMillis = millis(); 
    if (currentMillis - previousMillis >= interval)
  { Serial.print("Entre en el IF \n");
  
    previousMillis = currentMillis; 
    Serial.print("previousMillis: "); 
    Serial.println(previousMillis);

    Case = random(0, 4);                        // el codigo eligé un Case
    ChangeLights(Case);                        // Ese Case enciende un led
    Status = SwitchesReading(Case);           // Invocamos la lectura del switch correspondiente y en consecuencía, nos da un true/false para Status 
    
    Serial.print("\n Status: ");
    Serial.println(Status);

     if (Status == 1) 
   { Serial.print("\n On Led_Green"); 

     digitalWrite(Led_Green, HIGH); 
   }  
      else
    { Serial.print("\n On Led_Red" );
      
      digitalWrite(Led_Red, HIGH);
    }

    ChangeLights(4);                            // Le pedimos al led encendido que se apague. 
    Serial.print(" \n To turn Off");
  }
}

 bool SwitchesReading(int condicion)
{
  bool variable; 
  int i = 0;
    switch (condicion)
  { 
    case 0:
      
      Serial.print("Entro en el Case 0");
      
       while(i <= 5)
     {    
         Serial.print("Entro en el While");
         
      variable = digitalRead(Switch_HighBlow);       //Leo el switch, siendo esá mi lectura predeterminada.
            
         Serial.println(variable);
         
        if (variable == 1)   
      {                                     // Siendo el 1 logico, mí lectura predeterminada, esta acción se ejecutara cuando lea un 0.  
        delay(200);                        // Retardo antirebote para mí "Pull Down"
        return true; 
        break;                                          
      }
        else 
      {
        delay(200);         
        i = ++i;
        //Status = false;
      }

        if (i == 5)
      {
        return false; 
      }

     }         
    break;
    case 1:
      
      Serial.print("Entro en el Case 1");
      
       while(i <= 5)
     {      
         Serial.print("Entro en el While");
         
      variable = digitalRead(Switch_LowBlow);              
        if (variable == 1)     
      {                                       
        delay(200);                        
        return  true;
        break;                                          
      } 
        else 
      {
        delay(200);         
        i = ++i;
        //Status = false;
      }

        if (i == 5)
      {
        return false; 
      }
                  
     }           
    break; 
    case 2:
      
      Serial.print("Entro en el Case 2");
      
       while(i <= 5)
     {      
         Serial.print("Entro en el While");
         
      variable = digitalRead(Switch_LeftBlow);              
        if (variable == 1)   
      {                                       
        delay(200);                       
        return true;              
        break;                                          
      }
        else 
      {
        delay(200);         
        i = ++i;
        //Status = false;
      }

        if (i == 5)
      {
        return false; 
      }

     }
    break;
    case 3:
      
      Serial.print("Entro en el Case 3");
      
       while(i <= 5)
     {      
         Serial.print("Entro en el While");
         
      variable = digitalRead(Switch_RightBlow);              
        if (variable == 1)     
      {                                       
        delay(200);                                
        return true;           
        break;                                         
      } 
        else 
      {
        delay(200);         
        i = ++i;
        //Status = false;
      }

        if (i == 5)
      {
        return false; 
      }
                          
     }
            
    break;    
  }
  
}

  void ChangeLights(int Condicion)                     
{
    switch (Condicion)
  {
    case 4: //Led_Off
      digitalWrite(Led_HighBlow, LOW);
      digitalWrite(Led_LowBlow, LOW);
      digitalWrite(Led_LeftBlow, LOW);
      digitalWrite(Led_RightBlow, LOW);
      digitalWrite(Led_Green, LOW);
      digitalWrite(Led_Red, LOW);
      
      //Serial.print("To Turn Off \n");
      break;
    case 0:  //Led_HighBlow_On
      digitalWrite(Led_HighBlow, HIGH);
      digitalWrite(Led_LowBlow, LOW);
      digitalWrite(Led_LeftBlow, LOW);
      digitalWrite(Led_RightBlow, LOW);

      //Serial.print("High Blow \n");
      break;
    case 1:  //Led_LowBlow_On
      digitalWrite(Led_HighBlow, LOW);
      digitalWrite(Led_LowBlow, HIGH);
      digitalWrite(Led_LeftBlow, LOW);
      digitalWrite(Led_RightBlow, LOW);

      //Serial.print("Low Blow \n");
      break;
    case 2:  //Led_LeftBlow_On
      digitalWrite(Led_HighBlow, LOW);
      digitalWrite(Led_LowBlow, LOW);
      digitalWrite(Led_LeftBlow, HIGH);
      digitalWrite(Led_RightBlow, LOW);

      //Serial.print("Left Blow \n");
      break;
    case 3:  //Led_RightBlow_On
      digitalWrite(Led_HighBlow, LOW);
      digitalWrite(Led_LowBlow, LOW);
      digitalWrite(Led_LeftBlow, LOW);
      digitalWrite(Led_RightBlow, HIGH);

      //Serial.print("Right Blow \n");
      break;
  }
}
  
