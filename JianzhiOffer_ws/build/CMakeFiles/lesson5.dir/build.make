# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/novauto/Learn/JianzhiOffer_study/JianzhiOffer_ws

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/novauto/Learn/JianzhiOffer_study/JianzhiOffer_ws/build

# Include any dependencies generated for this target.
include CMakeFiles/lesson5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lesson5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lesson5.dir/flags.make

CMakeFiles/lesson5.dir/lesson5/lesson5.cpp.o: CMakeFiles/lesson5.dir/flags.make
CMakeFiles/lesson5.dir/lesson5/lesson5.cpp.o: ../lesson5/lesson5.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/novauto/Learn/JianzhiOffer_study/JianzhiOffer_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lesson5.dir/lesson5/lesson5.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lesson5.dir/lesson5/lesson5.cpp.o -c /home/novauto/Learn/JianzhiOffer_study/JianzhiOffer_ws/lesson5/lesson5.cpp

CMakeFiles/lesson5.dir/lesson5/lesson5.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lesson5.dir/lesson5/lesson5.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/novauto/Learn/JianzhiOffer_study/JianzhiOffer_ws/lesson5/lesson5.cpp > CMakeFiles/lesson5.dir/lesson5/lesson5.cpp.i

CMakeFiles/lesson5.dir/lesson5/lesson5.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lesson5.dir/lesson5/lesson5.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/novauto/Learn/JianzhiOffer_study/JianzhiOffer_ws/lesson5/lesson5.cpp -o CMakeFiles/lesson5.dir/lesson5/lesson5.cpp.s

CMakeFiles/lesson5.dir/lesson5/lesson5.cpp.o.requires:

.PHONY : CMakeFiles/lesson5.dir/lesson5/lesson5.cpp.o.requires

CMakeFiles/lesson5.dir/lesson5/lesson5.cpp.o.provides: CMakeFiles/lesson5.dir/lesson5/lesson5.cpp.o.requires
	$(MAKE) -f CMakeFiles/lesson5.dir/build.make CMakeFiles/lesson5.dir/lesson5/lesson5.cpp.o.provides.build
.PHONY : CMakeFiles/lesson5.dir/lesson5/lesson5.cpp.o.provides

CMakeFiles/lesson5.dir/lesson5/lesson5.cpp.o.provides.build: CMakeFiles/lesson5.dir/lesson5/lesson5.cpp.o


# Object files for target lesson5
lesson5_OBJECTS = \
"CMakeFiles/lesson5.dir/lesson5/lesson5.cpp.o"

# External object files for target lesson5
lesson5_EXTERNAL_OBJECTS =

lesson5: CMakeFiles/lesson5.dir/lesson5/lesson5.cpp.o
lesson5: CMakeFiles/lesson5.dir/build.make
lesson5: CMakeFiles/lesson5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/novauto/Learn/JianzhiOffer_study/JianzhiOffer_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lesson5"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lesson5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lesson5.dir/build: lesson5

.PHONY : CMakeFiles/lesson5.dir/build

CMakeFiles/lesson5.dir/requires: CMakeFiles/lesson5.dir/lesson5/lesson5.cpp.o.requires

.PHONY : CMakeFiles/lesson5.dir/requires

CMakeFiles/lesson5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lesson5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lesson5.dir/clean

CMakeFiles/lesson5.dir/depend:
	cd /home/novauto/Learn/JianzhiOffer_study/JianzhiOffer_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/novauto/Learn/JianzhiOffer_study/JianzhiOffer_ws /home/novauto/Learn/JianzhiOffer_study/JianzhiOffer_ws /home/novauto/Learn/JianzhiOffer_study/JianzhiOffer_ws/build /home/novauto/Learn/JianzhiOffer_study/JianzhiOffer_ws/build /home/novauto/Learn/JianzhiOffer_study/JianzhiOffer_ws/build/CMakeFiles/lesson5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lesson5.dir/depend

