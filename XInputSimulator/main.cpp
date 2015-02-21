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

#ifdef __linux__
//sleep
#include <unistd.h>
#elif __APPLE__
//sleep
#include <unistd.h>
#elif _WIN32
//sleep
#include <windows.h>
#endif

using namespace std;

void waitABit();

int main()
{
    cout << "Hello World!" << endl;

    XInputSimulator &sim = XInputSimulator::getInstance();

    waitABit();
    sim.mouseMoveTo(500,400);
    waitABit();
    sim.mouseMoveRelative(400, -100);
    waitABit();
    sim.mouseDown(XIS::LEFT_MOUSE_BUTTON);
    waitABit();
    sim.mouseMoveRelative(0, 300);
    waitABit();
    sim.mouseUp(XIS::LEFT_MOUSE_BUTTON);
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

#if defined(__linux__) || defined(__APPLE__)
	char anA = 'a';
    cout << "a: " << (int)anA << " " << sim.charToKeyCode(anA) << endl;
    std::cout << std::endl;
    waitABit();
    sim.keyClick(sim.charToKeyCode(anA));
    std::cout << std::endl;
    waitABit();
    sim.keySequence(" Simple sentence Here 123 ");
#elif _WIN32
	//not implemented
#endif


    waitABit();
    return 0;
}

void waitABit()
{
    //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
#ifdef __linux__
	sleep(1);
#elif __APPLE__
	sleep(1);
#elif _WIN32
	Sleep(1000);
#endif
    
}
