//    Copyright 2013 Dustin Bensing

//    This file is part of XInputSimulator.

//    XInputSimulator is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Lesser Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    any later version.

//    XInputSimulator is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU Lesser Public License for more details.

//    You should have received a copy of the GNU Lesser Public License
//    along with XInputSimulator.  If not, see <http://www.gnu.org/licenses/>.

#ifdef __linux__

#include "xinputsimulatorimpllinux.h"
#include "notimplementedexception.h"
#include <iostream>

//memset
#include <stdio.h>
#include <cstring>

XInputSimulatorImplLinux::XInputSimulatorImplLinux()
{
    if((display = XOpenDisplay(NULL)) == NULL) {
        std::cout << "can not access display server!" << std::endl;
            return;
    }

    root = DefaultRootWindow(display);
}

void XInputSimulatorImplLinux::initMouseEvent(int button)
{
    event.xbutton.button = button; //which button
    event.xbutton.same_screen = True;
    event.xbutton.subwindow = DefaultRootWindow(display);
    while (event.xbutton.subwindow)
    {
        event.xbutton.window = event.xbutton.subwindow;
        XQueryPointer(display, event.xbutton.window,
                      &event.xbutton.root, &event.xbutton.subwindow,
                      &event.xbutton.x_root, &event.xbutton.y_root,
                      &event.xbutton.x, &event.xbutton.y,
                      &event.xbutton.state);
    }
}

void XInputSimulatorImplLinux::mouseMoveTo(int x, int y)
{
    if(!display){
        return;
    }

    XWarpPointer(display, None, root, 0, 0, 0, 0, x, y);
    XFlush(display);


    XEvent event;
    memset(&event, 0, sizeof (event));
}

void XInputSimulatorImplLinux::mouseMoveRelative(int x, int y)
{
    if(!display){
        return;
    }

    XWarpPointer(display, None, None, 0, 0, 0, 0, x, y);
    XFlush(display);
}

void XInputSimulatorImplLinux::mouseDown(int button)
{
    this->initMouseEvent(button);

    event.type = ButtonPress;
    if (XSendEvent(display, PointerWindow, True, ButtonPressMask, &event) == 0)
        std::cout << "Error to send the event!\n";
    XFlush(display);
}

void XInputSimulatorImplLinux::mouseUp(int button)
{
    this->initMouseEvent(button);

    event.type = ButtonRelease;
    if (XSendEvent(display, PointerWindow, True, ButtonReleaseMask, &event) == 0)
       std::cout <<  "Error to send the event!\n";
    XFlush(display);
}

void XInputSimulatorImplLinux::mouseClick(int button)
{
    this->mouseDown(button);
    this->mouseUp(button);
}
//kajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjf
void XInputSimulatorImplLinux::mouseScrollX(int length)
{
    int button;
    if(length < 0){
        button = 6;  //scroll left button
    }else{
        button = 7;  //scroll right button
    }

    if(length < 0){
        length *= -1;
    }

    for(int cnt = 0; cnt < length; cnt++){
        this->mouseDown(button);
        this->mouseUp(button);
    }
}

void XInputSimulatorImplLinux::mouseScrollY(int length)
{
    int button;
    if(length < 0){
        button = 4;  //scroll up button
    }else{
        button = 5;  //scroll down button
    }

    if(length < 0){
        length *= -1;
    }

    for(int cnt = 0; cnt < length; cnt++){
        this->mouseDown(button);
        this->mouseUp(button);
    }
}

void XInputSimulatorImplLinux::keyDown(int key)
{
    throw NotImplementedException();
}

void XInputSimulatorImplLinux::keyUp(int key)
{
    throw NotImplementedException();
}

void XInputSimulatorImplLinux::keyClick(int key)
{
    throw NotImplementedException();
}

void XInputSimulatorImplLinux::charToKeyCode(char key_char)
{
    throw NotImplementedException();
}
void XInputSimulatorImplLinux::keySequence(const std::string &sequence)
{
    throw NotImplementedException();
}


#endif // linux
