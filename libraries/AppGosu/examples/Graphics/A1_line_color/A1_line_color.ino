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
    app.Ttext("--- Line Color ---", 10, 50);
    
    for(int i=3; i<15; i++) {
        app.stroke( random(50,255), random(50,255), random(50,255) );
        app.line(50, 50*i, 430, 50*i);
    }
    delay(3000);
  
} // end of loop

//---------------------------------------------------------

