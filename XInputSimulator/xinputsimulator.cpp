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

#include "xinputsimulator.h"


//*************************************************//
//******************M O U S E**********************//
//*************************************************//
void XInputSimulator::mouseMoveTo(int x, int y)
{
    implementation->mouseMoveTo(x, y);
}

void XInputSimulator::mouseMoveRelative(int x, int y)
{
    implementation->mouseMoveRelative(x, y);
}

void XInputSimulator::mouseDown(int button)
{
    implementation->mouseDown(button);
}

void XInputSimulator::mouseUp(int button)
{
    implementation->mouseUp(button);
}

void XInputSimulator::mouseClick(int button)
{
    implementation->mouseClick(button);
}

void XInputSimulator::mouseScrollX(int length)
{
    implementation->mouseScrollX(length);
}

void XInputSimulator::mouseScrollY(int length)
{
    implementation->mouseScrollY(length);
}

//*************************************************//
//***************K E Y B O A R D*******************//
//*************************************************//

void XInputSimulator::keyDown(int key)
{
    implementation->keyDown(key);
}

void XInputSimulator::keyUp(int key)
{
    implementation->keyUp(key);
}

void XInputSimulator::keyClick(int key)
{
    implementation->keyClick(key);
}

int XInputSimulator::charToKeyCode(char key_char)
{
    return implementation->charToKeyCode(key_char);
}

void XInputSimulator::keySequence(const std::string &sequence)
{
    implementation->keySequence(sequence);
}
