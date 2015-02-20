cmake_minimum_required(VERSION 2.8.4)
project(XInputSimulator)

    # Linux
    if(UNIX AND NOT APPLE)
    	find_library(X_11 X11)
    	find_library(X_TST Xtst)
    	set(EXTRA_LIBS ${X_11} ${X_TST})
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
		set(PLATFORM_SOURCE_FILES xinputsimulatorimpllinux.cpp xinputsimulatorimpllinux.h)
    endif(UNIX AND NOT APPLE)

    # Apple
    if(APPLE)
       find_library(APP_SERVICES ApplicationServices)
       find_library(CARBON Carbon)
       find_library(CORE_FOUNDATION CoreFoundation)
       set(EXTRA_LIBS ${APP_SERVICES_LIBRARY} ${CARBON} ${CORE_FOUNDATION})
	   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
	   set(PLATFORM_SOURCE_FILES xinputsimulatorimplmacos.cpp xinputsimulatorimplmacos.h)
    endif(APPLE)
	
	# Windows
	if(WIN32)
		#find_library(USER_32 User32.Lib)
		#set(EXTRA_LIBS ${USER_32})
		set(PLATFORM_SOURCE_FILES xinputsimulatorimplwin.cpp xinputsimulatorimplwin.h)
	endif(WIN32)
	
	set(SOURCE_FILES
		main.cpp
		notimplementedexception.cpp
		notimplementedexception.h
		xinputsimulator.cpp
		xinputsimulator.h
		xinputsimulatorimpl.cpp
		xinputsimulatorimpl.h
		${PLATFORM_SOURCE_FILES})

add_executable(XInputSimulator ${SOURCE_FILES})
target_link_libraries(XInputSimulator ${EXTRA_LIBS} )