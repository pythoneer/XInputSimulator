cmake_minimum_required(VERSION 2.8.4)
project(XInputSimulator)
set(PROJECT_VERSION 0.1)

option(WITH_PIC "Compile static library as position-independent code" OFF) # Shared library is always PIC
option(BUILD_STATIC_LIBS "Build the static library" ON)
option(BUILD_SHARED_LIBS "Build the shared library" ON)
option(BUILD_MACOS_FATLIB "Build Fat library for both i386 and x86_64 on macOS" ON)
option(BUILD_MANUAL_TEST "Build the test application" ON)

if(BUILD_MACOS_FATLIB)
    if (CMAKE_OSX_ARCHITECTURES)
        message(FATAL_ERROR "User supplied -DCMAKE_OSX_ARCHITECTURES overrides BUILD_MACOS_FATLIB=ON")
    else()
        SET(CMAKE_OSX_ARCHITECTURES "x86_64;i386")
    endif()
endif()

    # Linux
    if(UNIX AND NOT APPLE)
        find_library(X_11 X11)
        find_library(X_TST Xtst)
        set(EXTRA_LIBS ${X_11} ${X_TST})
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
        # Not nice, but I don't know how to have CMake generate all dependencies
        # One could run ldd(1) on the .so and extract all deps...
        set(PKG_CONFIG_EXTRA_LIBS "-lX11 -lXtst -lXext -lxcb -lXau -pthread -lXdmcp -lrt")
        set(PLATFORM_SOURCE_FILES xinputsimulatorimpllinux.cpp xinputsimulatorimpllinux.h)
        set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
        set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
    endif(UNIX AND NOT APPLE)

    # Apple
    if(APPLE)
       find_library(CARBON Carbon)
       find_library(CORE_FOUNDATION CoreFoundation)
       set(EXTRA_LIBS ${CARBON} ${CORE_FOUNDATION})
       set(PKG_CONFIG_EXTRA_LIBS "-framework CoreFoundation -framework Carbon")
       set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
       set(PLATFORM_SOURCE_FILES xinputsimulatorimplmacos.cpp xinputsimulatorimplmacos.h)
       set(CMAKE_MACOSX_RPATH ON)
    endif(APPLE)

    # Windows
    if(WIN32)
        #find_library(USER_32 User32.Lib)
        #set(EXTRA_LIBS ${USER_32})
        set(PLATFORM_SOURCE_FILES xinputsimulatorimplwin.cpp xinputsimulatorimplwin.h)
    endif(WIN32)

    set(SOURCE_FILES
        notimplementedexception.cpp
        xinputsimulator.cpp
        xinputsimulator.h
        xinputsimulatorimpl.cpp
        xinputsimulatorimpl.h
        ${PLATFORM_SOURCE_FILES})

link_libraries(${EXTRA_LIBS} )
configure_file(XInputSimulator.pc.in XInputSimulator.pc @ONLY)

if (BUILD_SHARED_LIBS)
    add_library(XInputSimulator SHARED ${SOURCE_FILES})
    set_property(TARGET XInputSimulator PROPERTY POSITION_INDEPENDENT_CODE ON)
endif()
if (BUILD_STATIC_LIBS)
    add_library(XInputSimulator_static STATIC ${SOURCE_FILES})
    if (WITH_PIC)
        set_property(TARGET XInputSimulator_static PROPERTY POSITION_INDEPENDENT_CODE ON)
    endif()
    if(NOT WIN32) # Keep lib*.(a|dll) name, but avoid *.lib files overwriting each other on Windows
        set_target_properties(XInputSimulator_static PROPERTIES OUTPUT_NAME XInputSimulator)
    endif()
endif()



IF (NOT (BUILD_STATIC_LIBS OR BUILD_SHARED_LIBS))
    MESSAGE(FATAL_ERROR "Both -DBUILD_SHARED_LIBS=OFF and -DBUILD_STATIC_LIBS=OFF supplied. Nothing to do...")
ENDIF()

if (BUILD_MANUAL_TEST)
    add_executable(XInputSimulator_bin main.cpp)
    target_link_libraries(XInputSimulator_bin XInputSimulator)
    set_target_properties(XInputSimulator_bin PROPERTIES OUTPUT_NAME "XInputSimulator")
endif()

install(FILES ${CMAKE_BINARY_DIR}/XInputSimulator.pc DESTINATION lib/pkgconfig)
install(TARGETS XInputSimulator XInputSimulator_static
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)
install(FILES xinputsimulator.h DESTINATION include)

