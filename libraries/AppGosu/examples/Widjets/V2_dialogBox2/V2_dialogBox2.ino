// AppGosu  for smart phone
// @SensorClue
// by AppGosu
// 2014.10.01

// dialogBox example

#include "AppGosu.h"
AppGosu app;

int LED = 13;
int value = 35;  // inital setting value

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
          if( app.eventButton(1)) {
                digitalWrite(LED,HIGH); // LED on
                app.dialogBox("User title 1", "User description 1", 1);
           }
           if( app.eventButton(2)) {
                digitalWrite(LED, LOW); // LED off                  
                app.dialogBox("Setting value", "value is  " + (String)value, 2);
            }
            
        // get event method #1    
        if(app.eventDialogBox(1)){                   
               if(app.messageDialogBox(1) == 1) {    // ok clicked
                     app.background(10,50,70);
                     app.text("DialogBox #1 OK !", 30, 100); 
               } 
               else                                // cancel clicked 
               {
                     app.background(10,50,70);
                     app.text("DialogBox #1 cancel !", 30, 100); 
               }
        }
        // get event another method #2
        if(app.eventDialogBox(2)){     
               int abc = app.messageDialogBox(2);
               if(abc == 1) {      // ok clicked
                     app.background(10,50,70);
                     app.text("DialogBox #2 OK !", 30, 100); 
               }
               if(abc == 0) {      // cancel clicked
                     app.background(10,50,70);
                     app.text("DialogBox #2 cancel !", 30, 100); 
               }

        }


} 
//---------------------------------------------------------
void myStart(void) {
    // user starting code here
  app.setScale(2);
  app.clearAll();
  app.background(10,50,70);
  app.fill(250, 250, 200); 
  app.textSize(40);
  app.text("dialogBox", 100, 100);

  app.button("Show DialogBox 1", 100, 400, 280, 80, 1);
  app.button("Show DialogBox 2", 100, 500, 280, 80, 2);
  
}

void myEnd(void) {
    // user starting code here

        digitalWrite(LED, HIGH); // LED on
        delay(300);
        digitalWrite(LED, LOW); // LED on
        delay(300);
        digitalWrite(LED, HIGH); // LED on
        delay(300);
        digitalWrite(LED, LOW); // LED on
}
