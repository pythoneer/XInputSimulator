#include "xinputsimulator.h"

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

void XInputSimulator::keyDown(int key)
{
    implementation->keyDown(key);
}

void XInputSimulator::keyUp(int key)
{
    implementation->keyUp(key);
}

