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
CMAKE_SOURCE_DIR = /home/jch/Learn/JianzhiOffer_study/JianzhiOffer_ws

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jch/Learn/JianzhiOffer_study/JianzhiOffer_ws/build

# Include any dependencies generated for this target.
include CMakeFiles/lesson4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lesson4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lesson4.dir/flags.make

CMakeFiles/lesson4.dir/lesson4/lesson4.cpp.o: CMakeFiles/lesson4.dir/flags.make
CMakeFiles/lesson4.dir/lesson4/lesson4.cpp.o: ../lesson4/lesson4.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jch/Learn/JianzhiOffer_study/JianzhiOffer_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lesson4.dir/lesson4/lesson4.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lesson4.dir/lesson4/lesson4.cpp.o -c /home/jch/Learn/JianzhiOffer_study/JianzhiOffer_ws/lesson4/lesson4.cpp

CMakeFiles/lesson4.dir/lesson4/lesson4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lesson4.dir/lesson4/lesson4.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jch/Learn/JianzhiOffer_study/JianzhiOffer_ws/lesson4/lesson4.cpp > CMakeFiles/lesson4.dir/lesson4/lesson4.cpp.i

CMakeFiles/lesson4.dir/lesson4/lesson4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lesson4.dir/lesson4/lesson4.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jch/Learn/JianzhiOffer_study/JianzhiOffer_ws/lesson4/lesson4.cpp -o CMakeFiles/lesson4.dir/lesson4/lesson4.cpp.s

CMakeFiles/lesson4.dir/lesson4/lesson4.cpp.o.requires:

.PHONY : CMakeFiles/lesson4.dir/lesson4/lesson4.cpp.o.requires

CMakeFiles/lesson4.dir/lesson4/lesson4.cpp.o.provides: CMakeFiles/lesson4.dir/lesson4/lesson4.cpp.o.requires
	$(MAKE) -f CMakeFiles/lesson4.dir/build.make CMakeFiles/lesson4.dir/lesson4/lesson4.cpp.o.provides.build
.PHONY : CMakeFiles/lesson4.dir/lesson4/lesson4.cpp.o.provides

CMakeFiles/lesson4.dir/lesson4/lesson4.cpp.o.provides.build: CMakeFiles/lesson4.dir/lesson4/lesson4.cpp.o


# Object files for target lesson4
lesson4_OBJECTS = \
"CMakeFiles/lesson4.dir/lesson4/lesson4.cpp.o"

# External object files for target lesson4
lesson4_EXTERNAL_OBJECTS =

lesson4: CMakeFiles/lesson4.dir/lesson4/lesson4.cpp.o
lesson4: CMakeFiles/lesson4.dir/build.make
lesson4: CMakeFiles/lesson4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jch/Learn/JianzhiOffer_study/JianzhiOffer_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lesson4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lesson4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lesson4.dir/build: lesson4

.PHONY : CMakeFiles/lesson4.dir/build

CMakeFiles/lesson4.dir/requires: CMakeFiles/lesson4.dir/lesson4/lesson4.cpp.o.requires

.PHONY : CMakeFiles/lesson4.dir/requires

CMakeFiles/lesson4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lesson4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lesson4.dir/clean

CMakeFiles/lesson4.dir/depend:
	cd /home/jch/Learn/JianzhiOffer_study/JianzhiOffer_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jch/Learn/JianzhiOffer_study/JianzhiOffer_ws /home/jch/Learn/JianzhiOffer_study/JianzhiOffer_ws /home/jch/Learn/JianzhiOffer_study/JianzhiOffer_ws/build /home/jch/Learn/JianzhiOffer_study/JianzhiOffer_ws/build /home/jch/Learn/JianzhiOffer_study/JianzhiOffer_ws/build/CMakeFiles/lesson4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lesson4.dir/depend

