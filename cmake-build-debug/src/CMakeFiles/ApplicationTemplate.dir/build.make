# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/troy/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/193.5662.56/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/troy/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/193.5662.56/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/troy/Projects/jsontree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/troy/Projects/jsontree/cmake-build-debug

# Include any dependencies generated for this target.
include src/CMakeFiles/ApplicationTemplate.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/ApplicationTemplate.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/ApplicationTemplate.dir/flags.make

generated/data/resources.c: generated/data/ApplicationTemplate.gresource.xml
generated/data/resources.c: ../data/ui/window.glade
generated/data/resources.c: ../data/ui/headerbar.glade
generated/data/resources.c: ../data/ui/menu.glade
generated/data/resources.c: ../data/ui/preferences.glade
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/troy/Projects/jsontree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating /home/troy/Projects/jsontree/cmake-build-debug/generated/data/resources.c..."
	cd /home/troy/Projects/jsontree/data && /usr/bin/glib-compile-resources --target=/home/troy/Projects/jsontree/cmake-build-debug/generated/data/resources.c --generate-source /home/troy/Projects/jsontree/cmake-build-debug/generated/data/ApplicationTemplate.gresource.xml

src/CMakeFiles/ApplicationTemplate.dir/main.cpp.o: src/CMakeFiles/ApplicationTemplate.dir/flags.make
src/CMakeFiles/ApplicationTemplate.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/troy/Projects/jsontree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/ApplicationTemplate.dir/main.cpp.o"
	cd /home/troy/Projects/jsontree/cmake-build-debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ApplicationTemplate.dir/main.cpp.o -c /home/troy/Projects/jsontree/src/main.cpp

src/CMakeFiles/ApplicationTemplate.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ApplicationTemplate.dir/main.cpp.i"
	cd /home/troy/Projects/jsontree/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/troy/Projects/jsontree/src/main.cpp > CMakeFiles/ApplicationTemplate.dir/main.cpp.i

src/CMakeFiles/ApplicationTemplate.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ApplicationTemplate.dir/main.cpp.s"
	cd /home/troy/Projects/jsontree/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/troy/Projects/jsontree/src/main.cpp -o CMakeFiles/ApplicationTemplate.dir/main.cpp.s

src/CMakeFiles/ApplicationTemplate.dir/application.cpp.o: src/CMakeFiles/ApplicationTemplate.dir/flags.make
src/CMakeFiles/ApplicationTemplate.dir/application.cpp.o: ../src/application.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/troy/Projects/jsontree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/ApplicationTemplate.dir/application.cpp.o"
	cd /home/troy/Projects/jsontree/cmake-build-debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ApplicationTemplate.dir/application.cpp.o -c /home/troy/Projects/jsontree/src/application.cpp

src/CMakeFiles/ApplicationTemplate.dir/application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ApplicationTemplate.dir/application.cpp.i"
	cd /home/troy/Projects/jsontree/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/troy/Projects/jsontree/src/application.cpp > CMakeFiles/ApplicationTemplate.dir/application.cpp.i

src/CMakeFiles/ApplicationTemplate.dir/application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ApplicationTemplate.dir/application.cpp.s"
	cd /home/troy/Projects/jsontree/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/troy/Projects/jsontree/src/application.cpp -o CMakeFiles/ApplicationTemplate.dir/application.cpp.s

src/CMakeFiles/ApplicationTemplate.dir/window.cpp.o: src/CMakeFiles/ApplicationTemplate.dir/flags.make
src/CMakeFiles/ApplicationTemplate.dir/window.cpp.o: ../src/window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/troy/Projects/jsontree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/ApplicationTemplate.dir/window.cpp.o"
	cd /home/troy/Projects/jsontree/cmake-build-debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ApplicationTemplate.dir/window.cpp.o -c /home/troy/Projects/jsontree/src/window.cpp

src/CMakeFiles/ApplicationTemplate.dir/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ApplicationTemplate.dir/window.cpp.i"
	cd /home/troy/Projects/jsontree/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/troy/Projects/jsontree/src/window.cpp > CMakeFiles/ApplicationTemplate.dir/window.cpp.i

src/CMakeFiles/ApplicationTemplate.dir/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ApplicationTemplate.dir/window.cpp.s"
	cd /home/troy/Projects/jsontree/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/troy/Projects/jsontree/src/window.cpp -o CMakeFiles/ApplicationTemplate.dir/window.cpp.s

src/CMakeFiles/ApplicationTemplate.dir/preferences.cpp.o: src/CMakeFiles/ApplicationTemplate.dir/flags.make
src/CMakeFiles/ApplicationTemplate.dir/preferences.cpp.o: ../src/preferences.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/troy/Projects/jsontree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/ApplicationTemplate.dir/preferences.cpp.o"
	cd /home/troy/Projects/jsontree/cmake-build-debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ApplicationTemplate.dir/preferences.cpp.o -c /home/troy/Projects/jsontree/src/preferences.cpp

src/CMakeFiles/ApplicationTemplate.dir/preferences.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ApplicationTemplate.dir/preferences.cpp.i"
	cd /home/troy/Projects/jsontree/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/troy/Projects/jsontree/src/preferences.cpp > CMakeFiles/ApplicationTemplate.dir/preferences.cpp.i

