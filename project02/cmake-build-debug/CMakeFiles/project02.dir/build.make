# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /opt/clion-2019.1.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.1.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mercydude/University/SUMMER_CPP/cppProjects/project02

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mercydude/University/SUMMER_CPP/cppProjects/project02/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/project02.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/project02.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project02.dir/flags.make

CMakeFiles/project02.dir/main.cpp.o: CMakeFiles/project02.dir/flags.make
CMakeFiles/project02.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mercydude/University/SUMMER_CPP/cppProjects/project02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/project02.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project02.dir/main.cpp.o -c /home/mercydude/University/SUMMER_CPP/cppProjects/project02/main.cpp

CMakeFiles/project02.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project02.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mercydude/University/SUMMER_CPP/cppProjects/project02/main.cpp > CMakeFiles/project02.dir/main.cpp.i

CMakeFiles/project02.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project02.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mercydude/University/SUMMER_CPP/cppProjects/project02/main.cpp -o CMakeFiles/project02.dir/main.cpp.s

# Object files for target project02
project02_OBJECTS = \
"CMakeFiles/project02.dir/main.cpp.o"

# External object files for target project02
project02_EXTERNAL_OBJECTS =

project02: CMakeFiles/project02.dir/main.cpp.o
project02: CMakeFiles/project02.dir/build.make
project02: CMakeFiles/project02.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mercydude/University/SUMMER_CPP/cppProjects/project02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable project02"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project02.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project02.dir/build: project02

.PHONY : CMakeFiles/project02.dir/build

CMakeFiles/project02.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project02.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project02.dir/clean

CMakeFiles/project02.dir/depend:
	cd /home/mercydude/University/SUMMER_CPP/cppProjects/project02/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mercydude/University/SUMMER_CPP/cppProjects/project02 /home/mercydude/University/SUMMER_CPP/cppProjects/project02 /home/mercydude/University/SUMMER_CPP/cppProjects/project02/cmake-build-debug /home/mercydude/University/SUMMER_CPP/cppProjects/project02/cmake-build-debug /home/mercydude/University/SUMMER_CPP/cppProjects/project02/cmake-build-debug/CMakeFiles/project02.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/project02.dir/depend

