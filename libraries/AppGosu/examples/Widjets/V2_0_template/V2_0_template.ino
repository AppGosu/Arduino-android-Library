// AppGosu 
// by AppGosu   www.AppGosu.com
// 2014.10.01

// code template

#include "AppGosu.h"
AppGosu app;

int LED = 13;

void setup() {      
  
  app.start();
  app.clearAll();
  
  pinMode(LED,OUTPUT);  
  digitalWrite(LED, LOW); // LED off  
  
  myStart();
  //app.upLoading();  // for inital screen uploading
  
}

//void AppGosu::appBody() { myStart(); }

void loop() {


  
} // end of loop

//---------------------------------------------------------
void serialEvent() {  app.serialMessage();   EventLoop(); } 
void EventLoop() { 
    if( app.btConnected()) { myStart();  } // for auto BT starting
    if( app.btDisconnected()) { myEnd(); } // for auto BT ending

    // user event code here


} 

//---------------------------------------------------------
void myStart(void) {
    // user starting code here...
    
    //app.setScale(1); // use original smart phone screen size
    //app.setScale(2); // screen size(480, 800) defalut
    app.clearAll();
    app.background(10,50,70);
    app.fill(250, 250, 200); 
    app.textSize(50);
    app.text("Hello World.", 50, 100);
}

void myEnd(void) {
    // user ending code here
    digitalWrite(LED, HIGH); // LED on
    delay(300);
    digitalWrite(LED, LOW); // LED off
    delay(300);
    digitalWrite(LED, HIGH); // LED on
    delay(300);
    digitalWrite(LED, LOW); // LED off
}

