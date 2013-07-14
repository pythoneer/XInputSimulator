XInputSimulator
===============

Cross (X) Plattform (Linux/Mac/Win) Simulator for input devices to simulate mouse moves/clicks/scrolls or keyboard keystrokes.
=== How to use ===
For a detailed example see main.cpp

XInputSimulator &sim = XInputSimulator::getInstance();
sim.mouseMoveTo(1,2);
sim.mouseClick(1);

This program is published under the terms of the LGPL (http://www.gnu.org/licenses/)
