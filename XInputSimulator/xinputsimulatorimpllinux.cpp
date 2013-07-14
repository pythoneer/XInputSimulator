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
