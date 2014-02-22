// AppGosu  for smart phone
// @CopyRight by AppGosu
// 2014.02.05

#include "AppGosu.h"
AppGosu app;

int LED1 = 6;
int LED13 = 13;

void setup() {      
  //delay(5000);  
  
  app.start();
  app.setDelayCmd(20);
  //app.btWaiting();
  
  pinMode(LED1,OUTPUT);  
  pinMode(LED13,OUTPUT);  
  digitalWrite(LED13, LOW); // LED off  
  
  myStart();
}


void loop() {

  
} // end of loop

//---------------------------------------------------------
void serialEvent() {
      app.serialMessage(); 
      EventLoop();
} 
void EventLoop() { 
    if( app.btConnected()) {   // for auto starting
        myStart();
    }
    
    // user event code here

        if( app.eventButton(1)) {
                //app.sound("music.mp3"); // edit your mp3 file
                digitalWrite(LED13,HIGH); // LED on
        }
        if( app.eventButton(2)) {
                app.stopSound();
                digitalWrite(LED13, LOW); // LED off                  
        }


} 
//---------------------------------------------------------
void myStart3(void) {
  app.clearAll();
  app.background(0,0,0);
  app.textSize(70); 
  app.background(10,50,70);
  app.fill(250, 250, 200); 
  app.text("AppGosu", 100, 100);
  app.textSize(50);            
  app.fill(250, 150, 100);     
  app.text("App Control", 50, 300); 
  app.text("from MCU code", 50, 350); 
  app.fill(90, 150, 180);            
  app.text("graphic test", 50, 450); 
  app.stroke(255, 255, 255);         
  app.line(10, 600, 450, 600);       
  app.noStroke();                    
  app.fill(90, 150, 180);            
  app.ellipse(100, 600, 150, 100);   
  app.rect(250,550,50,100);          
  app.triangle(400, 550, 350, 650, 450, 650);
  app.arcDeg(100, 670, 180, 180, 90, 150);   
  app.fill(150, 250, 100) ;                  
  app.text("Text Color1 ", 200, 710);        
  app.fill(200, 220, 100);                   
  app.text2("Text Color2 ", 200, 780);       
  
}


void myStart(void) {

  // user starting code here
  app.clearAll();
  app.background(0,0,0);
  app.textSize(70); 
  app.background(10,50,70);
  app.fill(250, 250, 200); 
  app.text("AppGosu", 120, 100);
  app.textSize(50);            

  app.fill(250, 250, 200); 
  app.textSize(50);
  app.text("Embedded app", 80, 200);
  app.textSize(40);
  app.fill(255,255,50);
  app.text("Draw text", 80, 400);
  app.text("and graphics", 200, 450);

  app.stroke(255,255,255);
  app.line(50,150, 430,150);
  app.fill(250, 250, 200); 
  app.rect(100,250,50,50);
  app.fill(250, 190, 10);
  app.noStroke();
  app.ellipse(200,250+25,50,50);
  app.fill(50, 190, 200);
  app.triangle(350-50,250, 300-50,300, 400-50,300  );
  app.fill(200, 100, 160);
  app.arcDeg(400,250+25,50,50, 0, 270);
  
  //app.image("appledOn.png", 80, 480, 100, 150);  // edit your image
  app.fill(255,255,50);
  app.text("draw image", 220, 550);
  
  //app.loadVideo("blast1.mp4", 250, 400, 150, 150); // edit your mp4 file
  //app.playVideo();
  

  app.text("control widjet", 100, 690);
  app.button(" button 1"  , 50, 700, 150, 80, 1);
  app.button(" button 2 ", 250, 700, 150, 80, 2);

}



