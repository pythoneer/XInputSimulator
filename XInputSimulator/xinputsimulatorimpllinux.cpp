#include "xinputsimulatorimpllinux.h"
#include "notimplementedexception.h"
#include <iostream>

XInputSimulatorImplLinux::XInputSimulatorImplLinux()
{
}

void XInputSimulatorImplLinux::mouseMoveTo(int x, int y)
{
    std::cout << "move the mouse!\n";
}

void XInputSimulatorImplLinux::mouseMoveRelative(int x, int y)
{
    throw NotImplementedException();
}

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

void XInputSimulatorImplLinux::mouseDown(int button)
{
    throw NotImplementedException();
}

void XInputSimulatorImplLinux::mouseUp(int button)
{
    throw NotImplementedException();
}

void XInputSimulatorImplLinux::mouseClick(int button)
{
    throw NotImplementedException();
}

void XInputSimulatorImplLinux::mouseScrollX(int length)
{
    throw NotImplementedException();
}

void XInputSimulatorImplLinux::mouseScrollY(int length)
{
    throw NotImplementedException();
}

void XInputSimulatorImplLinux::keyDown(int key)
{
    throw NotImplementedException();
}

void XInputSimulatorImplLinux::keyUp(int key)
{
    throw NotImplementedException();
}
