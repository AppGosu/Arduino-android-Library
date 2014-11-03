/*
AppGosu :: Arduino-Android Library  ver. 2.0
By AppGosu.com
Updated : 2014-10-10
License : BSD
More information : Please visit    www.AppGosu.com
*/ 



#include "AppGosu.h"

/*
#ifdef SoftS_app
#include <SoftwareSerial.h>
SoftwareSerial Gosu_Uart(2,3); //RX, TX
#endif
*/
#ifdef SoftS_app
SoftwareSerial Gosu_Uart(_RX_PIN, _TX_PIN); // RX, TX  Don't change this.
#endif

#define AGNULL	NULL
String AppGosu_String = "";  

AppGosu::AppGosu(void) {
    delay_cmd = 20;  // app execution speed (depending on your smart phone)
    tx_pin = 1;  // hardware serial  port for transmiting
    rx_pin = 0;  // hardware serial  port for receiving
    baudRate = 115200;

    C = ", ";
    C2 = ",";
    E = ");";
    E2 = ";";
    S1 = "'";
    S2 = "'";
    m_type = 0; m_id=0; m_data = "_null_";
}
AppGosu::AppGosu(int r, int t) {
    delay_cmd = 20;
    rx_pin = r;  
    tx_pin = t;  
    baudRate = 115200;
    C = ", ";
    C2 = ",";
    E = ");";
    E2 = ";";
    S1 = "'";
    S2 = "'";
    m_data = "_null_";
}
void AppGosu::start(long baud) {
   #ifdef SoftS_app
   Gosu_Uart.begin(baud);
   #else
   Serial.begin(baud);
   #endif
   
   delay(300);
}
void AppGosu::start(void) {
   #ifdef SoftS_app
   Gosu_Uart.begin(baudRate);
   #else
   Serial.begin(baudRate);
   #endif

   delay(200);
   nop();
   nop();
}
void AppGosu::btWaiting(void) {
    // AppGosuBT\n
    char rx_data;

    #ifdef SoftS_app
    while(1) {
       /*  not implemeted
        if(Gosu_Uart.available() > 0) {
            rx_data = Gosu_Uart.read();
            if(rx_data == 0x77) return;
        }
        */
    }
    #else
    while(1) {
             serialMessage();
             if(btConnected()) return;
       /*
        if(Serial.available() > 0) {
            rx_data = Serial.read();
            if(rx_data == 0x77) {   return;  }
        }
        */

    }  // end of while
    #endif
}
void AppGosu::checkVer(void) {
    String in = "checkVer(";
    in = in + E ;
    command(in); 
}
//------- command --------------
void AppGosu::setDelayCmd(int d) {
    delay_cmd = d; 	
}
void AppGosu::cmd(String in) {
   in.trim();
   in = in + ";";
   Serial.print(in);
   delay(delay_cmd); 
}
void AppGosu::command(String in) {
   #ifdef SoftS_app
   Gosu_Uart.print(in);
   #else
   Serial.print(in);
   #endif
   delay(delay_cmd); 
}
void AppGosu::nop(void) {  ///
    String in = "nop(";
    in = in + E ;
    command(in); 
}
void AppGosu::clearAll(void) {  ///
    String in = "clearAll(";
    in = in + E ;
    Serial.print(";");
    delay(100);
    command(in); 
    nop();
}
void AppGosu::background(int r,int g,int b) {
    String in = "background(";
    in = in + r + C + g + C + b + E ;
    command(in); 
}
void AppGosu::fill(int r,int g,int b) {
    String in = "fill(";
    in = in + r + C + g + C + b + E ;
    command(in); 
}
void AppGosu::stroke(int r,int g,int b) {
    String in = "stroke(";
    in = in + r + C + g + C + b + E ;
    command(in); 
}
void AppGosu::noFill(void) {
    String in = "noFill(";
    in = in + E ;
    command(in); 
}
void AppGosu::noStroke(void) {
    String in = "noStroke(";
    in = in + E ;
    command(in); 
}
// Graphic
void AppGosu::textSize(int x) {
    String in = "textSize(";
    in = in + x + E;
    command(in); 
}  
void AppGosu::text(String s,int x,int y) {
    String in = "text(";
    in = in + S1 + s + S2 + C + x + C + y + E;
    command(in); 
}
void AppGosu::textBox(String s,int x,int y,int w,int h,int r,int g,int b) {
    String in = "textBox(";
    in = in + S1 + s + S2 + C + x + C + y + C + w + C + h + C + r + C + g + C + b + E;
    command(in); 
}
void AppGosu::text2(String s,int x,int y) {
    String in = "text2(";
    in = in + S1 + s + S2 + C + x + C + y + E;
    command(in); 
}
void AppGosu::line(int x1,int y1,int x2,int y2) {
    String in = "line(";
    in = in + x1 + C + y1 + C + x2 + C + y2 + E;
    command(in); 
}
void AppGosu::rect(int x,int y,int w,int h) {
    String in = "rect(";
    in = in + x + C + y + C + w+ C + h + E;
    command(in); 
}
void AppGosu::triangle(int x1,int y1,int x2,int y2,int x3,int y3) {
    String in = "triangle(";
    in = in + x1 + C + y1 + C + x2 + C + y2 + C + x3 + C + y3 + E;
    command(in); 
}
void AppGosu::ellipse(int x,int y,int w,int h) {
    String in = "ellipse(";
    in = in + x + C + y + C + w+ C + h + E;
    command(in); 
}
void AppGosu::arcDeg(int x,int y,int w,int h,int st,int sp) {
    String in = "arcDeg(";
    in = in + x + C + y + C + w + C + h + C + st + C + sp + E;
    command(in); 
}
// Multimedia
void AppGosu::image(String s,int x,int y,int w,int h) {
    String in = "image(";
    in = in + S1 + s + S2 + C + x + C + y + C + w + C + h + E;
    command(in); 
}
void AppGosu::imagePath(String s,int x,int y,int w,int h) {
    String in = "1213";
    in = in + C2+  s  + C2 + x + C2 + y + C2 + w + C2 + h + E2;
    command(in); 
}
void AppGosu::loadVideo(String s,int x,int y,int w,int h) {
    String in = "loadVideo(";
    in = in + S1 + s + S2 + C + x + C + y + C + w + C + h + E;
    command(in); 
}
void AppGosu::playVideo(void) {
    String in = "playVideo(";
    in = in + E ;
    command(in); 
}
void AppGosu::stopVideo(void) {
    String in = "stopVideo(";
    in = in + E ;
    command(in); 
}
void AppGosu::sound(String s) {
    String in = "sound(";
    in = in + S1 + s + S2 + E;
    command(in); 
}
void AppGosu::stopSound(void) {  
    String in = "stopSound(";
    in = in + E ;
    command(in); 
}  
// Widget
void AppGosu::makeButton(String s,int x,int y,int w,int h,int id,String ch) {
    String in = "makeButton(";
    in = in + S1 + s + S2 + C + x + C + y + C + w + C + h + C + id + C + S1 + ch + S2 + E;
    command(in); 
} 
void AppGosu::makeButton(String s,int x,int y,int w,int h,int id,char ch) {
    String in = "makeButton(";
    in = in + S1 + s + S2 + C + x + C + y + C + w + C + h + C + id + C + S1 + ch + S2 + E;
    command(in); 
} 
void AppGosu::button(String s,int x,int y,int w,int h,int id) {
     String in = "5011";
     in = in + C2 + s + C2 + x + C2 + y + C2 + w + C2 + h + C2 + id + E2;
     command(in);
}
void AppGosu::clearButton(int id) {
     String in = "5012";
     in = in + C2 + id + E2;
     command(in);
}
void AppGosu::editText(int x,int y,int w,int h,int id) {
     String in = "5031";
     in = in +  C2 + x + C2 + y + C2 + w + C2 + h + C2 + id + E2;
     command(in);
}
void AppGosu::clearEditText(int id) {
     String in = "5032";
     in = in + C2 + id + E2;
     command(in);
}
void AppGosu::imageButton(String s1,String s2, int x,int y,int w,int h,int id) {
     String in = "5051";
     in = in+ C2 + s1 + C2 + s2 + C2 + x + C2 + y + C2 + w + C2 + h + C2 + id + E2;
     command(in);
}
void AppGosu::clearImageButton(int id) {
     String in = "5053";
     in = in + C2 + id + E2;
     command(in);
}
void AppGosu::mousePressRect(int x,int y,int w,int h,int id) {
     String in = "5055";
     in = in +  C2 + x + C2 + y + C2 + w + C2 + h + C2 + id + E2;
     command(in);
}
// Message -----------------------------------------
boolean AppGosu::btConnected(void) {
	if( m_type == 8019 ) {
	      if( m_id == 1 ) {
		clearSerialBuffer();	
                    return(true);   
               }
          }
          return(false);
}
boolean AppGosu::btDisconnected(void) {
	if( m_type == 8018 ) {
		return(true);
	      if( m_id == 1 ) {
		clearSerialBuffer();	
                    return(true);   
               }
          }
          return(false);
}
void AppGosu::serialMessage(void) {
      const int bSize = 40; 
      char buffer[bSize];  // Serial buffer
      char data[30];       // ditto for data size
      char id[10];
      char type[10];
      int byteCount = -1;
      byteCount = -1;
      char *pch;
      byteCount =  Serial.readBytesUntil(';',buffer,bSize); 
      if (byteCount  > 0) {
            pch = strtok(buffer,",");
            strcpy(type,pch);
            //pch = strtok(NULL,",");
            pch = strtok(AGNULL,",");
            strcpy(id,pch);
            if( pch != AGNULL) {
                      pch = strtok(AGNULL,",");
                      strcpy(data,pch);
                      m_data = data;           
            } else { m_data = "_null_"; }
            m_type = atoi(type);
            m_id = atoi(id);   
   }
   memset(buffer, 0, sizeof(buffer));   // Clear contents of Buffer
   Serial.flush();
}
boolean AppGosu::eventButton(int id) {
	if( m_type == 5011 ) {
	      if( m_id == id ) {
		clearSerialBuffer();
                   	return(true);   
               }
          }
          return(false);
}
boolean AppGosu::eventEditText(int id) {
	if( m_type == 5031 ) {
		if( m_id == id) {
			return(true);
		}
	}
	return(false);
}
String AppGosu::messageEditText(int id) {
	if( m_id == id ) {
		m_type = 0;
		m_id = 0;
                    return( m_data);   
	} 
  	return(AppGosu_String);

}
boolean AppGosu::eventImageButton(int id) {
	if( m_type == 5051 ) {
	      if( m_id == id ) {
		clearSerialBuffer();
                   	return(true);   
               }
          }
          return(false);
}
boolean AppGosu::eventMousePressRect(int id) {
	if( m_type == 5055 ) {
	      if( m_id == id ) {
		clearSerialBuffer();
                   	return(true);   
               }
          }
          return(false);
}
// Hardware
void AppGosu::setScale(int s) {
     	String in = "8020";
    	 in = in + C2 + s + E2;
     	command(in);
}
void AppGosu::clearSerialBuffer(void) {
	m_type = 0;
	m_id = 0;
	m_data = "_null_";
          Serial.flush();
}
void AppGosu::btName(String s) {
	String in = "btName(";
	in = in + s + E;
	command(in);
}
void AppGosu::btPIN(int id) {
	String in = "btPIN(";
	in = in + id + E;
	command(in);
}
void AppGosu::bypass(String s) {
	String in = "AppGosu(";
	in = in + s + E;
	command(in);
}
//extern void AppGosu_appBody() __attribute__((weak));
void AppGosu::upLoading(void) {
	String in = "8023,0";
	in = in + E2;
	command(in); 
          // call body 
	AppGosu::appBody();
          in = "8025,0";
	in = in + E2;
	command(in); 
	in = "8027,0";
	in = in + E2;
	command(in); 
          delay(200);
          nop();
}
void AppGosu::MouseX(void) {
	// first send cmd
	String in = "5061,0";
	in = in + E2;
	command(in); 
}
boolean AppGosu::eventMouseX(int id) {
	if( m_type == 5061 ) {
		if( m_id == id) {
	                   	return(true);   
		}
          }
          return(false);
}
int AppGosu::messageMouseX(int id) {
	if( m_id == id ) {
		m_type = 0;
		m_id = 0;
		//char temp[10];
		//clearSerialBuffer();
                    return(m_data.toInt());   
	} 
	return(0); 
}
boolean AppGosu::eventMouseY(int id) {
	if( m_type == 5063 ) {
		if( m_id == id) {
	                   	return(true);   
		}
          }
          return(false);
}
int AppGosu::messageMouseY(int id) {
	if( m_id == id ) {
		m_type = 0;
		m_id = 0;
                    return(m_data.toInt());   
	} 
	return(0); 
}

