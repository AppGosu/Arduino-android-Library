// AppGosu  for smart phone
// @SensorClue
// by AppGosu
// 2014.10.01


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


  
} // end of loop

//---------------------------------------------------------
void serialEvent() {  app.serialMessage();   EventLoop(); } 
void EventLoop() { 
    if( app.btConnected()) { myStart();  } // for auto starting
    if( app.btDisconnected()) { myEnd(); } // for auto BT ending
    
    // user event code here...


} 
//---------------------------------------------------------
void myStart(void) {
    // user starting code here
  app.setScale(2);
  app.clearAll();
  app.background(10,50,70);
  app.fill(250, 250, 200); 
  app.textSize(50);
  app.text("Toast", 100, 100);

  delay(500);
  app.showToast("This is Toast.");
  
  delay(3500);
  app.showToast("Toast is short message.");
  
  
}

void myEnd(void) {
    // user ending code here...  
}


