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
CMAKE_COMMAND = /cygdrive/c/Users/HUAWEI/AppData/Local/JetBrains/CLion2022.2/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/HUAWEI/AppData/Local/JetBrains/CLion2022.2/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/d/Courses/ComputerPhysics/homework_10

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/d/Courses/ComputerPhysics/homework_10/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/homework_10.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/homework_10.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/homework_10.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/homework_10.dir/flags.make

CMakeFiles/homework_10.dir/main.cpp.o: CMakeFiles/homework_10.dir/flags.make
CMakeFiles/homework_10.dir/main.cpp.o: ../main.cpp
CMakeFiles/homework_10.dir/main.cpp.o: CMakeFiles/homework_10.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/Courses/ComputerPhysics/homework_10/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/homework_10.dir/main.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/homework_10.dir/main.cpp.o -MF CMakeFiles/homework_10.dir/main.cpp.o.d -o CMakeFiles/homework_10.dir/main.cpp.o -c /cygdrive/d/Courses/ComputerPhysics/homework_10/main.cpp

CMakeFiles/homework_10.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/homework_10.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/d/Courses/ComputerPhysics/homework_10/main.cpp > CMakeFiles/homework_10.dir/main.cpp.i

CMakeFiles/homework_10.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/homework_10.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/d/Courses/ComputerPhysics/homework_10/main.cpp -o CMakeFiles/homework_10.dir/main.cpp.s

CMakeFiles/homework_10.dir/Sch.cpp.o: CMakeFiles/homework_10.dir/flags.make
CMakeFiles/homework_10.dir/Sch.cpp.o: ../Sch.cpp
CMakeFiles/homework_10.dir/Sch.cpp.o: CMakeFiles/homework_10.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/Courses/ComputerPhysics/homework_10/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/homework_10.dir/Sch.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/homework_10.dir/Sch.cpp.o -MF CMakeFiles/homework_10.dir/Sch.cpp.o.d -o CMakeFiles/homework_10.dir/Sch.cpp.o -c /cygdrive/d/Courses/ComputerPhysics/homework_10/Sch.cpp

CMakeFiles/homework_10.dir/Sch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/homework_10.dir/Sch.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/d/Courses/ComputerPhysics/homework_10/Sch.cpp > CMakeFiles/homework_10.dir/Sch.cpp.i

CMakeFiles/homework_10.dir/Sch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/homework_10.dir/Sch.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/d/Courses/ComputerPhysics/homework_10/Sch.cpp -o CMakeFiles/homework_10.dir/Sch.cpp.s

# Object files for target homework_10
homework_10_OBJECTS = \
"CMakeFiles/homework_10.dir/main.cpp.o" \
"CMakeFiles/homework_10.dir/Sch.cpp.o"

# External object files for target homework_10
homework_10_EXTERNAL_OBJECTS =

homework_10.exe: CMakeFiles/homework_10.dir/main.cpp.o
homework_10.exe: CMakeFiles/homework_10.dir/Sch.cpp.o
homework_10.exe: CMakeFiles/homework_10.dir/build.make
homework_10.exe: CMakeFiles/homework_10.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/d/Courses/ComputerPhysics/homework_10/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable homework_10.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/homework_10.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/homework_10.dir/build: homework_10.exe
.PHONY : CMakeFiles/homework_10.dir/build

CMakeFiles/homework_10.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/homework_10.dir/cmake_clean.cmake
.PHONY : CMakeFiles/homework_10.dir/clean

CMakeFiles/homework_10.dir/depend:
	cd /cygdrive/d/Courses/ComputerPhysics/homework_10/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/d/Courses/ComputerPhysics/homework_10 /cygdrive/d/Courses/ComputerPhysics/homework_10 /cygdrive/d/Courses/ComputerPhysics/homework_10/cmake-build-debug /cygdrive/d/Courses/ComputerPhysics/homework_10/cmake-build-debug /cygdrive/d/Courses/ComputerPhysics/homework_10/cmake-build-debug/CMakeFiles/homework_10.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/homework_10.dir/depend