src/CMakeFiles/ApplicationTemplate.dir/preferences.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ApplicationTemplate.dir/preferences.cpp.s"
	cd /home/troy/Projects/jsontree/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/troy/Projects/jsontree/src/preferences.cpp -o CMakeFiles/ApplicationTemplate.dir/preferences.cpp.s

src/CMakeFiles/ApplicationTemplate.dir/utils.cpp.o: src/CMakeFiles/ApplicationTemplate.dir/flags.make
src/CMakeFiles/ApplicationTemplate.dir/utils.cpp.o: ../src/utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/troy/Projects/jsontree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/ApplicationTemplate.dir/utils.cpp.o"
	cd /home/troy/Projects/jsontree/cmake-build-debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ApplicationTemplate.dir/utils.cpp.o -c /home/troy/Projects/jsontree/src/utils.cpp

src/CMakeFiles/ApplicationTemplate.dir/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ApplicationTemplate.dir/utils.cpp.i"
	cd /home/troy/Projects/jsontree/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/troy/Projects/jsontree/src/utils.cpp > CMakeFiles/ApplicationTemplate.dir/utils.cpp.i

src/CMakeFiles/ApplicationTemplate.dir/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ApplicationTemplate.dir/utils.cpp.s"
	cd /home/troy/Projects/jsontree/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/troy/Projects/jsontree/src/utils.cpp -o CMakeFiles/ApplicationTemplate.dir/utils.cpp.s

src/CMakeFiles/ApplicationTemplate.dir/__/generated/data/resources.c.o: src/CMakeFiles/ApplicationTemplate.dir/flags.make
src/CMakeFiles/ApplicationTemplate.dir/__/generated/data/resources.c.o: generated/data/resources.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/troy/Projects/jsontree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object src/CMakeFiles/ApplicationTemplate.dir/__/generated/data/resources.c.o"
	cd /home/troy/Projects/jsontree/cmake-build-debug/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ApplicationTemplate.dir/__/generated/data/resources.c.o   -c /home/troy/Projects/jsontree/cmake-build-debug/generated/data/resources.c

src/CMakeFiles/ApplicationTemplate.dir/__/generated/data/resources.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ApplicationTemplate.dir/__/generated/data/resources.c.i"
	cd /home/troy/Projects/jsontree/cmake-build-debug/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/troy/Projects/jsontree/cmake-build-debug/generated/data/resources.c > CMakeFiles/ApplicationTemplate.dir/__/generated/data/resources.c.i

src/CMakeFiles/ApplicationTemplate.dir/__/generated/data/resources.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ApplicationTemplate.dir/__/generated/data/resources.c.s"
	cd /home/troy/Projects/jsontree/cmake-build-debug/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/troy/Projects/jsontree/cmake-build-debug/generated/data/resources.c -o CMakeFiles/ApplicationTemplate.dir/__/generated/data/resources.c.s

# Object files for target ApplicationTemplate
ApplicationTemplate_OBJECTS = \
"CMakeFiles/ApplicationTemplate.dir/main.cpp.o" \
"CMakeFiles/ApplicationTemplate.dir/application.cpp.o" \
"CMakeFiles/ApplicationTemplate.dir/window.cpp.o" \
"CMakeFiles/ApplicationTemplate.dir/preferences.cpp.o" \
"CMakeFiles/ApplicationTemplate.dir/utils.cpp.o" \
"CMakeFiles/ApplicationTemplate.dir/__/generated/data/resources.c.o"

# External object files for target ApplicationTemplate
ApplicationTemplate_EXTERNAL_OBJECTS =

src/ApplicationTemplate: src/CMakeFiles/ApplicationTemplate.dir/main.cpp.o
src/ApplicationTemplate: src/CMakeFiles/ApplicationTemplate.dir/application.cpp.o
src/ApplicationTemplate: src/CMakeFiles/ApplicationTemplate.dir/window.cpp.o
src/ApplicationTemplate: src/CMakeFiles/ApplicationTemplate.dir/preferences.cpp.o
src/ApplicationTemplate: src/CMakeFiles/ApplicationTemplate.dir/utils.cpp.o
src/ApplicationTemplate: src/CMakeFiles/ApplicationTemplate.dir/__/generated/data/resources.c.o
src/ApplicationTemplate: src/CMakeFiles/ApplicationTemplate.dir/build.make
src/ApplicationTemplate: src/CMakeFiles/ApplicationTemplate.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/troy/Projects/jsontree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable ApplicationTemplate"
	cd /home/troy/Projects/jsontree/cmake-build-debug/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ApplicationTemplate.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/ApplicationTemplate.dir/build: src/ApplicationTemplate

.PHONY : src/CMakeFiles/ApplicationTemplate.dir/build

src/CMakeFiles/ApplicationTemplate.dir/clean:
	cd /home/troy/Projects/jsontree/cmake-build-debug/src && $(CMAKE_COMMAND) -P CMakeFiles/ApplicationTemplate.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/ApplicationTemplate.dir/clean

src/CMakeFiles/ApplicationTemplate.dir/depend: generated/data/resources.c
	cd /home/troy/Projects/jsontree/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/troy/Projects/jsontree /home/troy/Projects/jsontree/src /home/troy/Projects/jsontree/cmake-build-debug /home/troy/Projects/jsontree/cmake-build-debug/src /home/troy/Projects/jsontree/cmake-build-debug/src/CMakeFiles/ApplicationTemplate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/ApplicationTemplate.dir/depend

