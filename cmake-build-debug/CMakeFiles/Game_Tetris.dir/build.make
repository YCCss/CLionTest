# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files (x86)\CLion 2020.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files (x86)\CLion 2020.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\YCQ\code\C++\CLionTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\YCQ\code\C++\CLionTest\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Game_Tetris.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Game_Tetris.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Game_Tetris.dir/flags.make

CMakeFiles/Game_Tetris.dir/Game_Tetris.cpp.obj: CMakeFiles/Game_Tetris.dir/flags.make
CMakeFiles/Game_Tetris.dir/Game_Tetris.cpp.obj: CMakeFiles/Game_Tetris.dir/includes_CXX.rsp
CMakeFiles/Game_Tetris.dir/Game_Tetris.cpp.obj: ../Game_Tetris.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\YCQ\code\C++\CLionTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Game_Tetris.dir/Game_Tetris.cpp.obj"
	D:\PROGRA~1\TDM_GCC\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Game_Tetris.dir\Game_Tetris.cpp.obj -c E:\YCQ\code\C++\CLionTest\Game_Tetris.cpp

CMakeFiles/Game_Tetris.dir/Game_Tetris.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game_Tetris.dir/Game_Tetris.cpp.i"
	D:\PROGRA~1\TDM_GCC\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\YCQ\code\C++\CLionTest\Game_Tetris.cpp > CMakeFiles\Game_Tetris.dir\Game_Tetris.cpp.i

CMakeFiles/Game_Tetris.dir/Game_Tetris.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game_Tetris.dir/Game_Tetris.cpp.s"
	D:\PROGRA~1\TDM_GCC\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\YCQ\code\C++\CLionTest\Game_Tetris.cpp -o CMakeFiles\Game_Tetris.dir\Game_Tetris.cpp.s

# Object files for target Game_Tetris
Game_Tetris_OBJECTS = \
"CMakeFiles/Game_Tetris.dir/Game_Tetris.cpp.obj"

# External object files for target Game_Tetris
Game_Tetris_EXTERNAL_OBJECTS =

Game_Tetris.exe: CMakeFiles/Game_Tetris.dir/Game_Tetris.cpp.obj
Game_Tetris.exe: CMakeFiles/Game_Tetris.dir/build.make
Game_Tetris.exe: CMakeFiles/Game_Tetris.dir/linklibs.rsp
Game_Tetris.exe: CMakeFiles/Game_Tetris.dir/objects1.rsp
Game_Tetris.exe: CMakeFiles/Game_Tetris.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\YCQ\code\C++\CLionTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Game_Tetris.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Game_Tetris.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Game_Tetris.dir/build: Game_Tetris.exe

.PHONY : CMakeFiles/Game_Tetris.dir/build

CMakeFiles/Game_Tetris.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Game_Tetris.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Game_Tetris.dir/clean

CMakeFiles/Game_Tetris.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\YCQ\code\C++\CLionTest E:\YCQ\code\C++\CLionTest E:\YCQ\code\C++\CLionTest\cmake-build-debug E:\YCQ\code\C++\CLionTest\cmake-build-debug E:\YCQ\code\C++\CLionTest\cmake-build-debug\CMakeFiles\Game_Tetris.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Game_Tetris.dir/depend
