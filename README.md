XInputSimulator
===============

Cross (X) Plattform (Linux/Mac/Win) Simulator for input devices to simulate mouse moves/clicks/scrolls or keyboard keystrokes.
####How to use
For a detailed example see main.cpp
```cpp
  sim.mouseMoveTo(500,400);         //set mouse to screen cords 500x400
  sim.mouseMoveRelative(400, -100); //move frome there 400px in x to the right and -100px in y upwards
  sim.mouseDown(1);                 //press left mouse and hold
  sim.mouseMoveRelative(0, 300);    //drag/mark with pressed mousebutton 300px down
  sim.mouseUp(1);                   //release the mousebutton press
```
This program is published under the terms of the LGPL (http://www.gnu.org/licenses/)


####Status
2013-07-14: only the Linux part with following functions
```cpp
mouseMoveTo  
mouseMoveRelative  
mouseDown  
mouseUp  
mouseClick  
```
