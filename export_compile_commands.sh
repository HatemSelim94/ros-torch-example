#!/bin/bash
catkin_make clean
catkin_make -DCMAKE_EXPORT_COMPILE_COMMANDS=1
cp build/compile_commands.json src/
