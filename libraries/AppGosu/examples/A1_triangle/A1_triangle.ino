// AppGosu  for smart phone
// @Copyright by AppGosu
// 2014.02.16


#include "AppGosu.h"
AppGosu app;


void setup() {      
   
  app.start();
  app.setDelayCmd(100);  // max speed 20ms
  app.clearAll();
  
}

void loop() {
    app.background(0,0,0);
    app.textSize(50);
    app.fill(255,255,255);
    app.Ttext("--- triangle ---", 60, 50);
    
    for(int i=3; i<10; i++) {
        app.stroke( random(50,255), random(50,255), random(50,255) );
        app.fill( random(50,255), random(50,255), random(50,255) );
        app.triangle(240, 50*i, 190-(i*15), 50*(i+1), 290+(i*15),50*(i+1) );
    }
    delay(3000);
  
} // end of loop

//---------------------------------------------------------

