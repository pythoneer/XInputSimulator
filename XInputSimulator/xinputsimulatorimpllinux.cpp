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

#include <unistd.h> //usleep

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

    Screen* pscr = DefaultScreenOfDisplay( display );

    this->displayX = pscr->width;
    this->displayY = pscr->height;

    //XCloseDisplay( pdsp );
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
    XTestFakeButtonEvent(display, button, true, CurrentTime);
    XFlush(display);
}

void XInputSimulatorImplLinux::mouseUp(int button)
{
    XTestFakeButtonEvent(display, button, false, CurrentTime);
    XFlush(display);
}

void XInputSimulatorImplLinux::mouseClick(int button)
{
    this->mouseDown(button);
    usleep(100);
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
    XTestFakeKeyEvent(display, key, True, 0);
    XFlush(display);
}

void XInputSimulatorImplLinux::keyUp(int key)
{
    XTestFakeKeyEvent(display, key, False, 0);
    XFlush(display);
}

void XInputSimulatorImplLinux::keyClick(int key)
{
    std::cout << "key click: " << key << std::endl;

    this->keyDown(key);
    this->keyUp(key);
}

int XInputSimulatorImplLinux::charToKeyCode(char key_char)
{
    std::cout << "cchar: " << (int)key_char << std::endl;

    int keyCode = XKeysymToKeycode(display, key_char);
//    int keyCode = XKeysymToKeycode(display, XStringToKeysym(&key_char));
    std::cout << "ccode: " << keyCode << std::endl;

    return keyCode;
}
void XInputSimulatorImplLinux::keySequence(const std::string &sequence)
{
    std::cout << "key seq: " << sequence << std::endl;

    for(const char c : sequence) {
        std::cout << "cahr: " << c << std::endl;
        int keyCode = this->charToKeyCode(c);
        std::cout << "key code: " << keyCode << std::endl;

        if (isupper(c)) {
            std::cout << "upper " << c << std::endl;

            this->keyDown(XKeysymToKeycode(display, XK_Shift_L));
            this->keyClick(keyCode);
            this->keyUp(XKeysymToKeycode(display, XK_Shift_L));
        }
        else {
            this->keyClick(keyCode);
        }


        std::cout << std::endl;
    }

}


#endif // linux
