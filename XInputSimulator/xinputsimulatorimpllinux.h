#ifndef XINPUTSIMULATORIMPLLINUX_H
#define XINPUTSIMULATORIMPLLINUX_H

#include "xinputsimulatorimpl.h"

class XInputSimulatorImplLinux : public XInputSimulatorImpl
{
public:
    XInputSimulatorImplLinux();
    ~XInputSimulatorImplLinux(){}

    virtual void mouseMoveTo(int x, int y) override;
    virtual void mouseMoveRelative(int x, int y) override;
    virtual void mouseDown(int button) override;
    virtual void mouseUp(int button) override;
    virtual void mouseClick(int button) override;
    virtual void mouseScrollX(int length) override;
    virtual void mouseScrollY(int length) override;

    virtual void keyDown(int key) override;
    virtual void keyUp(int key) override;

};

#endif // XINPUTSIMULATORIMPLLINUX_H
