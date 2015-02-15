cmake_minimum_required(VERSION 2.8.4)
project(XInputSimulator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.cpp
    notimplementedexception.cpp
    notimplementedexception.h
    xinputsimulator.cpp
    xinputsimulator.h
    xinputsimulatorimpl.cpp
    xinputsimulatorimpl.h
    xinputsimulatorimpllinux.cpp
    xinputsimulatorimpllinux.h
    xinputsimulatorimplmacos.cpp
    xinputsimulatorimplmacos.h
    xinputsimulatorimplwin.cpp
    xinputsimulatorimplwin.h)

    # Linux
    if(UNIX AND NOT APPLE)
    	find_library(X_11 X11)
    	find_library(X_TST Xtst)
    	set(EXTRA_LIBS ${X_11} ${X_TST})
    endif(UNIX AND NOT APPLE)

    # Apple
    if(APPLE)
       find_library(APP_SERVICES ApplicationServices)
       find_library(CARBON Carbon)
       find_library(CORE_FOUNDATION CoreFoundation )
       set(EXTRA_LIBS ${APP_SERVICES_LIBRARY} ${CARBON} ${CORE_FOUNDATION})
    endif(APPLE)

add_executable(XInputSimulator ${SOURCE_FILES})
target_link_libraries(XInputSimulator ${EXTRA_LIBS} )