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

#ifndef XINPUTSIMULATOR_H
#define XINPUTSIMULATOR_H

#include <memory>
#include <iostream>
#include <stdexcept>

class XInputSimulator
{
private:
    class XInputSimulatorImpl *implementation;

    XInputSimulator(){}

public:
    XInputSimulator(XInputSimulator&) = delete;
    void operator=(XInputSimulator&) = delete;

    ~XInputSimulator();

    static XInputSimulator & getInstance();

    void mouseMoveTo(int x, int y);
    void mouseMoveRelative(int x, int y);
    void mouseDown(int button);
    void mouseUp(int button);
    void mouseClick(int button);
    void mouseScrollX(int length);
    void mouseScrollY(int length);

    void keyDown(int key);
    void keyUp(int key);
    void keyClick(int key);

    int charToKeyCode(char key_char);
    void keySequence(const std::string &sequence);

    // mouse
    static const int LEFT_MOUSE_BUTTON = 1;
    static const int RIGHT_MOUSE_BUTTON = 2;
    static const int MIDDLE_MOUSE_BUTTON = 3;
};

typedef XInputSimulator XIS;


class NotImplementedException : public std::runtime_error
{
public:
    NotImplementedException();
};


#endif // XINPUTSIMULATOR_H
