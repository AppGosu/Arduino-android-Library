/*
AppGosu :: Arduino-Android Library
By AppGosu.com
Updated : 2014-03-04
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



AppGosu::AppGosu(void) {
    delay_cmd = 50;  // app execution speed (depending on your smart phone)
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
    //N = ";";
    //Serial.begin(baudRate);
    //Serial.begin(9600);
    //soft_serial = false;
}
AppGosu::AppGosu(int r, int t) {
    delay_cmd = 50;
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
    //soft_serial = true;
    //SoftwareSerial SoftSerial(rx_pin, tx_pin);	
}
void AppGosu::start(long baud) {
   //if(SoftS == 1) { Serial.begin(baud); }
   //if(SoftS == 0) { Serial.begin(baud); }
   
   #ifdef SoftS_app
   Gosu_Uart.begin(baud);
   #else
   Serial.begin(baud);
   #endif
   
   delay(300);
   //Serial.print(";");
}
void AppGosu::start(void) {
   //if(soft_serial == false) { Serial.begin(baudRate); }
   //else { SoftSerial.begin(baudRate); }
   #ifdef SoftS_app
   Gosu_Uart.begin(baudRate);
   #else
   Serial.begin(baudRate);
   #endif

  //Serial.begin(baudRate);
  /*
   if(soft_serial == false) Serial.begin(baudRate);
   if(soft_serial == true) {
       //SoftwareSerial SWserial(rx_pin, tx_pin);
       //SWserial.begin(baudRate);
   }
   */
   delay(300);
   //nop();
   //nop();
   //nop();
   //nop();
   //nop();
   //nop();
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
   //in.trim();
   //in = in + ";";
   
   //if(soft_serial == false) { Serial.print(in); }
   //else { SoftSerial.print(in); }

   #ifdef SoftS_app
   Gosu_Uart.print(in);
   #else
   Serial.print(in);
   #endif

   //Serial.print(in);
   delay(delay_cmd); 
}
void AppGosu::nop(void) {  ///
    String in = "nop(";
    in = in + E ;
    command(in); 
    //Serial.print("nop()");
    //Serial.print("noFill()");
    //delay(delay_cmd); 
}
void AppGosu::clearAll(void) {  ///
    String in = "clearAll(";
    in = in + E ;
    Serial.print(";");
    delay(100);
    command(in); 
    //clearSerialBuffer();
    //Serial.print("nop()");
    //Serial.print("noFill()");
    //delay(delay_cmd); 
}
void AppGosu::background(int r,int g,int b) {
    String in = "background(";
    in = in + r + C + g + C + b + E ;
    //cmd(in);
    command(in); 
}
void AppGosu::fill(int r,int g,int b) {
    String in = "fill(";
    in = in + r + C + g + C + b + E ;
    //cmd(in);
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
/*
void AppGosu::line(int x1,int y1,int x2,int y2) {
     String in = "1311";
     in = in +  C2 + x1 + C2 + y1 + C2 + x2 + C2 + y2 +  E2;
     command(in);
}
*/
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

            pch = strtok(NULL,",");
            strcpy(id,pch);

            if( pch != NULL) {
                      pch = strtok(NULL,",");
                      strcpy(data,pch);
                      m_data = data;           
            } else { m_data = "_null_"; }

            //pch = strtok(NULL,",");
            //
            m_type = atoi(type);
            m_id = atoi(id);   
            //m_data = data;           
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
                    //clearSerialBuffer();
		//Serial.flush();
		m_type = 0;
		m_id = 0;
                    return( m_data);   
	} 
	return(NULL); 
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
	// 
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
void AppGosu::byPass(String s) {
	String in = "AppGosu(";
	in = in + s + E;
	command(in);
}
//+++++    test +++++//
void AppGosu::Ttext(String s,int x,int y) {
	String in = "1019";
	in = in + C2 + s + C2  + x + C2 + y + E2;
	command(in); 
}


