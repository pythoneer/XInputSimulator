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

#ifndef XINPUTSIMULATORIMPLMACOS_H
#define XINPUTSIMULATORIMPLMACOS_H

#include <CoreFoundation/CoreFoundation.h>
#include <CoreGraphics/CoreGraphics.h>
#include <Carbon/Carbon.h> /* For kVK_ constants, and TIS functions. */

#include "xinputsimulatorimpl.h"

class XInputSimulatorImplMacOs : public XInputSimulatorImpl
{
private:
    int currentX;
    int currentY;

    size_t displayX;
    size_t displayY;

    void initCurrentMousePosition();
    CFStringRef createStringForKey(CGKeyCode keyCode);

public:
    XInputSimulatorImplMacOs();
    ~XInputSimulatorImplMacOs(){}

    virtual void mouseMoveTo(int x, int y) override;
    virtual void mouseMoveRelative(int x, int y) override;
    virtual void mouseDown(int button) override;
    virtual void mouseUp(int button) override;
    virtual void mouseClick(int button) override;
    virtual void mouseScrollX(int length) override;
    virtual void mouseScrollY(int length) override;

    virtual void keyDown(int key) override;
    virtual void keyUp(int key) override;
    virtual void keyClick(int key) override;

    virtual int charToKeyCode(char key_char) override;
    virtual void keySequence(const std::string &sequence) override;
};


#endif // XINPUTSIMULATORIMPLMACOS_H
#endif //apple
