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


#ifdef __APPLE__

#include <iostream>

//quartz CG... stuff
#include <ApplicationServices/ApplicationServices.h>

//sleep
#include <unistd.h>

#include "xinputsimulatorimplmacos.h"
#include "notimplementedexception.h"



XInputSimulatorImplMacOs::XInputSimulatorImplMacOs()
{
    //TODO
    //this->initCurrentMousePosition();

    this->currentX = 500;
    this->currentY = 500;
}

//void XInputSimulatorImplMacOs::initMouseEvent(int button)
//{

//}

void XInputSimulatorImplMacOs::initCurrentMousePosition()
{
    throw NotImplementedException();
}

void XInputSimulatorImplMacOs::mouseMoveTo(int x, int y)
{

    CGEventRef mouseEv = CGEventCreateMouseEvent(
                NULL, kCGEventMouseMoved,
                CGPointMake(x, y),
                kCGMouseButtonLeft);

    std::cout << "mv: " << mouseEv << std::endl;

    CGEventPost(kCGHIDEventTap, mouseEv);

    CFRelease(mouseEv);

    this->currentX = x;
    this->currentY = y;
}

void XInputSimulatorImplMacOs::mouseMoveRelative(int x, int y)
{
    int newX = this->currentX + x;
    int newY = this->currentY + y;

    std::cout << "newx: " << newX << " newy: " << newY << std::endl;

    CGEventRef mouseEv = CGEventCreateMouseEvent(
                NULL, kCGEventMouseMoved,
                CGPointMake(newX, newY),
                kCGMouseButtonLeft);

    CGEventPost(kCGHIDEventTap, mouseEv);

    CFRelease(mouseEv);

    this->currentX = newX;
    this->currentY = newY;
}

//TODO use the button from parameter list
void XInputSimulatorImplMacOs::mouseDown(int button)
{
    CGEventRef mouseEv = CGEventCreateMouseEvent(
                NULL, kCGEventLeftMouseDown,
                CGPointMake(this->currentX, this->currentY),
                kCGMouseButtonLeft); // use int buttn from parameter

    CGEventPost(kCGHIDEventTap, mouseEv);

    CFRelease(mouseEv);

}

//TODO use the button from parameter list
void XInputSimulatorImplMacOs::mouseUp(int button)
{
    CGEventRef mouseEv = CGEventCreateMouseEvent(
                NULL, kCGEventLeftMouseUp,
                CGPointMake(this->currentX, this->currentY),
                kCGMouseButtonLeft); // use int buttn from parameter

    CGEventPost(kCGHIDEventTap, mouseEv);

    CFRelease(mouseEv);
}

void XInputSimulatorImplMacOs::mouseClick(int button)
{
    //throw NotImplementedException();
    this->mouseDown(button);
    this->mouseUp(button);
}
//kajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjf
void XInputSimulatorImplMacOs::mouseScrollX(int length)
{
    int scrollDirection = -1; // 1 left -1 right

    if(length < 0){
        length *= -1;
        scrollDirection *= -1;
    }

    //length *= 100;

    for(int cnt = 0; cnt < length; cnt++){

        std::cout << "scroll y mac" << std::endl;

        CGEventRef scrollEv = CGEventCreateScrollWheelEvent (
                    NULL, kCGScrollEventUnitLine,  // kCGScrollEventUnitLine  //kCGScrollEventUnitPixel
                    2, //CGWheelCount 1 = y 2 = xy 3 = xyz
                    0,
                    scrollDirection); // length of scroll from -10 to 10 higher values lead to undef behaviour

        CGEventPost(kCGHIDEventTap, scrollEv);

        CFRelease(scrollEv);
        //sleep(1);
    }
}

void XInputSimulatorImplMacOs::mouseScrollY(int length)
{
    int scrollDirection = -1; // 1 down -1 up

    if(length < 0){
        length *= -1;
        scrollDirection *= -1;
    }

    //length *= 100;

    for(int cnt = 0; cnt < length; cnt++){

        std::cout << "scroll y mac" << std::endl;

        CGEventRef scrollEv = CGEventCreateScrollWheelEvent (
                    NULL, kCGScrollEventUnitLine,  // kCGScrollEventUnitLine  //kCGScrollEventUnitPixel
                    1, //CGWheelCount 1 = y 2 = xy 3 = xyz
                    scrollDirection); // length of scroll from -10 to 10 higher values lead to undef behaviour

        CGEventPost(kCGHIDEventTap, scrollEv);

        CFRelease(scrollEv);
        //sleep(1);
    }
}

void XInputSimulatorImplMacOs::keyDown(int key)
{
    throw NotImplementedException();
}

void XInputSimulatorImplMacOs::keyUp(int key)
{
    throw NotImplementedException();
}

void XInputSimulatorImplMacOs::keyClick(int key)
{
    throw NotImplementedException();
}

int XInputSimulatorImplMacOs::charToKeyCode(char key_char)
{
    throw NotImplementedException();
}
void XInputSimulatorImplMacOs::keySequence(const std::string &sequence)
{
    throw NotImplementedException();
}

#endif //apple
