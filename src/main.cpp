#include <Arduino.h>
#include "..\lib\Pin.h"
#define PASS_PLUS
Pin Led_Pins[]=
{
  Pin(6,1),
  Pin(7,2),
  Pin(8,3),
  Pin(9,4),
  Pin(10,5)
};

Pin Button_Pins[] ={
  Pin(2,1,INPUT_PULLUP),
  Pin(3,2,INPUT_PULLUP),
  Pin(4,3,INPUT_PULLUP),
  Pin(5,4,INPUT_PULLUP)

};
// LED BAR GRAPH
//  reserved for push{1 d2 2 d3 3 d4 4 d5} 5 d6 6 d7 7 d8 8 d9 9 d10 10 d11
#ifdef PASS_PLUS
int buttonOffToggle;
int lastOffToggleState;
#endif
void setup() {
  
  #ifdef PASS_PLUS
   for (int i = 0 ; i <  (sizeof(Led_Pins) / sizeof(Led_Pins[0])); i++)
    Led_Pins[i].TimedRun(0);

   for (int i = 0 ; i <  (sizeof(Button_Pins) / sizeof(Button_Pins[0])); i++)
    Button_Pins[i].TimedRun(0);

  Button_Pins[0].ReadPin();
  buttonOffToggle = Button_Pins[0].GetState();
  
  #endif
  // put your setup code here, to run once:
   // for (int i = 2; i !=12; i++) {        //Declares pin mode for pins 2-12
   // pinMode(i, OUTPUT);
 // }
}

void loop() {
  // put your main code here, to run repeatedly:
 

  #ifdef PASS_PLUS


  for (int i = 0 ; i < (sizeof(Led_Pins) / sizeof(Led_Pins[0])); i++)
  {
    Led_Pins[i].TimedRun(100*i);
    Led_Pins[i].Refresh(millis());  
  };
  for (int i = 0 ; i <  (sizeof(Led_Pins) / sizeof(Led_Pins[0])); i++)
  {  
    Led_Pins[i].Refresh(millis());
    delay(150);
   };    
 



  #endif
}