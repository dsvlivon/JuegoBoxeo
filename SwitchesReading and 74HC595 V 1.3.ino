

////////////////////////////////// SWITCHES; RED PLAYER  ////////////////////////////////////////////////////////////////////////
#define Switch_HighBlow_RED 2
#define Switch_LowBlow_RED 3
#define Switch_LeftBlow_RED 4
#define Switch_RightBlow_RED 5 
////////////////////////////////// SWITCHES; BLUE PLAYER  /////////////////////////////////////////////////////////////////////////////
#define Switch_HighBlow_BLUE 6
#define Switch_LowBlow_BLUE 7
#define Switch_LeftBlow_BLUE 8
#define Switch_RightBlow_BLUE 9 
////////////////////////////////// 74HC595  //////////////////////////////////////////////////////////////////////////////////////////////////
#define SER 2
#define RCLK 3
#define SRCLK 4
////////////////////////////////////////////////// GLOBALS  //////////////////////////////////////////////////////////////////////////////////
unsigned long previousMillis_1 = 0; 
unsigned long previousMillis_2 = 0;
unsigned long currentMillis = 0; 
const long interval_1 = 1000;
const long interval_2 = 600;
//int Case;
int Mistakes = 0;
int RandNum;
int ALTO;
int MEDIO;
int var; 
bool Status; 
////////////////////////////////////////////////////////// LED WRITE /////////////////////////////////////////////////////////////////////////
void ledWrite(int BAJO,int MEDIO, int ALTO)
{
   shiftOut(SER, SRCLK, MSBFIRST, ALTO);   // parte alta
   shiftOut(SER, SRCLK, MSBFIRST, MEDIO); // parte media
   shiftOut(SER, SRCLK, MSBFIRST, BAJO); // parte baja
   digitalWrite(RCLK, HIGH);
   digitalWrite(RCLK, LOW);
}
////////////////////////////////////////////////////// SETUP  /////////////////////////////////////////////////////////////////////////////////
  void setup()
{
   Serial.begin(9600);

  /////////////////////////////////// 74HC595 //////////////
   pinMode(SER, OUTPUT);
   pinMode(RCLK, OUTPUT);
   pinMode(SRCLK, OUTPUT);  
   ///////////////////////////////////// SWITCHES RED //////
   pinMode(Switch_HighBlow_RED, INPUT);
   pinMode(Switch_LowBlow_RED, INPUT);
   pinMode(Switch_LeftBlow_RED, INPUT);
   pinMode(Switch_RightBlow_RED, INPUT);
   ////////////////////////////////////// SWITCHES BLUE ///
   pinMode(Switch_HighBlow_BLUE, INPUT);
   pinMode(Switch_LowBlow_BLUE, INPUT);
   pinMode(Switch_LeftBlow_BLUE, INPUT);
   pinMode(Switch_RightBlow_BLUE, INPUT);
   ///////////////////////////////////////////////////////
}

  void loop() 
{  
      if (Mistakes == 5)
    {
      //delay(500);
      Mistakes = 0;
    } 
    while (Mistakes < 5)
  {
    RandNum = random(1, 5);
    UpdateLeds(RandNum, Mistakes, Mistakes);
    Status = SwitchesReading(RandNum);
      if (Status == false)
    {
      Mistakes = ++Mistakes;
    }  
    Serial.print(var);
    Serial.print(Status);
    //delay(500);

  } 
}
/////////////////////////////////////////////////////////// UpdateBlows /////////////////////////////////////////////////////////////////////
   void UpdateLeds(int Bajo, int Medio, int Alto) 
{
      switch (Bajo) 
    {
      case 0: // To turn Off
         ledWrite(B00000000, MEDIO, ALTO);
       break; 
      case 1: // HighBlow
         ledWrite(B10001000, MEDIO, ALTO);
       break; 
      case 2: // LeftBlow
         ledWrite(B01000100, MEDIO, ALTO);
       break; 
      case 3: // RightBlow
         ledWrite(B00100010, MEDIO, ALTO);
       break;     
      case 4: // LowBlow
         ledWrite(B00010001, MEDIO, ALTO);
       break;     
    }  
      switch (Medio) 
    {
      case 0: 
         MEDIO = B11110000;
       break; 
      case 1: 
         MEDIO = B11100000;
       break; 
      case 2: 
        MEDIO = B11000000;
       break; 
      case 3: 
       MEDIO = B10000000;
       break;     
      case 4: 
       MEDIO = B00000000;
       break;     
    }    
      switch (Alto) 
    {
      case 0: 
         ALTO = B11110000;
       break; 
      case 1: 
         ALTO = B11100000;
       break; 
      case 2: 
        ALTO = B11000000;
       break; 
      case 3: 
       ALTO = B10000000;
       break;     
      case 4: 
       ALTO = B00000000;
       break;     
    }       
}


////////////////////////////////////////////////////////// SWITCHES; READ ///////////////////////////////////////////////////////////////////
   bool SwitchesReading(int condittion)
{
   bool var; 
   int i = 0;
    switch (condittion)
  { 
     case 1: 
        while(i <= 5)
     {  
        delay(100);   
        var = digitalRead(Switch_HighBlow_RED);           //Leo el switch, siendo esá mi lectura predeterminada.   
           if (var == 1)                                
         {                                                // Siendo el 1 logico, mí lectura predeterminada, esta acción se ejecutara cuando lea un 0.  
           //delay(200);                                   // Retardo antirebote para mí "Pull Down" 
           return true; 
           break;                                          
         }
           else 
         {
           //delay(200);         
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
        delay(100);    
        var = digitalRead(Switch_LowBlow_RED);              
           if (var == 1)                                
         {                                                
           //delay(200);                                    
           return true; 
           break;                                          
         }
           else 
         {
           //delay(200);         
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
        delay(100);        
        var = digitalRead(Switch_LeftBlow_RED);           //Leo el switch, siendo esá mi lectura predeterminada.   
           if (var == 1)                                
         {                                                // Siendo el 1 logico, mí lectura predeterminada, esta acción se ejecutara cuando lea un 0.  
           //delay(200);                                   // Retardo antirebote para mí "Pull Down" 
           return true; 
           break;                                          
         }
           else 
         {
           //delay(200);         
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
        delay(100);      
        var = digitalRead(Switch_RightBlow_RED);           //Leo el switch, siendo esá mi lectura predeterminada.   
           if (var == 1)                                
         {                                                // Siendo el 1 logico, mí lectura predeterminada, esta acción se ejecutara cuando lea un 0.  
           //delay(200);                                   // Retardo antirebote para mí "Pull Down" 
           return true; 
           break;                                          
         }
           else 
         {
           //delay(200);         
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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

