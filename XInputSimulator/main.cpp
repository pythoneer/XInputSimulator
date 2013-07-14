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

int main()
{
    cout << "Hello World!" << endl;

    XInputSimulator &sim = XInputSimulator::getInstance();
    sim.mouseMoveTo(100,200);
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    sim.mouseMoveRelative(400, -100);

    return 0;
}

