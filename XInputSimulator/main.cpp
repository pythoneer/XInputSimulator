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

#include <iostream>
#include "xinputsimulator.h"

#include <chrono>
#include <thread>

using namespace std;

void waitABit();

int main()
{
    cout << "Hello World!" << endl;

    XInputSimulator &sim = XInputSimulator::getInstance();
    sim.mouseMoveTo(500,400);
    waitABit();
    sim.mouseMoveRelative(400, -100);
    waitABit();
    sim.mouseDown(1);
    waitABit();
    sim.mouseMoveRelative(0, 300);
    waitABit();
    sim.mouseUp(1);
    waitABit();
    //scroll down and up
    sim.mouseScrollY(10);
    waitABit();
    sim.mouseScrollY(-10);
    //scroll left and right
    waitABit();
    sim.mouseScrollX(10);
    waitABit();
    sim.mouseScrollX(-10);

    return 0;
}

void waitABit()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
