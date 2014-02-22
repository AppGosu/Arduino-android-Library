// AppGosu  for smart phone
// @Copyright by AppGosu
// 2014.02.12


#include "AppGosu.h"
AppGosu app;


void setup() {      
   
  app.start();
  app.setDelayCmd(300);  // max speed 20ms
  app.clearAll();
  
}

void loop() {
    app.background(0,0,0);
    app.textSize(50);
    app.Ttext("--- Text Size ---", 50, 70);
    
    for(int i=1; i<6; i++) {
        app.textSize(20*i);
        app.text("Size : " + (String)(20*i) , 10, 100*i);
    }
    delay(5000);
  
} // end of loop

//---------------------------------------------------------

