# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\congcong\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\203.7717.62\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\congcong\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\203.7717.62\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\git\lyz05\ACM\19CCPC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\git\lyz05\ACM\19CCPC\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/report.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/report.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/report.dir/flags.make

CMakeFiles/report.dir/report.cpp.obj: CMakeFiles/report.dir/flags.make
CMakeFiles/report.dir/report.cpp.obj: ../report.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\git\lyz05\ACM\19CCPC\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/report.dir/report.cpp.obj"
	"D:\Program Files\MinGW\bin\g++.exe"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\report.dir\report.cpp.obj -c D:\git\lyz05\ACM\19CCPC\report.cpp

CMakeFiles/report.dir/report.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/report.dir/report.cpp.i"
	"D:\Program Files\MinGW\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\git\lyz05\ACM\19CCPC\report.cpp > CMakeFiles\report.dir\report.cpp.i

CMakeFiles/report.dir/report.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/report.dir/report.cpp.s"
	"D:\Program Files\MinGW\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\git\lyz05\ACM\19CCPC\report.cpp -o CMakeFiles\report.dir\report.cpp.s

# Object files for target report
report_OBJECTS = \
"CMakeFiles/report.dir/report.cpp.obj"

# External object files for target report
report_EXTERNAL_OBJECTS =

report.exe: CMakeFiles/report.dir/report.cpp.obj
report.exe: CMakeFiles/report.dir/build.make
report.exe: CMakeFiles/report.dir/linklibs.rsp
report.exe: CMakeFiles/report.dir/objects1.rsp
report.exe: CMakeFiles/report.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\git\lyz05\ACM\19CCPC\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable report.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\report.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/report.dir/build: report.exe

.PHONY : CMakeFiles/report.dir/build

CMakeFiles/report.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\report.dir\cmake_clean.cmake
.PHONY : CMakeFiles/report.dir/clean

CMakeFiles/report.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\git\lyz05\ACM\19CCPC D:\git\lyz05\ACM\19CCPC D:\git\lyz05\ACM\19CCPC\cmake-build-debug D:\git\lyz05\ACM\19CCPC\cmake-build-debug D:\git\lyz05\ACM\19CCPC\cmake-build-debug\CMakeFiles\report.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/report.dir/depend

