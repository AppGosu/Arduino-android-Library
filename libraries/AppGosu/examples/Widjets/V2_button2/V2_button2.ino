// AppGosu 
// by AppGosu   www.AppGosu.com
// 2014.10.01

// button example

#include "AppGosu.h"
AppGosu app;

int LED = 13;
int cb1,cb2;


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
    if( app.btDisconnected()) { myEnd(); } // for auto ending
    
    // user event code here
    if( app.eventButton(1)) {
          app.textViewSetText("button1 clicked", 1); 
          digitalWrite(LED, HIGH); // LED on
    }
    if( app.eventButton(2)) {
          app.textViewSetText("button2 clicked", 1); 
          digitalWrite(LED, LOW); // LED off
    }


} 
//---------------------------------------------------------
void myStart(void) {

  // user starting code here...
    app.clearAll();
    app.background(10,50,70);
    app.fill(250, 250, 200); 
    app.textSize(40);
    app.text("button", 100, 100);
  
    app.button("button 1", 50, 400, 350, 80, 1);
    app.button("button 2", 50, 500, 350, 80, 2);

    app.textView("which button?", 50, 250, 40, 0, 1);
}

void myEnd(void) {
    // user ending code here...  
}

