/*
AppGosu :: Arduino-Android Library  ver. 2.0
By AppGosu.com
Updated : 2014-10-10
License : BSD
More information : Please visit    www.AppGosu.com
*/ 


#ifndef _AppGosu_H_INCLUDED
#define _AppGosu_H_INCLUDED

#include <Arduino.h>
// for SoftSerial only --------------------
//#define SoftS_app  // if u use softSerial, delete '//'

#ifdef SoftS_app
#include <SoftwareSerial.h>
#define _RX_PIN   2
#define _TX_PIN   3
#endif

//------------------------------------------
#define appgosu_buf_size 100

class AppGosu {

  //public:
  private:
    unsigned int delay_cmd;
    //unsigned long delay_cmd;
    char _data[appgosu_buf_size];  // send data buffer
    int tx_pin;
    int rx_pin;
    long baudRate;
    //boolean soft_serial;
    //String C = ", ";
    //String E = ")";
    String C, C2, E, E2, S1, S2;

  public:
    int m_type;
    int m_id;
    String m_data; 

  private:
    void clearSerialBuffer(void);
    void AppGosu_var_init(void);

  public:
    
    AppGosu(void);
    AppGosu(int, int);
    void start(void);
    void start(long baud);
    void btWaiting(void);
    void checkVer(void);
    // command
    void cmd(String);
    void command(String);
    void nop(void);
    void clearAll(void);
    // Color
    void background(int,int,int);
    void fill(int,int,int);
    void stroke(int,int,int);
    void noFill(void);
    void noStroke(void);
    // Graphic
    void textSize(int);
    void text(String,int,int);
    void textBox(String,int,int,int,int,int,int,int);
    void text2(String,int,int);
    void line(int,int,int,int);
    void rect(int,int,int,int);
    void triangle(int,int,int,int,int,int);
    void ellipse(int,int,int,int);
    void arcDeg(int,int,int,int,int,int);
    // Multimedia
    void image(String,int,int,int,int);
    void imagePath(String,int,int,int,int);
    void loadVideo(String,int,int,int,int);
    void playVideo(void);
    void stopVideo(void);
    void sound(String);
    void stopSound(void);
    // Widget
    void makeButton(String,int,int,int,int,int,String);
    void makeButton(String,int,int,int,int,int,char);
    void button(String,int,int,int,int,int);
    void clearButton(int);
    void editText(int,int,int,int,int); 
    void clearEditText(int); 
    void imageButton(String,String,int,int,int,int,int);
    void clearImageButton(int);
    void mousePressRect(int,int,int,int,int);
    // Hardware
    void setDelayCmd(int d);
    void setScale(int);
    boolean btConnected(void);
    void btName(String);
    void btPIN(int);
    void bypass(String);
    // Message
    void serialMessage(void);
    boolean eventButton(int);
    boolean eventEditText(int);
    String messageEditText(int);
    boolean eventImageButton(int);
    boolean eventMousePressRect(int);
    void upLoading(void);
    void appBody(void);
    boolean btDisconnected(void);
    boolean eventMouseX(int);
    int messageMouseX(int);
    void MouseX(void); 
    boolean eventMouseY(int);
    int messageMouseY(int);
    void vibrate(int);
    void vibrate(int,int, int, int, int, int, int);
    void vibrateCancel(void);
    void textView(String, int, int, int, int );
    void textView(String, int, int, int, int, int );
    void textViewSetText(String s,  int id );
    void textViewSetColor(int, int, int, int);
    void textViewSetSize(int,  int);
    void textViewSetAlign(int,  int);
    void clearTextView(int);
    void showToast(String s); 
    void checkBox(String s, int x1, int y1, int y2, int id );
    boolean eventCheckBox(int id);
    int messageCheckBox(int id);
    void clearCheckBox(int id ); 
    void switchBox(String s, int x1, int y1, int y2, int id );
    boolean eventSwitchBox(int id);
    int messageSwitchBox(int id);
    void clearSwitchBox(int id );
    void seekBar(int x1, int y1, int w, int mMax, int mProgress, int id );
    boolean eventSeekBar(int id);
    int messageSeekBar(int id);
    void setDelayEventSeekBar(int id);
    void clearSeekBar(int id );
    void setDelayEvent(int id);  // defaule : 10
    void dialogBox(String str1, String str2, int id ); 
    boolean eventDialogBox(int id);
    int messageDialogBox(int id);
    void numberPicker(int x, int id );
    boolean eventNumberPicker(int id);
    int messageNumberPicker(int id);

};


#endif


