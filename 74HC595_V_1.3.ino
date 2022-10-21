                       
///////////////////////     BLOW;  RED PLAYER    /////////////////////////////////////////////////
const int Led_HighBlow_RED = 1; 
const int Led_LowBlow_RED  = 2;
const int Led_LeftBlow_RED = 4; 
const int Led_RightBlow_RED = 8;
////////////////////////////  BLOWS; BLUE PLAYER  ////////////////////////////////////////////////
const int Led_HighBlow_BLUE = 1;         //16;
const int Led_LowBlow_BLUE  = 2;        //32;
const int Led_LeftBlow_BLUE = 4;       //64;
const int Led_RightBlow_BLUE = 8;     //128;
//////////////////////////////// ATTEMPTS; RED PLAYER ////////////////////////////////////////
const int Led_attempt_ONE_RED = 16;       //256;
const int Led_attempt_TWO_RED = 32;      //512;
const int Led_attempt_THREE_RED = 64;   //1024;
const int Led_attempt_FOUR_RED = 128;  //2048;
const int Led_attempt_FIVE_RED = 256; //4096; 
///////////////////////////////// ATTEMPTS; BLUE PLAYER  ///////////////////////////////////////////////////////
const int Led_attempt_ONE_BLUE = 512;        //8192;
const int Led_attempt_TWO_BLUE = 1024;      //16384;
const int Led_attempt_THREE_BLUE = 2048;   //32768;
const int Led_attempt_FOUR_BLUE = 4096;   //65536;  
const int Led_attempt_FIVE_BLUE = 8192;  //131072;  
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
#define SER 10
#define RCLK 11
#define SRCLK 12
///////////////////////////////////////////////////  GLOBALS   //////////////////////////////////////////////////////////////////////////////////////////

unsigned long previousMillis = 0; 
unsigned long currentMillis = 0; 
const long interval = 1000;     
int Case;
bool Status; 
int Mistakes = 0;

  void setup() 
{
   Serial.begin(9600);
  
   //////////////////////////////////////////////// SWITCHES; RED PLAYER //////////////////////////////////
   pinMode(Switch_HighBlow_RED, INPUT);
   pinMode(Switch_LowBlow_RED, INPUT);
   pinMode(Switch_LeftBlow_RED, INPUT);
   pinMode(Switch_RightBlow_RED, INPUT);
   ///////////////////////////////////////////////// SWITCHES; BLUE PLAYER  //////////////////////////////
   pinMode(Switch_HighBlow_BLUE, INPUT);
   pinMode(Switch_LowBlow_BLUE, INPUT);
   pinMode(Switch_LeftBlow_BLUE, INPUT);
   pinMode(Switch_RightBlow_BLUE, INPUT);
   /////////////////////////////////////////////////////// IS NOTHINGS ////////////////////////////////
   
}

  void loop() 
{  
  
}

  void UpdateBlow(int Condition)
{
    switch(Condition)
  {
    case 0:
      digitalWrite(RCLK, LOW);
     break; 
    case 1: //HighBlow
      shiftOut(SER, SRCLK, MSBFIRST,(1 >> 8)); // parte alta 
      shiftOut(SER, SRCLK, MSBFIRST,1);       // parte baja    
      digitalWrite(RCLK, HIGH);
     break; 
    case 2: //LowBlow 
      shiftOut(SER, SRCLK, MSBFIRST,(4 >> 8)); 
      shiftOut(SER, SRCLK, MSBFIRST,4);         
      digitalWrite(RCLK, HIGH);  
     break; 
    case 3: //LeftBlow 
      shiftOut(SER, SRCLK, MSBFIRST,(8 >> 8)); 
      shiftOut(SER, SRCLK, MSBFIRST,8);        
      digitalWrite(RCLK, HIGH);    
     break; 
    case 4: //RightBlow 
      shiftOut(SER, SRCLK, MSBFIRST,(16 >> 8)); 
      shiftOut(SER, SRCLK, MSBFIRST,16);         
      digitalWrite(RCLK, HIGH);  
     break;  
  }
}

  void UpdateAttempts(int Condittion)
{
    switch (Condittion)
  {
    case 0:
      digitalWrite(RCLK, LOW);    
      shiftOut(SER, SRCLK, MSBFIRST,(1 >> 8)); // parte alta 
      shiftOut(SER, SRCLK, MSBFIRST,1);       // parte baja    
      digitalWrite(RCLK, HIGH);
     break; 
    case 1: 
     break; 
    case 2: 
     break; 
    case 3: 
     break; 
    case 4: 
     break; 
    case 5: 
     break; 
  }
  
}
