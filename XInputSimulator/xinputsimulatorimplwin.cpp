
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

#ifdef _WIN32

#include "xinputsimulatorimplwin.h"
#include "notimplementedexception.h"
#include <iostream>

#include <Windows.h>

#define MOUSEEVENTF_HWHEEL 0x01000

XInputSimulatorImplWin::XInputSimulatorImplWin()
{
    this->initCurrentMousePosition();
}

void XInputSimulatorImplWin::initCurrentMousePosition()
{
    POINT p;
    if (GetCursorPos(&p))
    {
        this->currentX = p.x;
        this->currentY = p.y;
    }
}

void XInputSimulatorImplWin::mouseMoveTo(int x, int y)
{
    SetCursorPos(x, y);

    this->currentX = x;
    this->currentY = y;
}

void XInputSimulatorImplWin::mouseMoveRelative(int x, int y)
{
    int newX = this->currentX + x;
    int newY = this->currentY + y;

    SetCursorPos(newX, newY);

    this->currentX = newX;
    this->currentY = newY;
}

//TODO use the button from parameter list
void XInputSimulatorImplWin::mouseDown(int button)
{
    INPUT in={0};
    in.type = INPUT_MOUSE;
    in.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1,&in,sizeof(INPUT));
    ZeroMemory(&in,sizeof(INPUT));
}

//TODO use the button from parameter list
void XInputSimulatorImplWin::mouseUp(int button)
{
    INPUT in={0};
    in.type = INPUT_MOUSE;
    in.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1,&in,sizeof(INPUT));
    ZeroMemory(&in,sizeof(INPUT));
}

//TODO use the button from parameter list
void XInputSimulatorImplWin::mouseClick(int button)
{
    this->mouseDown(button);
    //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    this->mouseUp(button);
}
//kajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjf
void XInputSimulatorImplWin::mouseScrollX(int length)
{
    int scrollDirection = 1 * 50; // 1 left -1 right

    if(length < 0){
        length *= -1;
        scrollDirection *= -1;
    }

    for(int cnt = 0; cnt < length; cnt++)
    {
        INPUT in;
        in.type = INPUT_MOUSE;
        in.mi.dx = 0;
        in.mi.dy = 0;
        in.mi.dwFlags = MOUSEEVENTF_HWHEEL;
        in.mi.time = 0;
        in.mi.dwExtraInfo = 0;
        in.mi.mouseData = scrollDirection;// WHEEL_DELTA;
        SendInput(1,&in,sizeof(in));
    }
}

void XInputSimulatorImplWin::mouseScrollY(int length)
{
    int scrollDirection = -1 * 50; // 1 up -1 down

    if(length < 0){
        length *= -1;
        scrollDirection *= -1;
    }

    for(int cnt = 0; cnt < length; cnt++)
    {
        INPUT in;
        in.type = INPUT_MOUSE;
        in.mi.dx = 0;
        in.mi.dy = 0;
        in.mi.dwFlags = MOUSEEVENTF_WHEEL;
        in.mi.time = 0;
        in.mi.dwExtraInfo = 0;
        in.mi.mouseData = scrollDirection;// WHEEL_DELTA;
        SendInput(1,&in,sizeof(in));
    }
}

void XInputSimulatorImplWin::keyDown(int key)
{
    throw NotImplementedException();
}

void XInputSimulatorImplWin::keyUp(int key)
{
    throw NotImplementedException();
}

void XInputSimulatorImplWin::keyClick(int key)
{
    throw NotImplementedException();
}

int XInputSimulatorImplWin::charToKeyCode(char key_char)
{
    throw NotImplementedException();
}
void XInputSimulatorImplWin::keySequence(const std::string &sequence)
{
    throw NotImplementedException();
}

#endif //win
