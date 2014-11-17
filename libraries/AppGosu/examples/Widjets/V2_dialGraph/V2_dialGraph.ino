// AppGosu 
// by AppGosu   www.AppGosu.com
// 2014.10.25

// dial graph


#include "AppGosu.h"
AppGosu app;

int LED = 13;
boolean BT_on = false;
int cnt = 0;


void setup() {      
    app.start();
    app.clearAll();
    app.setDelayCmd(15);
  
    pinMode(LED,OUTPUT);  
    digitalWrite(LED, LOW); // LED off  
  
    myStart();
    //app.upLoading();
  
}

//void AppGosu::appBody() { myStart(); }
void loop() {
  
    if( cnt > 100) { cnt = 0; }

    //circleGraph(cnt++);
    //delay(500);
    
    if(BT_on) circleGraph(cnt++);
    if(BT_on) delay(700);
} // end of loop

//---------------------------------------------------------
void serialEvent() {  app.serialMessage();   EventLoop(); } 
void EventLoop() { 
    if( app.btConnected()) {BT_on = true;  myStart();  } // for auto starting
    if( app.btDisconnected()) { myEnd(); }  // for auto starting
    
    // user event code here
    if(app.eventButton(1)) {
       cnt = 0;
      
    }
    
    if(app.eventButton(2)) {
       cnt = 50;
      
    }
  

} 
//---------------------------------------------------------
void myStart2(void) {
     circleGraph2(11); 
}
void myStart(void) {
    // user starting code here
  //app.setScale(2);
  app.clearAll();
  app.background(10,50,70);
  app.fill(250, 250, 200); 
  app.textSize(50);
  app.text("textView", 100, 100);
  //app.textView("textView", 100, 100, 50, 0, 1);
  
  
  app.textView("0", 100, 400, 150, 2, 2);
  app.textViewSetColor(200, 200, 50, 2);   // textView Color
  //app.textViewSetColor(200, 200, 50,255, 2);   // textView Color
    
  // number background
  app.noStroke();
  app.fill(171, 130, 90);
  app.ellipse(240, 400, 280, 280);
  app.fill(10,40,80);
  app.ellipse(240, 400, 250, 250);
  delay(500);
  app.fill(71, 130, 90);
  
  app.button("set 0",   80, 700, 150, 80, 1);
  app.button("set 50", 280, 700, 150, 80, 2);
  
  
}

void circleGraph(int value) {
     app.textViewSetText( (String)value, 2);
     app.fill(10,40,80);
     app.ellipse(240, 400, 250, 250);
     //app.fill(71, 130, 90);
     //app.fill(16, 59, 19);
     app.fill(75,109,78);
     app.arcDeg(240, 400, 250, 250, 0, (int)(3.6*value)   ); 
     //delay(100);
}


void circleGraph2(int value) {
     //app.textViewSetText( (String)value, 2);
     
     //app.holdOn();
     app.fill(10,40,80);
     app.ellipse(240, 400, 280, 280);
     
     app.fill(171, 130, 90);
     app.arcDeg(240, 400, 280, 280, 0, (int)(3.6*value)   ); 
     
     app.fill(10,40,80);
     app.ellipse(240, 400, 250, 250);
     //app.holdOff();
     
     app.textViewSetText( (String)value, 2);
}

void myEnd() {
        BT_on = false;
        digitalWrite(LED, HIGH); // LED on
        delay(300);
        digitalWrite(LED, LOW); // LED on
        delay(300);
        digitalWrite(LED, HIGH); // LED on
        delay(300);
        digitalWrite(LED, LOW); // LED on
}



