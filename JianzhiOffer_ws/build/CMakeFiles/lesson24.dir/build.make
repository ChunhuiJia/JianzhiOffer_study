# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
include CMakeFiles/lesson24.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lesson24.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lesson24.dir/flags.make

CMakeFiles/lesson24.dir/lesson24/lesson24.cpp.o: CMakeFiles/lesson24.dir/flags.make
CMakeFiles/lesson24.dir/lesson24/lesson24.cpp.o: ../lesson24/lesson24.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jch/Learn/JianzhiOffer_study/JianzhiOffer_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lesson24.dir/lesson24/lesson24.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lesson24.dir/lesson24/lesson24.cpp.o -c /home/jch/Learn/JianzhiOffer_study/JianzhiOffer_ws/lesson24/lesson24.cpp

CMakeFiles/lesson24.dir/lesson24/lesson24.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lesson24.dir/lesson24/lesson24.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jch/Learn/JianzhiOffer_study/JianzhiOffer_ws/lesson24/lesson24.cpp > CMakeFiles/lesson24.dir/lesson24/lesson24.cpp.i

CMakeFiles/lesson24.dir/lesson24/lesson24.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lesson24.dir/lesson24/lesson24.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jch/Learn/JianzhiOffer_study/JianzhiOffer_ws/lesson24/lesson24.cpp -o CMakeFiles/lesson24.dir/lesson24/lesson24.cpp.s

CMakeFiles/lesson24.dir/Utilities/List.cpp.o: CMakeFiles/lesson24.dir/flags.make
CMakeFiles/lesson24.dir/Utilities/List.cpp.o: ../Utilities/List.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jch/Learn/JianzhiOffer_study/JianzhiOffer_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lesson24.dir/Utilities/List.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lesson24.dir/Utilities/List.cpp.o -c /home/jch/Learn/JianzhiOffer_study/JianzhiOffer_ws/Utilities/List.cpp

CMakeFiles/lesson24.dir/Utilities/List.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lesson24.dir/Utilities/List.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jch/Learn/JianzhiOffer_study/JianzhiOffer_ws/Utilities/List.cpp > CMakeFiles/lesson24.dir/Utilities/List.cpp.i

CMakeFiles/lesson24.dir/Utilities/List.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lesson24.dir/Utilities/List.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jch/Learn/JianzhiOffer_study/JianzhiOffer_ws/Utilities/List.cpp -o CMakeFiles/lesson24.dir/Utilities/List.cpp.s

# Object files for target lesson24
lesson24_OBJECTS = \
"CMakeFiles/lesson24.dir/lesson24/lesson24.cpp.o" \
"CMakeFiles/lesson24.dir/Utilities/List.cpp.o"

# External object files for target lesson24
lesson24_EXTERNAL_OBJECTS =

lesson24: CMakeFiles/lesson24.dir/lesson24/lesson24.cpp.o
lesson24: CMakeFiles/lesson24.dir/Utilities/List.cpp.o
lesson24: CMakeFiles/lesson24.dir/build.make
lesson24: CMakeFiles/lesson24.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jch/Learn/JianzhiOffer_study/JianzhiOffer_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable lesson24"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lesson24.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lesson24.dir/build: lesson24

.PHONY : CMakeFiles/lesson24.dir/build

CMakeFiles/lesson24.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lesson24.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lesson24.dir/clean

CMakeFiles/lesson24.dir/depend:
	cd /home/jch/Learn/JianzhiOffer_study/JianzhiOffer_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jch/Learn/JianzhiOffer_study/JianzhiOffer_ws /home/jch/Learn/JianzhiOffer_study/JianzhiOffer_ws /home/jch/Learn/JianzhiOffer_study/JianzhiOffer_ws/build /home/jch/Learn/JianzhiOffer_study/JianzhiOffer_ws/build /home/jch/Learn/JianzhiOffer_study/JianzhiOffer_ws/build/CMakeFiles/lesson24.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lesson24.dir/depend

