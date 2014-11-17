// AppGosu 
// by AppGosu   www.AppGosu.com
// 2014.10.25

// Demo graphics


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
    if( app.btConnected()) { myStart();  } // for auto BT starting
    if( app.btDisconnected()) { myEnd(); } // for auto BT ending

    // user event code here...


} 
//---------------------------------------------------------
void myStart(void) {
    // user starting code here...
    app.clearAll();
    app.background(10,50,70);
    app.fill(250, 250, 200); 
    app.textSize(50);
    app.text("AppGosu", 120, 80);
    
    demo();
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
//----------------------------------------------------------
void demo(void) {
   app.textSize(30);
   app.fill(200,200,30);
   app.text("Graphics", 50, 150);
  
   app.fill(250,250,200);
   app.text("line", 50, 200);
   app.line(200,190, 400, 190);
   
   app.noStroke();
   app.fill(250,250,200);
   app.text("rect", 50, 250);
   app.rect(200,220,100,40);
   
   app.fill(250,250,200);
   app.text("ellipse", 50, 310);
   app.fill(250, 190, 10);
   app.ellipse(220, 300, 40, 40);
   app.fill(150, 190, 210);
   app.ellipse(350, 300, 80, 40);
   
   app.fill(250,250,200);
   app.text("triangle", 50, 380);
   app.fill(50, 190, 200);
   app.triangle(200+25,350, 200,400, 200+50,400  );
   
   app.fill(250,250,200);
   app.text("arc", 50, 450);
   app.fill(200, 100, 160);
   app.arcDeg(225,450-10,50,50, 0, 270);
  
   //-----
   app.fill(250,250,140);
   app.text("fill", 50, 530);
   app.text("stroke", 300, 530);
   
   app.text("background", 50, 580);
   app.text("image", 300, 580);
   
   app.text("text", 50, 630);
   app.text("textSize", 300, 630);
   
   //app.text("imagePath", 50, 530);
  
}


