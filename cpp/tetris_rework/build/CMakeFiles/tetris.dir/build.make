# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tienp/Documents/repo_git/cpp/tetris_rework

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tienp/Documents/repo_git/cpp/tetris_rework/build

# Include any dependencies generated for this target.
include CMakeFiles/tetris.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tetris.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tetris.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tetris.dir/flags.make

CMakeFiles/tetris.dir/main.cpp.o: CMakeFiles/tetris.dir/flags.make
CMakeFiles/tetris.dir/main.cpp.o: /home/tienp/Documents/repo_git/cpp/tetris_rework/main.cpp
CMakeFiles/tetris.dir/main.cpp.o: CMakeFiles/tetris.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tienp/Documents/repo_git/cpp/tetris_rework/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tetris.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tetris.dir/main.cpp.o -MF CMakeFiles/tetris.dir/main.cpp.o.d -o CMakeFiles/tetris.dir/main.cpp.o -c /home/tienp/Documents/repo_git/cpp/tetris_rework/main.cpp

CMakeFiles/tetris.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tetris.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tienp/Documents/repo_git/cpp/tetris_rework/main.cpp > CMakeFiles/tetris.dir/main.cpp.i

CMakeFiles/tetris.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tetris.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tienp/Documents/repo_git/cpp/tetris_rework/main.cpp -o CMakeFiles/tetris.dir/main.cpp.s

CMakeFiles/tetris.dir/src/block.cpp.o: CMakeFiles/tetris.dir/flags.make
CMakeFiles/tetris.dir/src/block.cpp.o: /home/tienp/Documents/repo_git/cpp/tetris_rework/src/block.cpp
CMakeFiles/tetris.dir/src/block.cpp.o: CMakeFiles/tetris.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tienp/Documents/repo_git/cpp/tetris_rework/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tetris.dir/src/block.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tetris.dir/src/block.cpp.o -MF CMakeFiles/tetris.dir/src/block.cpp.o.d -o CMakeFiles/tetris.dir/src/block.cpp.o -c /home/tienp/Documents/repo_git/cpp/tetris_rework/src/block.cpp

CMakeFiles/tetris.dir/src/block.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tetris.dir/src/block.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tienp/Documents/repo_git/cpp/tetris_rework/src/block.cpp > CMakeFiles/tetris.dir/src/block.cpp.i

CMakeFiles/tetris.dir/src/block.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tetris.dir/src/block.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tienp/Documents/repo_git/cpp/tetris_rework/src/block.cpp -o CMakeFiles/tetris.dir/src/block.cpp.s

CMakeFiles/tetris.dir/src/blocks.cpp.o: CMakeFiles/tetris.dir/flags.make
CMakeFiles/tetris.dir/src/blocks.cpp.o: /home/tienp/Documents/repo_git/cpp/tetris_rework/src/blocks.cpp
CMakeFiles/tetris.dir/src/blocks.cpp.o: CMakeFiles/tetris.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tienp/Documents/repo_git/cpp/tetris_rework/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/tetris.dir/src/blocks.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tetris.dir/src/blocks.cpp.o -MF CMakeFiles/tetris.dir/src/blocks.cpp.o.d -o CMakeFiles/tetris.dir/src/blocks.cpp.o -c /home/tienp/Documents/repo_git/cpp/tetris_rework/src/blocks.cpp

CMakeFiles/tetris.dir/src/blocks.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tetris.dir/src/blocks.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tienp/Documents/repo_git/cpp/tetris_rework/src/blocks.cpp > CMakeFiles/tetris.dir/src/blocks.cpp.i

CMakeFiles/tetris.dir/src/blocks.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tetris.dir/src/blocks.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tienp/Documents/repo_git/cpp/tetris_rework/src/blocks.cpp -o CMakeFiles/tetris.dir/src/blocks.cpp.s

CMakeFiles/tetris.dir/src/colors.cpp.o: CMakeFiles/tetris.dir/flags.make
CMakeFiles/tetris.dir/src/colors.cpp.o: /home/tienp/Documents/repo_git/cpp/tetris_rework/src/colors.cpp
CMakeFiles/tetris.dir/src/colors.cpp.o: CMakeFiles/tetris.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tienp/Documents/repo_git/cpp/tetris_rework/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/tetris.dir/src/colors.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tetris.dir/src/colors.cpp.o -MF CMakeFiles/tetris.dir/src/colors.cpp.o.d -o CMakeFiles/tetris.dir/src/colors.cpp.o -c /home/tienp/Documents/repo_git/cpp/tetris_rework/src/colors.cpp

CMakeFiles/tetris.dir/src/colors.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tetris.dir/src/colors.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tienp/Documents/repo_git/cpp/tetris_rework/src/colors.cpp > CMakeFiles/tetris.dir/src/colors.cpp.i

CMakeFiles/tetris.dir/src/colors.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tetris.dir/src/colors.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tienp/Documents/repo_git/cpp/tetris_rework/src/colors.cpp -o CMakeFiles/tetris.dir/src/colors.cpp.s

