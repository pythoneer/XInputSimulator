XInputSimulator
===============

Cross (X) Plattform (Linux/Mac/Win) Simulator for input devices to simulate mouse moves/clicks/scrolls or keyboard keystrokes.  

[![Build Status](https://travis-ci.org/pythoneer/XInputSimulator.svg?branch=master)](https://travis-ci.org/pythoneer/XInputSimulator)
  
This program is published under the terms of the LGPL (http://www.gnu.org/licenses/)
####How to use
For a detailed example see main.cpp
```cpp
  XInputSimulator &sim = XInputSimulator::getInstance();

  sim.mouseMoveTo(500,400);                           //set mouse to screen cords 500x400
  sim.mouseMoveRelative(400, -100);                   //move frome there 400px in x to the right and -100px in y upwards
  sim.mouseDown(XInputSimulator::LEFT_MOUSE_BUTTON);  //press left mouse and hold
  sim.mouseMoveRelative(0, 300);                      //drag/mark with pressed mousebutton 300px down
  sim.mouseUp(XInputSimulator::LEFT_MOUSE_BUTTON);    //release the mousebutton press
```
  
building for Linux use -lX11 -lXtst  
building for Mac use -framework ApplicationServices Carbon CoreFoundation  
building for Win use User32.lib  

for cmake there is a CMakeLists.txt file -simply type (for all platforms):
```
>$ mkdir build
>$ cd build
>$ cmake ../XInputSimulator/
>$ cmake --build .
```

for xcode you can generate a project by
```
>$ mkdir build
>$ cd build
>$ cmake -G Xcode ../XInputSimulator/
```

####Status early Alpha
2013-07-16: Linux, Mac and Win part with following functions
```cpp
mouseMoveTo  
mouseMoveRelative  
mouseDown  
mouseUp  
mouseClick  
mouseScrollY  //up and down
mouseScrollX  //left an right
```

be aware that some glitches might appear and the interface might be changing every minute due to the early state of development. There is not much testing going on apart from the main.cpp. Feel free to file bugreports, wishes or patches :)
