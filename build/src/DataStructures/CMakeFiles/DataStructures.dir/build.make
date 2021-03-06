# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.23.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.23.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/cursedrock17/documents/CPP/ArduinoVisualizer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/cursedrock17/documents/CPP/ArduinoVisualizer/build

# Include any dependencies generated for this target.
include src/DataStructures/CMakeFiles/DataStructures.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/DataStructures/CMakeFiles/DataStructures.dir/compiler_depend.make

# Include the progress variables for this target.
include src/DataStructures/CMakeFiles/DataStructures.dir/progress.make

# Include the compile flags for this target's objects.
include src/DataStructures/CMakeFiles/DataStructures.dir/flags.make

src/DataStructures/CMakeFiles/DataStructures.dir/Vector.cpp.o: src/DataStructures/CMakeFiles/DataStructures.dir/flags.make
src/DataStructures/CMakeFiles/DataStructures.dir/Vector.cpp.o: ../src/DataStructures/Vector.cpp
src/DataStructures/CMakeFiles/DataStructures.dir/Vector.cpp.o: src/DataStructures/CMakeFiles/DataStructures.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cursedrock17/documents/CPP/ArduinoVisualizer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/DataStructures/CMakeFiles/DataStructures.dir/Vector.cpp.o"
	cd /Users/cursedrock17/documents/CPP/ArduinoVisualizer/build/src/DataStructures && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/DataStructures/CMakeFiles/DataStructures.dir/Vector.cpp.o -MF CMakeFiles/DataStructures.dir/Vector.cpp.o.d -o CMakeFiles/DataStructures.dir/Vector.cpp.o -c /Users/cursedrock17/documents/CPP/ArduinoVisualizer/src/DataStructures/Vector.cpp

src/DataStructures/CMakeFiles/DataStructures.dir/Vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DataStructures.dir/Vector.cpp.i"
	cd /Users/cursedrock17/documents/CPP/ArduinoVisualizer/build/src/DataStructures && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cursedrock17/documents/CPP/ArduinoVisualizer/src/DataStructures/Vector.cpp > CMakeFiles/DataStructures.dir/Vector.cpp.i

src/DataStructures/CMakeFiles/DataStructures.dir/Vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DataStructures.dir/Vector.cpp.s"
	cd /Users/cursedrock17/documents/CPP/ArduinoVisualizer/build/src/DataStructures && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cursedrock17/documents/CPP/ArduinoVisualizer/src/DataStructures/Vector.cpp -o CMakeFiles/DataStructures.dir/Vector.cpp.s

# Object files for target DataStructures
DataStructures_OBJECTS = \
"CMakeFiles/DataStructures.dir/Vector.cpp.o"

# External object files for target DataStructures
DataStructures_EXTERNAL_OBJECTS =

src/DataStructures/libDataStructures.a: src/DataStructures/CMakeFiles/DataStructures.dir/Vector.cpp.o
src/DataStructures/libDataStructures.a: src/DataStructures/CMakeFiles/DataStructures.dir/build.make
src/DataStructures/libDataStructures.a: src/DataStructures/CMakeFiles/DataStructures.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/cursedrock17/documents/CPP/ArduinoVisualizer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libDataStructures.a"
	cd /Users/cursedrock17/documents/CPP/ArduinoVisualizer/build/src/DataStructures && $(CMAKE_COMMAND) -P CMakeFiles/DataStructures.dir/cmake_clean_target.cmake
	cd /Users/cursedrock17/documents/CPP/ArduinoVisualizer/build/src/DataStructures && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DataStructures.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/DataStructures/CMakeFiles/DataStructures.dir/build: src/DataStructures/libDataStructures.a
.PHONY : src/DataStructures/CMakeFiles/DataStructures.dir/build

src/DataStructures/CMakeFiles/DataStructures.dir/clean:
	cd /Users/cursedrock17/documents/CPP/ArduinoVisualizer/build/src/DataStructures && $(CMAKE_COMMAND) -P CMakeFiles/DataStructures.dir/cmake_clean.cmake
.PHONY : src/DataStructures/CMakeFiles/DataStructures.dir/clean

src/DataStructures/CMakeFiles/DataStructures.dir/depend:
	cd /Users/cursedrock17/documents/CPP/ArduinoVisualizer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/cursedrock17/documents/CPP/ArduinoVisualizer /Users/cursedrock17/documents/CPP/ArduinoVisualizer/src/DataStructures /Users/cursedrock17/documents/CPP/ArduinoVisualizer/build /Users/cursedrock17/documents/CPP/ArduinoVisualizer/build/src/DataStructures /Users/cursedrock17/documents/CPP/ArduinoVisualizer/build/src/DataStructures/CMakeFiles/DataStructures.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/DataStructures/CMakeFiles/DataStructures.dir/depend

