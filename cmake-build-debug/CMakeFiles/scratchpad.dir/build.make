# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /cygdrive/c/Users/Rameen/AppData/Local/JetBrains/CLion2020.3/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/Rameen/AppData/Local/JetBrains/CLion2020.3/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/Rameen/CLionProjects/scratchpad

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/Rameen/CLionProjects/scratchpad/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/scratchpad.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/scratchpad.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/scratchpad.dir/flags.make

CMakeFiles/scratchpad.dir/main.cpp.o: CMakeFiles/scratchpad.dir/flags.make
CMakeFiles/scratchpad.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Rameen/CLionProjects/scratchpad/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/scratchpad.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/scratchpad.dir/main.cpp.o -c /cygdrive/c/Users/Rameen/CLionProjects/scratchpad/main.cpp

CMakeFiles/scratchpad.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/scratchpad.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/Rameen/CLionProjects/scratchpad/main.cpp > CMakeFiles/scratchpad.dir/main.cpp.i

CMakeFiles/scratchpad.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/scratchpad.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/Rameen/CLionProjects/scratchpad/main.cpp -o CMakeFiles/scratchpad.dir/main.cpp.s

# Object files for target scratchpad
scratchpad_OBJECTS = \
"CMakeFiles/scratchpad.dir/main.cpp.o"

# External object files for target scratchpad
scratchpad_EXTERNAL_OBJECTS =

scratchpad.exe: CMakeFiles/scratchpad.dir/main.cpp.o
scratchpad.exe: CMakeFiles/scratchpad.dir/build.make
scratchpad.exe: CMakeFiles/scratchpad.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/Rameen/CLionProjects/scratchpad/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable scratchpad.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/scratchpad.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/scratchpad.dir/build: scratchpad.exe

.PHONY : CMakeFiles/scratchpad.dir/build

CMakeFiles/scratchpad.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/scratchpad.dir/cmake_clean.cmake
.PHONY : CMakeFiles/scratchpad.dir/clean

CMakeFiles/scratchpad.dir/depend:
	cd /cygdrive/c/Users/Rameen/CLionProjects/scratchpad/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/Rameen/CLionProjects/scratchpad /cygdrive/c/Users/Rameen/CLionProjects/scratchpad /cygdrive/c/Users/Rameen/CLionProjects/scratchpad/cmake-build-debug /cygdrive/c/Users/Rameen/CLionProjects/scratchpad/cmake-build-debug /cygdrive/c/Users/Rameen/CLionProjects/scratchpad/cmake-build-debug/CMakeFiles/scratchpad.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/scratchpad.dir/depend

