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
include CMakeFiles/CLionTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CLionTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CLionTest.dir/flags.make

CMakeFiles/CLionTest.dir/main.cpp.obj: CMakeFiles/CLionTest.dir/flags.make
CMakeFiles/CLionTest.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\YCQ\code\C++\CLionTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CLionTest.dir/main.cpp.obj"
	D:\PROGRA~1\mingw\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CLionTest.dir\main.cpp.obj -c E:\YCQ\code\C++\CLionTest\main.cpp

CMakeFiles/CLionTest.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CLionTest.dir/main.cpp.i"
	D:\PROGRA~1\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\YCQ\code\C++\CLionTest\main.cpp > CMakeFiles\CLionTest.dir\main.cpp.i

CMakeFiles/CLionTest.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CLionTest.dir/main.cpp.s"
	D:\PROGRA~1\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\YCQ\code\C++\CLionTest\main.cpp -o CMakeFiles\CLionTest.dir\main.cpp.s

CMakeFiles/CLionTest.dir/mthread.cpp.obj: CMakeFiles/CLionTest.dir/flags.make
CMakeFiles/CLionTest.dir/mthread.cpp.obj: ../mthread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\YCQ\code\C++\CLionTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CLionTest.dir/mthread.cpp.obj"
	D:\PROGRA~1\mingw\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CLionTest.dir\mthread.cpp.obj -c E:\YCQ\code\C++\CLionTest\mthread.cpp

CMakeFiles/CLionTest.dir/mthread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CLionTest.dir/mthread.cpp.i"
	D:\PROGRA~1\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\YCQ\code\C++\CLionTest\mthread.cpp > CMakeFiles\CLionTest.dir\mthread.cpp.i

CMakeFiles/CLionTest.dir/mthread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CLionTest.dir/mthread.cpp.s"
	D:\PROGRA~1\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\YCQ\code\C++\CLionTest\mthread.cpp -o CMakeFiles\CLionTest.dir\mthread.cpp.s

CMakeFiles/CLionTest.dir/thread_pool1.cpp.obj: CMakeFiles/CLionTest.dir/flags.make
CMakeFiles/CLionTest.dir/thread_pool1.cpp.obj: ../thread_pool1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\YCQ\code\C++\CLionTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CLionTest.dir/thread_pool1.cpp.obj"
	D:\PROGRA~1\mingw\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CLionTest.dir\thread_pool1.cpp.obj -c E:\YCQ\code\C++\CLionTest\thread_pool1.cpp

CMakeFiles/CLionTest.dir/thread_pool1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CLionTest.dir/thread_pool1.cpp.i"
	D:\PROGRA~1\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\YCQ\code\C++\CLionTest\thread_pool1.cpp > CMakeFiles\CLionTest.dir\thread_pool1.cpp.i

CMakeFiles/CLionTest.dir/thread_pool1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CLionTest.dir/thread_pool1.cpp.s"
	D:\PROGRA~1\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\YCQ\code\C++\CLionTest\thread_pool1.cpp -o CMakeFiles\CLionTest.dir\thread_pool1.cpp.s

CMakeFiles/CLionTest.dir/test.cpp.obj: CMakeFiles/CLionTest.dir/flags.make
CMakeFiles/CLionTest.dir/test.cpp.obj: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\YCQ\code\C++\CLionTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/CLionTest.dir/test.cpp.obj"
	D:\PROGRA~1\mingw\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CLionTest.dir\test.cpp.obj -c E:\YCQ\code\C++\CLionTest\test.cpp

CMakeFiles/CLionTest.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CLionTest.dir/test.cpp.i"
	D:\PROGRA~1\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\YCQ\code\C++\CLionTest\test.cpp > CMakeFiles\CLionTest.dir\test.cpp.i

CMakeFiles/CLionTest.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CLionTest.dir/test.cpp.s"
	D:\PROGRA~1\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\YCQ\code\C++\CLionTest\test.cpp -o CMakeFiles\CLionTest.dir\test.cpp.s

# Object files for target CLionTest
CLionTest_OBJECTS = \
"CMakeFiles/CLionTest.dir/main.cpp.obj" \
"CMakeFiles/CLionTest.dir/mthread.cpp.obj" \
"CMakeFiles/CLionTest.dir/thread_pool1.cpp.obj" \
"CMakeFiles/CLionTest.dir/test.cpp.obj"

# External object files for target CLionTest
CLionTest_EXTERNAL_OBJECTS =

CLionTest.exe: CMakeFiles/CLionTest.dir/main.cpp.obj
CLionTest.exe: CMakeFiles/CLionTest.dir/mthread.cpp.obj
CLionTest.exe: CMakeFiles/CLionTest.dir/thread_pool1.cpp.obj
CLionTest.exe: CMakeFiles/CLionTest.dir/test.cpp.obj
CLionTest.exe: CMakeFiles/CLionTest.dir/build.make
CLionTest.exe: CMakeFiles/CLionTest.dir/linklibs.rsp
CLionTest.exe: CMakeFiles/CLionTest.dir/objects1.rsp
CLionTest.exe: CMakeFiles/CLionTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\YCQ\code\C++\CLionTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable CLionTest.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CLionTest.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CLionTest.dir/build: CLionTest.exe

.PHONY : CMakeFiles/CLionTest.dir/build

CMakeFiles/CLionTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CLionTest.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CLionTest.dir/clean

CMakeFiles/CLionTest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\YCQ\code\C++\CLionTest E:\YCQ\code\C++\CLionTest E:\YCQ\code\C++\CLionTest\cmake-build-debug E:\YCQ\code\C++\CLionTest\cmake-build-debug E:\YCQ\code\C++\CLionTest\cmake-build-debug\CMakeFiles\CLionTest.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CLionTest.dir/depend
