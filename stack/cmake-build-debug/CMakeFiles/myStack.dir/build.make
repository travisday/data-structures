# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/Travis/x/Data Structures/myStack"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/Travis/x/Data Structures/myStack/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/myStack.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/myStack.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/myStack.dir/flags.make

CMakeFiles/myStack.dir/main.cpp.o: CMakeFiles/myStack.dir/flags.make
CMakeFiles/myStack.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/Travis/x/Data Structures/myStack/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/myStack.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/myStack.dir/main.cpp.o -c "/Users/Travis/x/Data Structures/myStack/main.cpp"

CMakeFiles/myStack.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myStack.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Travis/x/Data Structures/myStack/main.cpp" > CMakeFiles/myStack.dir/main.cpp.i

CMakeFiles/myStack.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myStack.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Travis/x/Data Structures/myStack/main.cpp" -o CMakeFiles/myStack.dir/main.cpp.s

CMakeFiles/myStack.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/myStack.dir/main.cpp.o.requires

CMakeFiles/myStack.dir/main.cpp.o.provides: CMakeFiles/myStack.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/myStack.dir/build.make CMakeFiles/myStack.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/myStack.dir/main.cpp.o.provides

CMakeFiles/myStack.dir/main.cpp.o.provides.build: CMakeFiles/myStack.dir/main.cpp.o


# Object files for target myStack
myStack_OBJECTS = \
"CMakeFiles/myStack.dir/main.cpp.o"

# External object files for target myStack
myStack_EXTERNAL_OBJECTS =

myStack: CMakeFiles/myStack.dir/main.cpp.o
myStack: CMakeFiles/myStack.dir/build.make
myStack: CMakeFiles/myStack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/Travis/x/Data Structures/myStack/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable myStack"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/myStack.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/myStack.dir/build: myStack

.PHONY : CMakeFiles/myStack.dir/build

CMakeFiles/myStack.dir/requires: CMakeFiles/myStack.dir/main.cpp.o.requires

.PHONY : CMakeFiles/myStack.dir/requires

CMakeFiles/myStack.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/myStack.dir/cmake_clean.cmake
.PHONY : CMakeFiles/myStack.dir/clean

CMakeFiles/myStack.dir/depend:
	cd "/Users/Travis/x/Data Structures/myStack/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/Travis/x/Data Structures/myStack" "/Users/Travis/x/Data Structures/myStack" "/Users/Travis/x/Data Structures/myStack/cmake-build-debug" "/Users/Travis/x/Data Structures/myStack/cmake-build-debug" "/Users/Travis/x/Data Structures/myStack/cmake-build-debug/CMakeFiles/myStack.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/myStack.dir/depend
