// AppGosu  for smart phone
// @SensorClue
// by AppGosu
// 2014.10.01


#include "AppGosu.h"
AppGosu app;

int LED = 13;
int value1 = 0;
int value2 = 0;


void setup() {      
  
  app.start();
  app.clearAll();
  
  pinMode(LED,OUTPUT);  
  digitalWrite(LED, LOW); // LED off  
  
  myStart();
  //app.upLoading();
  
}

//void AppGosu::appBody() { myStart(); }

void loop() {


  
} // end of loop

//---------------------------------------------------------
void serialEvent() {  app.serialMessage();   EventLoop(); } 
void EventLoop() { 
    if( app.btConnected()) { myStart();  } // for auto starting
    if( app.btDisconnected()) {   // for auto starting
        digitalWrite(LED, HIGH); // LED on
        delay(300);
        digitalWrite(LED, LOW); // LED on
        delay(300);
        digitalWrite(LED, HIGH); // LED on
        delay(300);
        digitalWrite(LED, LOW); // LED on
    }    
    
    // user event code here
       // button event makes numberPicker
       if( app.eventButton(1)) {
                digitalWrite(LED,HIGH); // LED on
                app.numberPicker(value1, 1);
        }
        if( app.eventButton(2)) {
                digitalWrite(LED, LOW); // LED off                  
                app.numberPicker(value2, 2);                
        }
        
        // get number from numberPicker event
        if(app.eventNumberPicker(1)){
                value1 = app.messageNumberPicker(1);
                app.textViewSetText("Num #1 :  " + (String)value1, 1);
        }
        if(app.eventNumberPicker(2)){
                value2 = app.messageNumberPicker(2);
                app.textViewSetText("Num #2 :  " + (String)value2, 2);
        }

} 
//---------------------------------------------------------
void myStart(void) {
    // user starting code here
  app.setScale(2);
  app.clearAll();
  app.background(10,50,70);
  app.fill(250, 250, 200); 
  app.textSize(50);
  app.text("numberPicker", 90, 100);

  app.button("set", 350, 300-40, 90, 80, 1);
  app.button("set", 350, 400-40, 90, 80, 2);
  
  app.textView("Num #1 : ", 30, 300, 40, 0, 1);
  app.textView("Num #2 : ", 30, 400, 40, 0, 2);
  
  
}


