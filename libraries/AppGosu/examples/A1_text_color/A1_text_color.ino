// AppGosu  for smart phone
// @Copyright by AppGosu
// 2014.02.16


#include "AppGosu.h"
AppGosu app;


void setup() {      
   
  app.start();
  app.setDelayCmd(20);  // max speed 20ms
  app.clearAll();
  
}

void loop() {
    app.background(0,0,0);
    app.textSize(50);
    app.fill(255,255,255);
    app.Ttext("--- Text Color ---", 30, 50);
    app.textSize(30);
    app.Ttext("by AppGosu", 50, 750);
    
    app.setDelayCmd(300);
    app.textSize(50);
    for(int i=2; i<8; i++) {
        app.fill( random(255), random(255), random(255) );
        app.text("Text Color", 50, 100*i);
    }
    delay(3000);
  
} // end of loop

//---------------------------------------------------------

