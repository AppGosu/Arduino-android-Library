// AppGosu  for smart phone
// @SensorClue
// by AppGosu
// 2014.10.01


#include "AppGosu.h"
AppGosu app;

int LED = 13;
int sb1,sb2;


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
    if( app.btDisconnected()) { myEnd(); } // for auto BT ending

    // user event code here...
    if(app.eventSeekBar(1)){
         int value1 = app.messageSeekBar(1);
         app.textViewSetText( (String)value1, 1); 
    }
    if(app.eventSeekBar(2)){
         int value2 = app.messageSeekBar(2);
         app.textViewSetText( (String)value2, 2); 
     }
     if(app.eventSeekBar(3)){
         int value3 = app.messageSeekBar(3);
         app.textViewSetText( (String)value3, 3); 
     }

} 
//---------------------------------------------------------
void myStart(void) {
    // user starting code here
  app.clearAll();
  app.background(10,50,70);
  app.fill(250, 250, 200); 
  app.textSize(50);
  app.text("seekBar", 100, 100);
  
  app.setDelayEventSeekBar(2); // default(10)   
  
  app.seekBar(100, 200, 350, 100, 30, 1);
  app.seekBar(100, 300, 350, 100, 50, 2);
  app.seekBar(100, 400, 350, 100, 70, 3);
  
  
  app.textView("30", 20, 200, 40, 1);
  app.textView("50", 20, 300, 40, 2);
  app.textView("70", 20, 400, 40, 3);
  
}

void myEnd(void) {
    // user ending code here...  
}

