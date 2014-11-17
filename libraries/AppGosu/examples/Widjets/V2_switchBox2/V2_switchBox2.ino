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
    if( app.eventSwitchBox(1)) {
                sb1 = app.messageSwitchBox(1);
                if( sb1 == 1) {
                     //app.textViewSetColor(250, 250, 30, 255, 1); 
                     app.textViewSetColor(250, 250, 30, 1); 
                     app.textViewSetText("SB 1 : on", 1); 
                } 
                else if( sb1 == 0) {
                     //app.textViewSetColor(200, 200, 200, 255, 1); 
                     app.textViewSetColor(200, 200, 200, 1); 
                     app.textViewSetText("SB 1 : off", 1); 
                }
        }
  if( app.eventSwitchBox(2)) {
                sb2 = app.messageSwitchBox(2);
                if( sb2 == 1) {
                     //app.textViewSetColor(250, 250, 30, 255, 2); 
                     app.textViewSetColor(250, 250, 30, 2); 
                     app.textViewSetText("SB 2 : on", 2); 
                } 
                else if( sb2 == 0) {
                     //app.textViewSetColor(200, 200, 200, 255, 2); 
                     app.textViewSetColor(200, 200, 200, 2); 
                     app.textViewSetText("SB 2 : off", 2); 
                }
        }

} 
//---------------------------------------------------------
void myStart(void) {
    // user starting code here...
  app.clearAll();
  app.background(10,50,70);
  app.fill(250, 250, 200); 
  app.textSize(50);
  app.text("switchBox", 100, 100);
  
  app.switchBox("control",  100, 200, 0, 1);
  app.switchBox("prameter", 100, 300, 1, 2);

  app.textView("which switchBox?", 50, 500, 40, 0, 1);
  app.textView("which switchBox?", 50, 570, 40, 0, 2);
  
}
void myEnd(void) {
    // user ending code here...  
}