//====================================
void AppGosu::vibrate(int id) {
     String in = "6011";
     in = in + C2 + id + E2;
     command(in);
     nop();
}
void AppGosu::vibrate(int s,int x1, int x2, int y1, int y2, int z1, int z2 ) {
     String in = "6015";
     in = in +C2 + s + C2 + x1 + C2 + x2 + C2 + y1 + C2 + y2 + C2 + z1 + C2 + z2  + E2;
     command(in);
     nop();
}

void AppGosu::vibrateCancel(void) {
     String in = "6013";
     int id = 0;
     in = in + C2 + id + E2;
     command(in);
}
void AppGosu::textView(String s, int x1, int y1, int y2, int id ) {
     String in = "5071";
     in = in +C2 + s + C2 + x1 + C2 + y1 + C2 + y2 +  C2 + id + E2;
     command(in);
}
void AppGosu::textView(String s, int x1, int y1, int y2, int y3, int id ) {
     String in = "5072";
     in = in +C2 + s + C2 + x1 + C2 + y1 + C2 + y2 +  C2 + y3 + C2 +  id + E2;
     command(in);
}
void AppGosu::textViewSetText(String s,  int id ) {
     String in = "5073";
     in = in +C2 + s + C2  + id + E2;
     command(in);
}
void AppGosu::textViewSetColor(int x1, int x2, int y1, int id ) {
     String in = "5075";
     int y2 = 255;
     in = in +C2 +  x1 + C2 + x2 + C2 + y1 +  C2 +  y2 +  C2  + id + E2;
     command(in);
}
void AppGosu::textViewSetSize(int x1, int id ) {
     String in = "5077";
     in = in +C2 + x1 + C2 + id + E2;
     command(in);
}
void AppGosu::textViewSetAlign(int x1, int id ) {
     String in = "5078";
     in = in +C2 + x1 + C2 + id + E2;
     command(in);
}
void AppGosu::clearTextView(int id ) {
     String in = "5079";
     in = in +C2 + id + E2;
     command(in);
}
void AppGosu::showToast(String s) {
	String in = "5081";
	in = in + C2 + s + E2;
	command(in); 
          nop();
}
void AppGosu::checkBox(String s, int x1, int y1, int y2, int id ) {
     String in = "5091";
     in = in +C2 + s + C2 + x1 + C2 + y1 + C2 + y2 +  C2 + id + E2;
     command(in);
}
boolean AppGosu::eventCheckBox(int id) {
	if( m_type == 5095 ) {
	      if( m_id == id ) {
                   	return(true);   
               }
          }
          return(false);
}
int AppGosu::messageCheckBox(int id) {
	if( m_id == id ) {
		m_type = 0;
		m_id = 0;
                    return( m_data.toInt() );   
	} 
	return(AGNULL); 
}
void AppGosu::switchBox(String s, int x1, int y1, int y2, int id ) {
     String in = "5111";
     in = in +C2 + s + C2 + x1 + C2 + y1 + C2 + y2 +  C2 + id + E2;
     command(in);
}
boolean AppGosu::eventSwitchBox(int id) {
	if( m_type == 5115 ) {
	      if( m_id == id ) {
		//clearSerialBuffer();
                   	return(true);   
               }
          }
          return(false);
}
int AppGosu::messageSwitchBox(int id) {
	if( m_id == id ) {
                    //clearSerialBuffer();
		//Serial.flush();
		m_type = 0;
		m_id = 0;
                    return( m_data.toInt() );   
	} 
	return(AGNULL); 
}
void AppGosu::clearSwitchBox(int id ) {
     String in = "5113";
     in = in +C2 + id + E2;
     command(in);
}
void AppGosu::seekBar(int x1, int y1, int w, int mMax, int mProgress, int id ) {
     String in = "5121";
     in = in +C2 +  x1 + C2 + y1 + C2 + w +  C2 + mMax + C2 + mProgress + C2 + id + E2;
     command(in);
}
boolean AppGosu::eventSeekBar(int id) {
	if( m_type == 5125 ) {
	      if( m_id == id ) {
		//clearSerialBuffer();
                   	return(true);   
               }
          }
          return(false);
}
int AppGosu::messageSeekBar(int id) {
	if( m_id == id ) {
                    //clearSerialBuffer();
		//Serial.flush();
		m_type = 0;
		m_id = 0;
                    return( m_data.toInt() );   
	} 
	return(AGNULL); 
}
void AppGosu::clearSeekBar(int id ) {
     String in = "5123";
     in = in +C2 + id + E2;
     command(in);
}
void AppGosu::setDelayEventSeekBar(int id) {
     String in = "5127";
     in = in + C2 + id + E2;
     command(in);
}
void AppGosu::dialogBox(String str1, String str2, int id ) {
     String in = "5131";
     in = in +C2 +  str1 + C2 + str2 + C2 +  id + E2;
     command(in);
     nop();
}
boolean AppGosu::eventDialogBox(int id) {
	if( m_type == 5133 ) {
	      if( m_id == id ) {
		//clearSerialBuffer();
                   	return(true);   
               }
          }
          return(false);
}
int AppGosu::messageDialogBox(int id) {
	if( m_id == id ) {
                    //clearSerialBuffer();
		//Serial.flush();
		m_type = 0;
		m_id = 0;
                    return( m_data.toInt() );   
	} 
	return(AGNULL); 
}
void AppGosu::numberPicker(int x, int id ) {
     String in = "5141";
     in = in +C2 +  x + C2 +  id + E2;
     command(in);
     nop();
}
boolean AppGosu::eventNumberPicker(int id) {
	if( m_type == 5143 ) {
	      if( m_id == id ) {
		//clearSerialBuffer();
                   	return(true);   
               }
          }
          return(false);
}
int AppGosu::messageNumberPicker(int id) {
	if( m_id == id ) {
		m_type = 0;
		m_id = 0;
                    return( m_data.toInt() );   
	} 
	return(AGNULL); 
}
// end of file
// by AppGosu    
// www.AppGosu.com


