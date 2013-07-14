#ifndef XINPUTSIMULATORIMPL_H
#define XINPUTSIMULATORIMPL_H

class XInputSimulatorImpl
{
public:
    XInputSimulatorImpl();
    virtual ~XInputSimulatorImpl(){}

    virtual void mouseMoveTo(int x, int y) = 0;
    virtual void mouseMoveRelative(int x, int y) = 0;
    virtual void mouseDown(int button) = 0;
    virtual void mouseUp(int button) = 0;
    virtual void mouseClick(int button) = 0;
    virtual void mouseScrollX(int length) = 0;
    virtual void mouseScrollY(int length) = 0;

    virtual void keyDown(int key) = 0;
    virtual void keyUp(int key) = 0;

};

#endif // XINPUTSIMULATORIMPL_H
