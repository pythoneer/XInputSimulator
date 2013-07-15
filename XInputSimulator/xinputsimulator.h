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

#ifndef XINPUTSIMULATOR_H
#define XINPUTSIMULATOR_H

#include <memory>
//#include <mutex>
#include <iostream>
#include "xinputsimulatorimpl.h"
#include "notimplementedexception.h"

#ifdef __linux__
#include "xinputsimulatorimpllinux.h"
#elif __APPLE__
#include "xinputsimulatorimplmacos.h"
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
        instance.implementation = new XInputSimulatorImplMacOs;
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
