// AppGosu  for smart phone
// @SensorClue
// by AppGosu
// 2014.10.01


#include "AppGosu.h"
AppGosu app;

int LED = 13;
int sb1,sb2;
int R = 0, G = 0, B = 0;

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

    // user event code here
    if(app.eventSeekBar(1)){
         R = app.messageSeekBar(1);
         app.textViewSetText( (String)R, 1); 
         app.background(R,G,B);
    }
    if(app.eventSeekBar(2)){
         G = app.messageSeekBar(2);
         app.textViewSetText( (String)G, 2); 
         app.background(R,G,B);
     }
     if(app.eventSeekBar(3)){
         B = app.messageSeekBar(3);
         app.textViewSetText( (String)B, 3); 
         app.background(R,G,B);
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
  app.textView("RGB seekBar", 30, 130, 40, 0);  
  
  // delay slow 15
  app.setDelayEventSeekBar(5); // default(10)   
  
  // make seekBar
  app.seekBar(100, 200, 350, 255, 30, 1);
  app.seekBar(100, 300, 350, 255, 50, 2);
  app.seekBar(100, 400, 350, 255, 70, 3);
  
  // make textView
  app.textView("30", 20, 200, 40, 1);
  app.textView("50", 20, 300, 40, 2);
  app.textView("70", 20, 400, 40, 3);
  
  // set textView color
  app.textViewSetColor(255, 0, 0,  1);
  app.textViewSetColor(0, 255, 0,  2);
  app.textViewSetColor(0, 0, 255,  3);
  
}

void myEnd(void) {
    // user ending code here...  
}



