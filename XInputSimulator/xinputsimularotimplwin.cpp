
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

#include "xinputsimularotimplwin.h"
#include "notimplementedexception.h"
#include <iostream>

XInputSimularotImplWin::XInputSimularotImplWin()
{
}


void XInputSimularotImplWin::mouseMoveTo(int x, int y)
{
    std::cout << "move the mouse!\n";
}

void XInputSimularotImplWin::mouseMoveRelative(int x, int y)
{
    throw NotImplementedException();
}

void XInputSimularotImplWin::mouseDown(int button)
{
    throw NotImplementedException();
}

void XInputSimularotImplWin::mouseUp(int button)
{
    throw NotImplementedException();

}

void XInputSimularotImplWin::mouseClick(int button)
{
    throw NotImplementedException();
    this->mouseDown(button);
    //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    this->mouseUp(button);
}
//kajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjf
void XInputSimularotImplWin::mouseScrollX(int length)
{
    throw NotImplementedException();
}

void XInputSimularotImplWin::mouseScrollY(int length)
{
    throw NotImplementedException();
}

void XInputSimularotImplWin::keyDown(int key)
{
    throw NotImplementedException();
}

void XInputSimularotImplWin::keyUp(int key)
{
    throw NotImplementedException();
}

#endif //win
