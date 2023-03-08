#ifndef Pin_h
#define Pin_h
#include <Arduino.h>
class Pin{

   
      
  public:
  Pin(int pin, int IDENTITY, int pin_mode);
          
          int GetIdentifier();
          void State(bool state);//Allows for direct modification of state _state = state
          void ToggleState();//Allows you to toggle the state   _state = !_state; 
          void TimedRun(unsigned long interval); // runs pin for a specific time in miliseconds
          void Refresh(unsigned time);// Refreshs the pin to determine whether or not it should still be running
          void Override(bool state);//Allows us to turn off the timer part 
          int  ReadPin(); // Read a digital pin state
          int GetState(); // returns state;
  private:
          int pin;
          int _identifier;
          bool _state;
          unsigned long _interval; 
          unsigned long _ptime;//previous time
          bool override =false;
  
  
  
  };
  Pin::Pin(int pin,  int _identifier, int pin_mode = PinMode::OUTPUT)   {
        this->pin = pin;
        this->_identifier = _identifier; 
        pinMode(pin,pin_mode);
        //Initializes the pin with a pin and Identity 
        //which can then be put into an array or hash table for quick and dynamic access.  
			
      };
      int Pin::ReadPin(){
        return digitalRead(pin);

      }
  int Pin::GetState() {return _state;};
  void Pin::Override(bool override) {this->override = override;};
  void Pin::ToggleState(){_state = !_state;};
  void Pin::State(bool state)
  { 
    this->_state = state;
  }; 
  int Pin::GetIdentifier()
  {
    return _identifier;
  };
  void Pin::TimedRun(unsigned long _interval)
  {
    this->_interval = _interval; 
	_ptime = millis();	
	_state = 0;
  };
  void Pin::Refresh(unsigned time)
  {
    if(override){ digitalWrite(pin,HIGH);
	  _state = 1;}else{
    if((millis() - _ptime >= _interval)  )
    {
      digitalWrite(pin,LOW);
      _interval = 0;
      _ptime = 0;
	  _state = 0;
    }
    else
    {
      digitalWrite(pin,HIGH);
	  _state = 1;

    } 
    }
  
  };


#endif