CMakeFiles/tetris.dir/src/game.cpp.o: CMakeFiles/tetris.dir/flags.make
CMakeFiles/tetris.dir/src/game.cpp.o: /home/tienp/Documents/repo_git/cpp/tetris_rework/src/game.cpp
CMakeFiles/tetris.dir/src/game.cpp.o: CMakeFiles/tetris.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tienp/Documents/repo_git/cpp/tetris_rework/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/tetris.dir/src/game.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tetris.dir/src/game.cpp.o -MF CMakeFiles/tetris.dir/src/game.cpp.o.d -o CMakeFiles/tetris.dir/src/game.cpp.o -c /home/tienp/Documents/repo_git/cpp/tetris_rework/src/game.cpp

CMakeFiles/tetris.dir/src/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tetris.dir/src/game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tienp/Documents/repo_git/cpp/tetris_rework/src/game.cpp > CMakeFiles/tetris.dir/src/game.cpp.i

CMakeFiles/tetris.dir/src/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tetris.dir/src/game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tienp/Documents/repo_git/cpp/tetris_rework/src/game.cpp -o CMakeFiles/tetris.dir/src/game.cpp.s

CMakeFiles/tetris.dir/src/grid.cpp.o: CMakeFiles/tetris.dir/flags.make
CMakeFiles/tetris.dir/src/grid.cpp.o: /home/tienp/Documents/repo_git/cpp/tetris_rework/src/grid.cpp
CMakeFiles/tetris.dir/src/grid.cpp.o: CMakeFiles/tetris.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tienp/Documents/repo_git/cpp/tetris_rework/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/tetris.dir/src/grid.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tetris.dir/src/grid.cpp.o -MF CMakeFiles/tetris.dir/src/grid.cpp.o.d -o CMakeFiles/tetris.dir/src/grid.cpp.o -c /home/tienp/Documents/repo_git/cpp/tetris_rework/src/grid.cpp

CMakeFiles/tetris.dir/src/grid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tetris.dir/src/grid.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tienp/Documents/repo_git/cpp/tetris_rework/src/grid.cpp > CMakeFiles/tetris.dir/src/grid.cpp.i

CMakeFiles/tetris.dir/src/grid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tetris.dir/src/grid.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tienp/Documents/repo_git/cpp/tetris_rework/src/grid.cpp -o CMakeFiles/tetris.dir/src/grid.cpp.s

CMakeFiles/tetris.dir/src/position.cpp.o: CMakeFiles/tetris.dir/flags.make
CMakeFiles/tetris.dir/src/position.cpp.o: /home/tienp/Documents/repo_git/cpp/tetris_rework/src/position.cpp
CMakeFiles/tetris.dir/src/position.cpp.o: CMakeFiles/tetris.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tienp/Documents/repo_git/cpp/tetris_rework/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/tetris.dir/src/position.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tetris.dir/src/position.cpp.o -MF CMakeFiles/tetris.dir/src/position.cpp.o.d -o CMakeFiles/tetris.dir/src/position.cpp.o -c /home/tienp/Documents/repo_git/cpp/tetris_rework/src/position.cpp

CMakeFiles/tetris.dir/src/position.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tetris.dir/src/position.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tienp/Documents/repo_git/cpp/tetris_rework/src/position.cpp > CMakeFiles/tetris.dir/src/position.cpp.i

CMakeFiles/tetris.dir/src/position.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tetris.dir/src/position.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tienp/Documents/repo_git/cpp/tetris_rework/src/position.cpp -o CMakeFiles/tetris.dir/src/position.cpp.s

# Object files for target tetris
tetris_OBJECTS = \
"CMakeFiles/tetris.dir/main.cpp.o" \
"CMakeFiles/tetris.dir/src/block.cpp.o" \
"CMakeFiles/tetris.dir/src/blocks.cpp.o" \
"CMakeFiles/tetris.dir/src/colors.cpp.o" \
"CMakeFiles/tetris.dir/src/game.cpp.o" \
"CMakeFiles/tetris.dir/src/grid.cpp.o" \
"CMakeFiles/tetris.dir/src/position.cpp.o"

# External object files for target tetris
tetris_EXTERNAL_OBJECTS =

bin/tetris: CMakeFiles/tetris.dir/main.cpp.o
bin/tetris: CMakeFiles/tetris.dir/src/block.cpp.o
bin/tetris: CMakeFiles/tetris.dir/src/blocks.cpp.o
bin/tetris: CMakeFiles/tetris.dir/src/colors.cpp.o
bin/tetris: CMakeFiles/tetris.dir/src/game.cpp.o
bin/tetris: CMakeFiles/tetris.dir/src/grid.cpp.o
bin/tetris: CMakeFiles/tetris.dir/src/position.cpp.o
bin/tetris: CMakeFiles/tetris.dir/build.make
bin/tetris: CMakeFiles/tetris.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/tienp/Documents/repo_git/cpp/tetris_rework/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable bin/tetris"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tetris.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tetris.dir/build: bin/tetris
.PHONY : CMakeFiles/tetris.dir/build

CMakeFiles/tetris.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tetris.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tetris.dir/clean

CMakeFiles/tetris.dir/depend:
	cd /home/tienp/Documents/repo_git/cpp/tetris_rework/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tienp/Documents/repo_git/cpp/tetris_rework /home/tienp/Documents/repo_git/cpp/tetris_rework /home/tienp/Documents/repo_git/cpp/tetris_rework/build /home/tienp/Documents/repo_git/cpp/tetris_rework/build /home/tienp/Documents/repo_git/cpp/tetris_rework/build/CMakeFiles/tetris.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/tetris.dir/depend
