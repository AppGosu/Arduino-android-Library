// AppGosu 
// by AppGosu   www.AppGosu.com
// 2014.10.01

// checkBox example

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
    if( app.btConnected()) { myStart();  } // for auto BT starting
    if( app.btDisconnected()) { myEnd(); } // for auto BT ending
    
    // user event code here
    if( app.eventCheckBox(1)) {
                cb1 = app.messageCheckBox(1);
                if( cb1 == 1) {
                     app.textViewSetText("CB 1 : checked", 1); 
                } 
                else if( cb1 == 0) {
                     app.textViewSetText("CB 1 : unchecked", 1); 
                }
        }
  if( app.eventCheckBox(2)) {
                cb2 = app.messageCheckBox(2);
                if( cb2 == 1) {
                     app.textViewSetText("CB 2 : checked", 2); 
                } 
                else if( cb2 == 0) {
                     app.textViewSetText("CB 2 : unchecked", 2); 
                }
        }

} 
//---------------------------------------------------------
void myStart(void) {
    // user starting code here...
    app.setScale(2);
    app.clearAll();
    app.background(10,50,70);
    app.fill(250, 250, 200); 
    app.textSize(50);
    app.text("checkBox", 100, 100);
  
    app.checkBox("control",  100, 200, 0, 1);
    app.checkBox("prameter", 100, 300, 1, 2);

    app.textView("which checkBox?", 50, 500, 40, 0, 1);
    app.textView("which checkBox?", 50, 570, 40, 0, 2);
}

void myEnd(void) {
    // user ending code here...  
}

