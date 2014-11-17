// AppGosu 
// by AppGosu   www.AppGosu.com
// 2014.10.01

// editText example

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
    if( app.eventEditText(1)) {
            String sss = app.messageEditText(1);
            app.textViewSetText("Name = " + sss, 11);
    }
    
    if( app.eventEditText(2)) {
            String sss = app.messageEditText(2);
            app.textViewSetText("PWD = " + sss, 22);
    }


} 
//---------------------------------------------------------
void myStart(void) {

  // user starting code here...
    app.clearAll();
    app.background(10,50,70);
    app.fill(250, 250, 200); 
    app.textSize(40);
    app.text("editText", 100, 100);
  
    // create editText
    app.editText(200, 200, 200, 50, 1); 
    app.editText(200, 300, 200, 50, 2); 

    app.textView("Name : ", 50, 200+30, 40, 0, 1);
    app.textView("PWD  : ", 50, 300+30, 40, 0, 2);
    
    app.textView("Name = ?", 50, 500, 40, 0, 11);
    app.textView("PWD = ?", 50, 600, 40, 0, 22);
    
    
}

void myEnd(void) {
    // user ending code here...  
}

