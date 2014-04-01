Arduino-android-Library
==============
Only arduino IDE, no eclipse, no android SDK (make your own app!)

Arduino-android-Library for AppGosu

Design your own android app using this library.

no eclipse, no android SDK

only Arduino IDE

-------------------------


Features
-------------
- Arduino-android library

Software dependencies:
- Arduino IDE
- "**AppGosu for Android shield**" app from google play
- No eclipse, No android SDK


Hardware dependencies : 
* Arduino UNO, Leonardo, Due, Micro, Mega 2560, Mini, Nano etc
* Android smart phone (on android 4.0.3 or higher)
* **AppGosu ADK : Arduino-Android-Shield Module**
 

Code example
--------------
```java
#include "AppGosu.h"
AppGosu app;

void setup() {
   app.start();
   app.clearAll();
   
   app.textSize(50);
   app.text("ABC", 10, 100);
   app.line(20, 150, 200, 150);
   app.rect(30, 180, 100, 100);
}

```

![result](http://4.bp.blogspot.com/-mb_H962BjRQ/UwB4Q44ZAiI/AAAAAAAAAB8/ZgrN0U6mDV0/s1600/concept1.png)


More information
----------------
  www.appgosu.com
 
  www.embeddedapp.com 
