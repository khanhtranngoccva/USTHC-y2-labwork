# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Projects\USTHC-y2-labwork

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Projects\USTHC-y2-labwork\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/USTHC_y2_labwork_e1_c.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/USTHC_y2_labwork_e1_c.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/USTHC_y2_labwork_e1_c.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/USTHC_y2_labwork_e1_c.dir/flags.make

CMakeFiles/USTHC_y2_labwork_e1_c.dir/01/ex1.c.obj: CMakeFiles/USTHC_y2_labwork_e1_c.dir/flags.make
CMakeFiles/USTHC_y2_labwork_e1_c.dir/01/ex1.c.obj: ../01/ex1.c
CMakeFiles/USTHC_y2_labwork_e1_c.dir/01/ex1.c.obj: CMakeFiles/USTHC_y2_labwork_e1_c.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Projects\USTHC-y2-labwork\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/USTHC_y2_labwork_e1_c.dir/01/ex1.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/USTHC_y2_labwork_e1_c.dir/01/ex1.c.obj -MF CMakeFiles\USTHC_y2_labwork_e1_c.dir\01\ex1.c.obj.d -o CMakeFiles\USTHC_y2_labwork_e1_c.dir\01\ex1.c.obj -c C:\Projects\USTHC-y2-labwork\01\ex1.c

CMakeFiles/USTHC_y2_labwork_e1_c.dir/01/ex1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/USTHC_y2_labwork_e1_c.dir/01/ex1.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Projects\USTHC-y2-labwork\01\ex1.c > CMakeFiles\USTHC_y2_labwork_e1_c.dir\01\ex1.c.i

CMakeFiles/USTHC_y2_labwork_e1_c.dir/01/ex1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/USTHC_y2_labwork_e1_c.dir/01/ex1.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Projects\USTHC-y2-labwork\01\ex1.c -o CMakeFiles\USTHC_y2_labwork_e1_c.dir\01\ex1.c.s

# Object files for target USTHC_y2_labwork_e1_c
USTHC_y2_labwork_e1_c_OBJECTS = \
"CMakeFiles/USTHC_y2_labwork_e1_c.dir/01/ex1.c.obj"

# External object files for target USTHC_y2_labwork_e1_c
USTHC_y2_labwork_e1_c_EXTERNAL_OBJECTS =

USTHC_y2_labwork_e1_c.exe: CMakeFiles/USTHC_y2_labwork_e1_c.dir/01/ex1.c.obj
USTHC_y2_labwork_e1_c.exe: CMakeFiles/USTHC_y2_labwork_e1_c.dir/build.make
USTHC_y2_labwork_e1_c.exe: CMakeFiles/USTHC_y2_labwork_e1_c.dir/linklibs.rsp
USTHC_y2_labwork_e1_c.exe: CMakeFiles/USTHC_y2_labwork_e1_c.dir/objects1.rsp
USTHC_y2_labwork_e1_c.exe: CMakeFiles/USTHC_y2_labwork_e1_c.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Projects\USTHC-y2-labwork\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable USTHC_y2_labwork_e1_c.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\USTHC_y2_labwork_e1_c.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/USTHC_y2_labwork_e1_c.dir/build: USTHC_y2_labwork_e1_c.exe
.PHONY : CMakeFiles/USTHC_y2_labwork_e1_c.dir/build

CMakeFiles/USTHC_y2_labwork_e1_c.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\USTHC_y2_labwork_e1_c.dir\cmake_clean.cmake
.PHONY : CMakeFiles/USTHC_y2_labwork_e1_c.dir/clean

CMakeFiles/USTHC_y2_labwork_e1_c.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Projects\USTHC-y2-labwork C:\Projects\USTHC-y2-labwork C:\Projects\USTHC-y2-labwork\cmake-build-debug C:\Projects\USTHC-y2-labwork\cmake-build-debug C:\Projects\USTHC-y2-labwork\cmake-build-debug\CMakeFiles\USTHC_y2_labwork_e1_c.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/USTHC_y2_labwork_e1_c.dir/depend

