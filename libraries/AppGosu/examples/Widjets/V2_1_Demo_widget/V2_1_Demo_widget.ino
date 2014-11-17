// AppGosu 
// by AppGosu   www.AppGosu.com
// 2014.10.25

// Demo widgets


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
    // user starting code here
    app.clearAll();
    app.background(10,50,70);
    app.fill(250, 250, 200); 
    app.textSize(50);
    app.text("AppGosu", 120, 80);
    
    demo_widget();
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

void demo_widget(void) {
    app.textSize(30);
    app.fill(200,200,40);
    app.text("Widgets", 50, 150);  
  
    app.textView("button", 50, 200+10, 30, 1);
    app.button("OK"  ,     200, 200, 100, 60, 1);
    app.button("Cancel"  , 320, 200, 150, 60, 2);
    
    app.textView("editText", 50, 250+20, 30, 2);
    app.editText(200, 250, 150, 60, 1);
    
    app.textView("checkBox", 50, 330, 30, 3);
    app.checkBox("item1", 200, 330, 1, 1);
    app.checkBox("item2", 320, 330, 0, 2);
    
    app.textView("switchBox", 50, 390, 30, 4);
    app.switchBox("item", 250, 390, 1, 1);
    
    app.textView("seekBar", 50, 450, 30, 5);
    app.seekBar(200, 450, 200, 100, 80, 1);
    
    
    //----------
    app.textView("imageButton", 50, 520, 30, 11);
    app.textView("dialogBox", 300, 520, 30, 12);
    
    app.textView("numberPicker", 50, 570, 30, 14);
    app.textView("toast", 300, 570, 30, 13);
    
    app.textView("mousePressRect", 50, 620, 30, 16);
    app.textView("vibrate", 320, 620, 30, 15);
    
    app.textView("sound", 50, 670, 30, 17);
    app.textView("playVideo", 300, 670, 30, 18);
    
    for(int k=11; k<19; k++) {
      app.textViewSetColor(250,250,140,k);
    }
  
}



