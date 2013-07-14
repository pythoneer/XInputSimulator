#include <iostream>
#include "xinputsimulator.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    XInputSimulator &sim = XInputSimulator::getInstance();
    sim.mouseMoveTo(1,2);
    sim.mouseClick(1);

    return 0;
}

