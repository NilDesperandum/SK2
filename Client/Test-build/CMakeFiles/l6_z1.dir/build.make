# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lukas/Pulpit/Client/Test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lukas/Pulpit/Client/Test-build

# Include any dependencies generated for this target.
include CMakeFiles/l6_z1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/l6_z1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/l6_z1.dir/flags.make

CMakeFiles/l6_z1.dir/main.cpp.o: CMakeFiles/l6_z1.dir/flags.make
CMakeFiles/l6_z1.dir/main.cpp.o: /home/lukas/Pulpit/Client/Test/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lukas/Pulpit/Client/Test-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/l6_z1.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/l6_z1.dir/main.cpp.o -c /home/lukas/Pulpit/Client/Test/main.cpp

CMakeFiles/l6_z1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/l6_z1.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lukas/Pulpit/Client/Test/main.cpp > CMakeFiles/l6_z1.dir/main.cpp.i

CMakeFiles/l6_z1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/l6_z1.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lukas/Pulpit/Client/Test/main.cpp -o CMakeFiles/l6_z1.dir/main.cpp.s

CMakeFiles/l6_z1.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/l6_z1.dir/main.cpp.o.requires

CMakeFiles/l6_z1.dir/main.cpp.o.provides: CMakeFiles/l6_z1.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/l6_z1.dir/build.make CMakeFiles/l6_z1.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/l6_z1.dir/main.cpp.o.provides

CMakeFiles/l6_z1.dir/main.cpp.o.provides.build: CMakeFiles/l6_z1.dir/main.cpp.o


CMakeFiles/l6_z1.dir/mywidget.cpp.o: CMakeFiles/l6_z1.dir/flags.make
CMakeFiles/l6_z1.dir/mywidget.cpp.o: /home/lukas/Pulpit/Client/Test/mywidget.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lukas/Pulpit/Client/Test-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/l6_z1.dir/mywidget.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/l6_z1.dir/mywidget.cpp.o -c /home/lukas/Pulpit/Client/Test/mywidget.cpp

CMakeFiles/l6_z1.dir/mywidget.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/l6_z1.dir/mywidget.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lukas/Pulpit/Client/Test/mywidget.cpp > CMakeFiles/l6_z1.dir/mywidget.cpp.i

CMakeFiles/l6_z1.dir/mywidget.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/l6_z1.dir/mywidget.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lukas/Pulpit/Client/Test/mywidget.cpp -o CMakeFiles/l6_z1.dir/mywidget.cpp.s

CMakeFiles/l6_z1.dir/mywidget.cpp.o.requires:

.PHONY : CMakeFiles/l6_z1.dir/mywidget.cpp.o.requires

CMakeFiles/l6_z1.dir/mywidget.cpp.o.provides: CMakeFiles/l6_z1.dir/mywidget.cpp.o.requires
	$(MAKE) -f CMakeFiles/l6_z1.dir/build.make CMakeFiles/l6_z1.dir/mywidget.cpp.o.provides.build
.PHONY : CMakeFiles/l6_z1.dir/mywidget.cpp.o.provides

CMakeFiles/l6_z1.dir/mywidget.cpp.o.provides.build: CMakeFiles/l6_z1.dir/mywidget.cpp.o


CMakeFiles/l6_z1.dir/l6_z1_automoc.cpp.o: CMakeFiles/l6_z1.dir/flags.make
CMakeFiles/l6_z1.dir/l6_z1_automoc.cpp.o: l6_z1_automoc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lukas/Pulpit/Client/Test-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/l6_z1.dir/l6_z1_automoc.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/l6_z1.dir/l6_z1_automoc.cpp.o -c /home/lukas/Pulpit/Client/Test-build/l6_z1_automoc.cpp

CMakeFiles/l6_z1.dir/l6_z1_automoc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/l6_z1.dir/l6_z1_automoc.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lukas/Pulpit/Client/Test-build/l6_z1_automoc.cpp > CMakeFiles/l6_z1.dir/l6_z1_automoc.cpp.i

CMakeFiles/l6_z1.dir/l6_z1_automoc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/l6_z1.dir/l6_z1_automoc.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lukas/Pulpit/Client/Test-build/l6_z1_automoc.cpp -o CMakeFiles/l6_z1.dir/l6_z1_automoc.cpp.s

CMakeFiles/l6_z1.dir/l6_z1_automoc.cpp.o.requires:

.PHONY : CMakeFiles/l6_z1.dir/l6_z1_automoc.cpp.o.requires

CMakeFiles/l6_z1.dir/l6_z1_automoc.cpp.o.provides: CMakeFiles/l6_z1.dir/l6_z1_automoc.cpp.o.requires
	$(MAKE) -f CMakeFiles/l6_z1.dir/build.make CMakeFiles/l6_z1.dir/l6_z1_automoc.cpp.o.provides.build
.PHONY : CMakeFiles/l6_z1.dir/l6_z1_automoc.cpp.o.provides

CMakeFiles/l6_z1.dir/l6_z1_automoc.cpp.o.provides.build: CMakeFiles/l6_z1.dir/l6_z1_automoc.cpp.o


# Object files for target l6_z1
l6_z1_OBJECTS = \
"CMakeFiles/l6_z1.dir/main.cpp.o" \
"CMakeFiles/l6_z1.dir/mywidget.cpp.o" \
"CMakeFiles/l6_z1.dir/l6_z1_automoc.cpp.o"

# External object files for target l6_z1
l6_z1_EXTERNAL_OBJECTS =

l6_z1: CMakeFiles/l6_z1.dir/main.cpp.o
l6_z1: CMakeFiles/l6_z1.dir/mywidget.cpp.o
l6_z1: CMakeFiles/l6_z1.dir/l6_z1_automoc.cpp.o
l6_z1: CMakeFiles/l6_z1.dir/build.make
l6_z1: /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.5.1
l6_z1: /usr/lib/i386-linux-gnu/libQt5Network.so.5.5.1
l6_z1: /usr/lib/i386-linux-gnu/libQt5Gui.so.5.5.1
l6_z1: /usr/lib/i386-linux-gnu/libQt5Core.so.5.5.1
l6_z1: CMakeFiles/l6_z1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lukas/Pulpit/Client/Test-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable l6_z1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/l6_z1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/l6_z1.dir/build: l6_z1

.PHONY : CMakeFiles/l6_z1.dir/build

CMakeFiles/l6_z1.dir/requires: CMakeFiles/l6_z1.dir/main.cpp.o.requires
CMakeFiles/l6_z1.dir/requires: CMakeFiles/l6_z1.dir/mywidget.cpp.o.requires
CMakeFiles/l6_z1.dir/requires: CMakeFiles/l6_z1.dir/l6_z1_automoc.cpp.o.requires

.PHONY : CMakeFiles/l6_z1.dir/requires

CMakeFiles/l6_z1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/l6_z1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/l6_z1.dir/clean

CMakeFiles/l6_z1.dir/depend:
	cd /home/lukas/Pulpit/Client/Test-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lukas/Pulpit/Client/Test /home/lukas/Pulpit/Client/Test /home/lukas/Pulpit/Client/Test-build /home/lukas/Pulpit/Client/Test-build /home/lukas/Pulpit/Client/Test-build/CMakeFiles/l6_z1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/l6_z1.dir/depend

