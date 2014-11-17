// AppGosu  for smart phone
// @SensorClue
// by AppGosu
// 2014.09.25


#include "AppGosu.h"
AppGosu app;

int LED = 13;

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
  /*
  for(int i=0; i<100; i=i+10) {
      app.textViewSetText( (String)i, 5);
      delay(300);
  }
  */
  //app.vibrate(200);
  

  
} // end of loop

//---------------------------------------------------------
void serialEvent() {  app.serialMessage();   EventLoop(); } 
void EventLoop() { 
    if( app.btConnected()) { myStart();  } // for auto starting
    if( app.btDisconnected()) { myEnd(); } // for auto BT ending
    
    // user event code here


} 
//---------------------------------------------------------
void myStart(void) {
    // user starting code here
  app.setScale(2);
  app.clearAll();
  app.background(10,50,70);
  app.fill(250, 250, 200); 
  app.textSize(50);
  app.text("textView", 100, 100);
  //app.textView("textView", 100, 100, 50, 0, 1);
  
  
  app.textView("textView", 100, 400, 70, 0, 2);
  app.textViewSetColor(200, 200, 50, 2);   // textView Color
  delay(500);
  app.textViewSetAlign(1, 2);     // textView align left = 1 
  delay(500);
  app.textViewSetAlign(3, 2);     // textView align right = 3 
  delay(500);
  app.textViewSetAlign(2, 2);     // textView align center = 2 
  delay(500);
  app.textViewSetText("0", 2);    // textView setText = "0"
  delay(500);
  app.textViewSetSize(150, 2);    // textView  Size = 150
  delay(500);
  
  /*
  // number background
  app.noStroke();
  app.fill(171, 130, 90);
  app.ellipse(240, 400, 280, 280);
  app.fill(10,40,80);
  app.ellipse(240, 400, 250, 250);
  delay(500);
  
  for(int i=0; i<100; i++) {
     app.textViewSetText( (String) i, 2); 
     delay(300);
  }
  */
  
}

void myEnd(void) {
    // user ending code here...  
}


