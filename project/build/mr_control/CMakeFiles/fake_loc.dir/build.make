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
CMAKE_SOURCE_DIR = /home/dixuan/Document/robotique/project/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dixuan/Document/robotique/project/build

# Include any dependencies generated for this target.
include mr_control/CMakeFiles/fake_loc.dir/depend.make

# Include the progress variables for this target.
include mr_control/CMakeFiles/fake_loc.dir/progress.make

# Include the compile flags for this target's objects.
include mr_control/CMakeFiles/fake_loc.dir/flags.make

mr_control/CMakeFiles/fake_loc.dir/src/fake_localization.cpp.o: mr_control/CMakeFiles/fake_loc.dir/flags.make
mr_control/CMakeFiles/fake_loc.dir/src/fake_localization.cpp.o: /home/dixuan/Document/robotique/project/src/mr_control/src/fake_localization.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dixuan/Document/robotique/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object mr_control/CMakeFiles/fake_loc.dir/src/fake_localization.cpp.o"
	cd /home/dixuan/Document/robotique/project/build/mr_control && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fake_loc.dir/src/fake_localization.cpp.o -c /home/dixuan/Document/robotique/project/src/mr_control/src/fake_localization.cpp

mr_control/CMakeFiles/fake_loc.dir/src/fake_localization.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fake_loc.dir/src/fake_localization.cpp.i"
	cd /home/dixuan/Document/robotique/project/build/mr_control && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dixuan/Document/robotique/project/src/mr_control/src/fake_localization.cpp > CMakeFiles/fake_loc.dir/src/fake_localization.cpp.i

mr_control/CMakeFiles/fake_loc.dir/src/fake_localization.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fake_loc.dir/src/fake_localization.cpp.s"
	cd /home/dixuan/Document/robotique/project/build/mr_control && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dixuan/Document/robotique/project/src/mr_control/src/fake_localization.cpp -o CMakeFiles/fake_loc.dir/src/fake_localization.cpp.s

# Object files for target fake_loc
fake_loc_OBJECTS = \
"CMakeFiles/fake_loc.dir/src/fake_localization.cpp.o"

# External object files for target fake_loc
fake_loc_EXTERNAL_OBJECTS =

/home/dixuan/Document/robotique/project/devel/lib/mr_control/fake_loc: mr_control/CMakeFiles/fake_loc.dir/src/fake_localization.cpp.o
/home/dixuan/Document/robotique/project/devel/lib/mr_control/fake_loc: mr_control/CMakeFiles/fake_loc.dir/build.make
/home/dixuan/Document/robotique/project/devel/lib/mr_control/fake_loc: /opt/ros/noetic/lib/libtf.so
/home/dixuan/Document/robotique/project/devel/lib/mr_control/fake_loc: /opt/ros/noetic/lib/libtf2_ros.so
/home/dixuan/Document/robotique/project/devel/lib/mr_control/fake_loc: /opt/ros/noetic/lib/libactionlib.so
/home/dixuan/Document/robotique/project/devel/lib/mr_control/fake_loc: /opt/ros/noetic/lib/libmessage_filters.so
/home/dixuan/Document/robotique/project/devel/lib/mr_control/fake_loc: /opt/ros/noetic/lib/libroscpp.so
/home/dixuan/Document/robotique/project/devel/lib/mr_control/fake_loc: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/dixuan/Document/robotique/project/devel/lib/mr_control/fake_loc: /usr/lib/x86_64-linux-gnu/libboost_chrono.so.1.71.0
/home/dixuan/Document/robotique/project/devel/lib/mr_control/fake_loc: /opt/ros/noetic/lib/librosconsole.so
/home/dixuan/Document/robotique/project/devel/lib/mr_control/fake_loc: /opt/ros/noetic/lib/librosconsole_log4cxx.so
/home/dixuan/Document/robotique/project/devel/lib/mr_control/fake_loc: /opt/ros/noetic/lib/librosconsole_backend_interface.so
/home/dixuan/Document/robotique/project/devel/lib/mr_control/fake_loc: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/dixuan/Document/robotique/project/devel/lib/mr_control/fake_loc: /usr/lib/x86_64-linux-gnu/libboost_regex.so.1.71.0
/home/dixuan/Document/robotique/project/devel/lib/mr_control/fake_loc: /opt/ros/noetic/lib/libxmlrpcpp.so
/home/dixuan/Document/robotique/project/devel/lib/mr_control/fake_loc: /opt/ros/noetic/lib/libtf2.so
/home/dixuan/Document/robotique/project/devel/lib/mr_control/fake_loc: /opt/ros/noetic/lib/libroscpp_serialization.so
/home/dixuan/Document/robotique/project/devel/lib/mr_control/fake_loc: /opt/ros/noetic/lib/librostime.so
/home/dixuan/Document/robotique/project/devel/lib/mr_control/fake_loc: /usr/lib/x86_64-linux-gnu/libboost_date_time.so.1.71.0
/home/dixuan/Document/robotique/project/devel/lib/mr_control/fake_loc: /opt/ros/noetic/lib/libcpp_common.so
/home/dixuan/Document/robotique/project/devel/lib/mr_control/fake_loc: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.71.0
/home/dixuan/Document/robotique/project/devel/lib/mr_control/fake_loc: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/dixuan/Document/robotique/project/devel/lib/mr_control/fake_loc: /opt/ros/noetic/lib/libroslib.so
/home/dixuan/Document/robotique/project/devel/lib/mr_control/fake_loc: /opt/ros/noetic/lib/librospack.so
/home/dixuan/Document/robotique/project/devel/lib/mr_control/fake_loc: /usr/lib/x86_64-linux-gnu/libpython3.8.so
/home/dixuan/Document/robotique/project/devel/lib/mr_control/fake_loc: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.71.0
/home/dixuan/Document/robotique/project/devel/lib/mr_control/fake_loc: /usr/lib/x86_64-linux-gnu/libboost_program_options.so.1.71.0
/home/dixuan/Document/robotique/project/devel/lib/mr_control/fake_loc: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.71.0
/home/dixuan/Document/robotique/project/devel/lib/mr_control/fake_loc: /usr/lib/x86_64-linux-gnu/libtinyxml2.so
/home/dixuan/Document/robotique/project/devel/lib/mr_control/fake_loc: mr_control/CMakeFiles/fake_loc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dixuan/Document/robotique/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/dixuan/Document/robotique/project/devel/lib/mr_control/fake_loc"
	cd /home/dixuan/Document/robotique/project/build/mr_control && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fake_loc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
mr_control/CMakeFiles/fake_loc.dir/build: /home/dixuan/Document/robotique/project/devel/lib/mr_control/fake_loc

.PHONY : mr_control/CMakeFiles/fake_loc.dir/build

mr_control/CMakeFiles/fake_loc.dir/clean:
	cd /home/dixuan/Document/robotique/project/build/mr_control && $(CMAKE_COMMAND) -P CMakeFiles/fake_loc.dir/cmake_clean.cmake
.PHONY : mr_control/CMakeFiles/fake_loc.dir/clean

mr_control/CMakeFiles/fake_loc.dir/depend:
	cd /home/dixuan/Document/robotique/project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dixuan/Document/robotique/project/src /home/dixuan/Document/robotique/project/src/mr_control /home/dixuan/Document/robotique/project/build /home/dixuan/Document/robotique/project/build/mr_control /home/dixuan/Document/robotique/project/build/mr_control/CMakeFiles/fake_loc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : mr_control/CMakeFiles/fake_loc.dir/depend

