// AppGosu  for smart phone
// @Copyright by AppGosu
// 2014.02.12


#include "AppGosu.h"
AppGosu app;


void setup() {      
   
  app.start();
  app.setDelayCmd(20);  // max speed 20ms
  app.clearAll();
  
  
  app.background(0,0,0);

  
}

void loop() {
    app.background(0,0,0);
    delay(500);
    app.background(255,0,0);
    delay(500);
    app.background(0,255,0);
    delay(500);
    app.background(255,0,255);
    delay(500);
    app.background(255,255,0);
    delay(500);
    app.background(0,255,255);
    delay(500);
  
} // end of loop

//---------------------------------------------------------

