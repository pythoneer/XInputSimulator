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

#ifndef XINPUTSIMULATORIMPL_H
#define XINPUTSIMULATORIMPL_H

#include <iostream>

class XInputSimulatorImpl
{
public:
    XInputSimulatorImpl();
    virtual ~XInputSimulatorImpl(){}

    virtual void mouseMoveTo(int x, int y) = 0;
    virtual void mouseMoveRelative(int x, int y) = 0;
    virtual void mouseDown(int button) = 0;
    virtual void mouseUp(int button) = 0;
    virtual void mouseClick(int button) = 0;
    virtual void mouseScrollX(int length) = 0;
    virtual void mouseScrollY(int length) = 0;


    virtual void keyDown(int key) = 0;
    virtual void keyUp(int key) = 0;
    virtual void keyClick(int key) = 0;

    virtual int charToKeyCode(char key_char) = 0;
    virtual void keySequence(const std::string &sequence) = 0;

};

#endif // XINPUTSIMULATORIMPL_H
