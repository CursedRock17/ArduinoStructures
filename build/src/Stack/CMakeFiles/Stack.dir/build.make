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
include src/Stack/CMakeFiles/Stack.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/Stack/CMakeFiles/Stack.dir/compiler_depend.make

# Include the progress variables for this target.
include src/Stack/CMakeFiles/Stack.dir/progress.make

# Include the compile flags for this target's objects.
include src/Stack/CMakeFiles/Stack.dir/flags.make

src/Stack/CMakeFiles/Stack.dir/Stack.cpp.o: src/Stack/CMakeFiles/Stack.dir/flags.make
src/Stack/CMakeFiles/Stack.dir/Stack.cpp.o: ../src/Stack/Stack.cpp
src/Stack/CMakeFiles/Stack.dir/Stack.cpp.o: src/Stack/CMakeFiles/Stack.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cursedrock17/documents/CPP/ArduinoVisualizer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/Stack/CMakeFiles/Stack.dir/Stack.cpp.o"
	cd /Users/cursedrock17/documents/CPP/ArduinoVisualizer/build/src/Stack && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/Stack/CMakeFiles/Stack.dir/Stack.cpp.o -MF CMakeFiles/Stack.dir/Stack.cpp.o.d -o CMakeFiles/Stack.dir/Stack.cpp.o -c /Users/cursedrock17/documents/CPP/ArduinoVisualizer/src/Stack/Stack.cpp

src/Stack/CMakeFiles/Stack.dir/Stack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Stack.dir/Stack.cpp.i"
	cd /Users/cursedrock17/documents/CPP/ArduinoVisualizer/build/src/Stack && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cursedrock17/documents/CPP/ArduinoVisualizer/src/Stack/Stack.cpp > CMakeFiles/Stack.dir/Stack.cpp.i

src/Stack/CMakeFiles/Stack.dir/Stack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Stack.dir/Stack.cpp.s"
	cd /Users/cursedrock17/documents/CPP/ArduinoVisualizer/build/src/Stack && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cursedrock17/documents/CPP/ArduinoVisualizer/src/Stack/Stack.cpp -o CMakeFiles/Stack.dir/Stack.cpp.s

# Object files for target Stack
Stack_OBJECTS = \
"CMakeFiles/Stack.dir/Stack.cpp.o"

# External object files for target Stack
Stack_EXTERNAL_OBJECTS =

src/Stack/libStack.a: src/Stack/CMakeFiles/Stack.dir/Stack.cpp.o
src/Stack/libStack.a: src/Stack/CMakeFiles/Stack.dir/build.make
src/Stack/libStack.a: src/Stack/CMakeFiles/Stack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/cursedrock17/documents/CPP/ArduinoVisualizer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libStack.a"
	cd /Users/cursedrock17/documents/CPP/ArduinoVisualizer/build/src/Stack && $(CMAKE_COMMAND) -P CMakeFiles/Stack.dir/cmake_clean_target.cmake
	cd /Users/cursedrock17/documents/CPP/ArduinoVisualizer/build/src/Stack && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Stack.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/Stack/CMakeFiles/Stack.dir/build: src/Stack/libStack.a
.PHONY : src/Stack/CMakeFiles/Stack.dir/build

src/Stack/CMakeFiles/Stack.dir/clean:
	cd /Users/cursedrock17/documents/CPP/ArduinoVisualizer/build/src/Stack && $(CMAKE_COMMAND) -P CMakeFiles/Stack.dir/cmake_clean.cmake
.PHONY : src/Stack/CMakeFiles/Stack.dir/clean

src/Stack/CMakeFiles/Stack.dir/depend:
	cd /Users/cursedrock17/documents/CPP/ArduinoVisualizer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/cursedrock17/documents/CPP/ArduinoVisualizer /Users/cursedrock17/documents/CPP/ArduinoVisualizer/src/Stack /Users/cursedrock17/documents/CPP/ArduinoVisualizer/build /Users/cursedrock17/documents/CPP/ArduinoVisualizer/build/src/Stack /Users/cursedrock17/documents/CPP/ArduinoVisualizer/build/src/Stack/CMakeFiles/Stack.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/Stack/CMakeFiles/Stack.dir/depend

