// AppGosu  for smart phone
// @SensorClue
// by AppGosu
// 2014.09.25


#include "AppGosu.h"
AppGosu app;

int LED1 = 6;
int LED13 = 13;
int LED = 13;

void setup() {      
  
  app.start();
  app.clearAll();
  //app.nop();
  
  //app.setDelayCmd(20);
  //app.btWaiting();
  
  
  pinMode(LED1,OUTPUT);  
  pinMode(LED13,OUTPUT);  
  digitalWrite(LED13, LOW); // LED off  
  
  myStart();
  //app.upLoading();
  
}


void AppGosu::appBody() { myStart(); }



void loop() {

  
} // end of loop

//---------------------------------------------------------
void serialEvent() {  app.serialMessage();   EventLoop(); } 
void EventLoop() { 
    if( app.btConnected()) { myStart();  } // for auto starting
    if( app.btDisconnected()) { myEnd(); } // for auto BT ending
    
    // user event code here...

        if( app.eventButton(1)) {
                digitalWrite(LED13,HIGH); // LED on
                app.vibrate(500);  // simple vibrate
        }
        if( app.eventButton(2)) {
                digitalWrite(LED13, LOW); // LED off                  
                app.vibrate(0, 100,200, 300,100, 100,300); // pattern vibrate
        }

} 
//---------------------------------------------------------
void myStart(void) {
    // user starting code here
  app.clearAll();
  app.background(10,50,70);
  app.fill(250, 250, 200); 
  app.textSize(40);
  app.text("Vibrate", 90, 100);
  
  app.button("vibrate 1", 50, 400, 350, 80, 1);
  app.button("vibrate 2", 50, 500, 350, 80, 2);
 

}

void myEnd(void) {
    // user ending code here...  
}



