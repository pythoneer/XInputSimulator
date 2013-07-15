#ifdef __APPLE__

#include <iostream>

//quartz CG... stuff
#include <ApplicationServices/ApplicationServices.h>

//sleep
#include <unistd.h>

#include "xinputsimulatorimplmacos.h"
#include "notimplementedexception.h"



XInputSimulatorImplMacOs::XInputSimulatorImplMacOs()
{
    //this->initCurrentMousePosition();

    this->currentX = 500;
    this->currentY = 500;
}

//void XInputSimulatorImplMacOs::initMouseEvent(int button)
//{

//}

void XInputSimulatorImplMacOs::initCurrentMousePosition()
{
    throw NotImplementedException();
}

void XInputSimulatorImplMacOs::mouseMoveTo(int x, int y)
{
    std::cout << "moveTo mac\n";

    CGEventRef mouseEv = CGEventCreateMouseEvent(
                NULL, kCGEventMouseMoved,
                CGPointMake(x, y),
                kCGMouseButtonLeft);

    std::cout << "mv: " << mouseEv << std::endl;

    CGEventPost(kCGHIDEventTap, mouseEv);

    CFRelease(mouseEv);

    this->currentX = x;
    this->currentY = y;
}

void XInputSimulatorImplMacOs::mouseMoveRelative(int x, int y)
{
    std::cout << "moveRelative mac\n";

    int newX = this->currentX + x;
    int newY = this->currentY + y;

    std::cout << "newx: " << newX << " newy: " << newY << std::endl;

    CGEventRef mouseEv = CGEventCreateMouseEvent(
                NULL, kCGEventMouseMoved,
                CGPointMake(newX, newY),
                kCGMouseButtonLeft);

    CGEventPost(kCGHIDEventTap, mouseEv);

    CFRelease(mouseEv);

    this->currentX = newX;
    this->currentY = newY;
}

//TODO use the button from parameter list
void XInputSimulatorImplMacOs::mouseDown(int button)
{
    //throw NotImplementedException();

    std::cout << "mouseDown mac\n";

    CGEventRef mouseEv = CGEventCreateMouseEvent(
                NULL, kCGEventLeftMouseDown,
                CGPointMake(this->currentX, this->currentY),
                kCGMouseButtonLeft); // use int buttn from parameter

    CGEventPost(kCGHIDEventTap, mouseEv);

    CFRelease(mouseEv);

}

//TODO use the button from parameter list
void XInputSimulatorImplMacOs::mouseUp(int button)
{
    //throw NotImplementedException();

    std::cout << "mouseDown mac\n";

    CGEventRef mouseEv = CGEventCreateMouseEvent(
                NULL, kCGEventLeftMouseUp,
                CGPointMake(this->currentX, this->currentY),
                kCGMouseButtonLeft); // use int buttn from parameter

    CGEventPost(kCGHIDEventTap, mouseEv);

    CFRelease(mouseEv);
}

void XInputSimulatorImplMacOs::mouseClick(int button)
{
    //throw NotImplementedException();
    this->mouseDown(button);
    this->mouseUp(button);
}
//kajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjfkajsdölfkjasdölfkjasldökfjaölsdkjfalsdkjfalskdjfaldskjf
void XInputSimulatorImplMacOs::mouseScrollX(int length)
{
    //throw NotImplementedException();

    std::cout << "scroll x mac " << length << std::endl;

    int scrollDirection = -1; // 1 left -1 right

    if(length < 0){
        length *= -1;
        scrollDirection *= -1;
    }

    //length *= 100;

    for(int cnt = 0; cnt < length; cnt++){

        std::cout << "scroll y mac" << std::endl;

        CGEventRef scrollEv = CGEventCreateScrollWheelEvent (
                    NULL, kCGScrollEventUnitLine,  // kCGScrollEventUnitLine  //kCGScrollEventUnitPixel
                    2, //CGWheelCount 1 = y 2 = xy 3 = xyz
                    0,
                    scrollDirection); // length of scroll from -10 to 10 higher values lead to undef behaviour

        CGEventPost(kCGHIDEventTap, scrollEv);

        CFRelease(scrollEv);
        //sleep(1);
    }
}

void XInputSimulatorImplMacOs::mouseScrollY(int length)
{
    //throw NotImplementedException();

    std::cout << "scroll y mac " << length << std::endl;

    int scrollDirection = -1; // 1 down -1 up

    if(length < 0){
        length *= -1;
        scrollDirection *= -1;
    }

    //length *= 100;

    for(int cnt = 0; cnt < length; cnt++){

        std::cout << "scroll y mac" << std::endl;

        CGEventRef scrollEv = CGEventCreateScrollWheelEvent (
                    NULL, kCGScrollEventUnitLine,  // kCGScrollEventUnitLine  //kCGScrollEventUnitPixel
                    1, //CGWheelCount 1 = y 2 = xy 3 = xyz
                    scrollDirection); // length of scroll from -10 to 10 higher values lead to undef behaviour

        CGEventPost(kCGHIDEventTap, scrollEv);

        CFRelease(scrollEv);
        //sleep(1);
    }
}

void XInputSimulatorImplMacOs::keyDown(int key)
{
    throw NotImplementedException();
}

void XInputSimulatorImplMacOs::keyUp(int key)
{
    throw NotImplementedException();
}

#endif //apple
