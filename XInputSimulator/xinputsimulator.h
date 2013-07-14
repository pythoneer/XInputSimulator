#ifndef XINPUTSIMULATOR_H
#define XINPUTSIMULATOR_H

#include <memory>
#include <mutex>
#include <iostream>
#include "xinputsimulatorimpl.h"
#include "notimplementedexception.h"

#ifdef __linux__
#include "xinputsimulatorimpllinux.h"
#elif __APPLE__
// apple implementation
#elif _WIN32
// win implementation
#endif

class XInputSimulator
{
private:
//XInputSimulator    XInputSimulator instance;
    //std::unique_ptr<XInputSimulatorImpl> implementation;
    XInputSimulatorImpl *implementation;

    XInputSimulator(){}

public:
    XInputSimulator(XInputSimulator&) = delete;
    void operator=(XInputSimulator&) = delete;

    ~XInputSimulator() {
        std::cout <<  "Singleton::~Singleton" << std::endl;
        delete implementation;
    }
    //TODO add impl choose
    static XInputSimulator & getInstance()
    {
        static XInputSimulator instance;

        std::cout << "ThreadSafeSingleton::create_singleton_() "<< std::endl;

#ifdef __linux__
        // get linux impl
        //instance.implementation = std::move(std::unique_ptr<XInputSimulatorImpl>(new XInputSimulatorImplLinux));
        instance.implementation = new XInputSimulatorImplLinux;
#elif __APPLE__
        // apple implementation
            throw NotImplementedException();
#elif _WIN32
        // win implementation
            throw NotImplementedException();
#endif
        return instance;
    }

    void mouseMoveTo(int x, int y);//{ implementation->mouseMoveTo(x, y); }
    void mouseMoveRelative(int x, int y);
    void mouseDown(int button);
    void mouseUp(int button);
    void mouseClick(int button);
    void mouseScrollX(int length);
    void mouseScrollY(int length);

    void keyDown(int key);
    void keyUp(int key);
};


#endif // XINPUTSIMULATOR_H
