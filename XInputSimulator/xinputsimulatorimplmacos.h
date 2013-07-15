#ifndef XINPUTSIMULATORIMPLMACOS_H
#define XINPUTSIMULATORIMPLMACOS_H

#ifdef __APPLE__

#include "xinputsimulatorimpl.h"

class XInputSimulatorImplMacOs : public XInputSimulatorImpl
{
private:
    int currentX;
    int currentY;

    void initCurrentMousePosition();

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
};

#endif //apple

#endif // XINPUTSIMULATORIMPLMACOS_H
