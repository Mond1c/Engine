# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/elenak/Documents/SDL/Engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/elenak/Documents/SDL/Engine/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Engine.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Engine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Engine.dir/flags.make

CMakeFiles/Engine.dir/Functions/function_parser.cpp.o: CMakeFiles/Engine.dir/flags.make
CMakeFiles/Engine.dir/Functions/function_parser.cpp.o: ../Functions/function_parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/elenak/Documents/SDL/Engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Engine.dir/Functions/function_parser.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Engine.dir/Functions/function_parser.cpp.o -c /Users/elenak/Documents/SDL/Engine/Functions/function_parser.cpp

CMakeFiles/Engine.dir/Functions/function_parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Engine.dir/Functions/function_parser.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/elenak/Documents/SDL/Engine/Functions/function_parser.cpp > CMakeFiles/Engine.dir/Functions/function_parser.cpp.i

CMakeFiles/Engine.dir/Functions/function_parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Engine.dir/Functions/function_parser.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/elenak/Documents/SDL/Engine/Functions/function_parser.cpp -o CMakeFiles/Engine.dir/Functions/function_parser.cpp.s

CMakeFiles/Engine.dir/Objects/shapes.cpp.o: CMakeFiles/Engine.dir/flags.make
CMakeFiles/Engine.dir/Objects/shapes.cpp.o: ../Objects/shapes.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/elenak/Documents/SDL/Engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Engine.dir/Objects/shapes.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Engine.dir/Objects/shapes.cpp.o -c /Users/elenak/Documents/SDL/Engine/Objects/shapes.cpp

CMakeFiles/Engine.dir/Objects/shapes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Engine.dir/Objects/shapes.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/elenak/Documents/SDL/Engine/Objects/shapes.cpp > CMakeFiles/Engine.dir/Objects/shapes.cpp.i

CMakeFiles/Engine.dir/Objects/shapes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Engine.dir/Objects/shapes.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/elenak/Documents/SDL/Engine/Objects/shapes.cpp -o CMakeFiles/Engine.dir/Objects/shapes.cpp.s

CMakeFiles/Engine.dir/Parser/file.cpp.o: CMakeFiles/Engine.dir/flags.make
CMakeFiles/Engine.dir/Parser/file.cpp.o: ../Parser/file.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/elenak/Documents/SDL/Engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Engine.dir/Parser/file.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Engine.dir/Parser/file.cpp.o -c /Users/elenak/Documents/SDL/Engine/Parser/file.cpp

CMakeFiles/Engine.dir/Parser/file.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Engine.dir/Parser/file.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/elenak/Documents/SDL/Engine/Parser/file.cpp > CMakeFiles/Engine.dir/Parser/file.cpp.i

CMakeFiles/Engine.dir/Parser/file.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Engine.dir/Parser/file.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/elenak/Documents/SDL/Engine/Parser/file.cpp -o CMakeFiles/Engine.dir/Parser/file.cpp.s

CMakeFiles/Engine.dir/Parser/object_parser.cpp.o: CMakeFiles/Engine.dir/flags.make
CMakeFiles/Engine.dir/Parser/object_parser.cpp.o: ../Parser/object_parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/elenak/Documents/SDL/Engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Engine.dir/Parser/object_parser.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Engine.dir/Parser/object_parser.cpp.o -c /Users/elenak/Documents/SDL/Engine/Parser/object_parser.cpp

CMakeFiles/Engine.dir/Parser/object_parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Engine.dir/Parser/object_parser.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/elenak/Documents/SDL/Engine/Parser/object_parser.cpp > CMakeFiles/Engine.dir/Parser/object_parser.cpp.i

CMakeFiles/Engine.dir/Parser/object_parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Engine.dir/Parser/object_parser.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/elenak/Documents/SDL/Engine/Parser/object_parser.cpp -o CMakeFiles/Engine.dir/Parser/object_parser.cpp.s

CMakeFiles/Engine.dir/Physics/collider.cpp.o: CMakeFiles/Engine.dir/flags.make
CMakeFiles/Engine.dir/Physics/collider.cpp.o: ../Physics/collider.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/elenak/Documents/SDL/Engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Engine.dir/Physics/collider.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Engine.dir/Physics/collider.cpp.o -c /Users/elenak/Documents/SDL/Engine/Physics/collider.cpp

CMakeFiles/Engine.dir/Physics/collider.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Engine.dir/Physics/collider.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/elenak/Documents/SDL/Engine/Physics/collider.cpp > CMakeFiles/Engine.dir/Physics/collider.cpp.i

CMakeFiles/Engine.dir/Physics/collider.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Engine.dir/Physics/collider.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/elenak/Documents/SDL/Engine/Physics/collider.cpp -o CMakeFiles/Engine.dir/Physics/collider.cpp.s

CMakeFiles/Engine.dir/Render/event.cpp.o: CMakeFiles/Engine.dir/flags.make
CMakeFiles/Engine.dir/Render/event.cpp.o: ../Render/event.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/elenak/Documents/SDL/Engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Engine.dir/Render/event.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Engine.dir/Render/event.cpp.o -c /Users/elenak/Documents/SDL/Engine/Render/event.cpp

CMakeFiles/Engine.dir/Render/event.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Engine.dir/Render/event.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/elenak/Documents/SDL/Engine/Render/event.cpp > CMakeFiles/Engine.dir/Render/event.cpp.i

CMakeFiles/Engine.dir/Render/event.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Engine.dir/Render/event.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/elenak/Documents/SDL/Engine/Render/event.cpp -o CMakeFiles/Engine.dir/Render/event.cpp.s

CMakeFiles/Engine.dir/Render/window.cpp.o: CMakeFiles/Engine.dir/flags.make
CMakeFiles/Engine.dir/Render/window.cpp.o: ../Render/window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/elenak/Documents/SDL/Engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Engine.dir/Render/window.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Engine.dir/Render/window.cpp.o -c /Users/elenak/Documents/SDL/Engine/Render/window.cpp

CMakeFiles/Engine.dir/Render/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Engine.dir/Render/window.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/elenak/Documents/SDL/Engine/Render/window.cpp > CMakeFiles/Engine.dir/Render/window.cpp.i

CMakeFiles/Engine.dir/Render/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Engine.dir/Render/window.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/elenak/Documents/SDL/Engine/Render/window.cpp -o CMakeFiles/Engine.dir/Render/window.cpp.s

CMakeFiles/Engine.dir/engine.cpp.o: CMakeFiles/Engine.dir/flags.make
CMakeFiles/Engine.dir/engine.cpp.o: ../engine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/elenak/Documents/SDL/Engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Engine.dir/engine.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Engine.dir/engine.cpp.o -c /Users/elenak/Documents/SDL/Engine/engine.cpp

CMakeFiles/Engine.dir/engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Engine.dir/engine.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/elenak/Documents/SDL/Engine/engine.cpp > CMakeFiles/Engine.dir/engine.cpp.i

CMakeFiles/Engine.dir/engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Engine.dir/engine.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/elenak/Documents/SDL/Engine/engine.cpp -o CMakeFiles/Engine.dir/engine.cpp.s

CMakeFiles/Engine.dir/main.cpp.o: CMakeFiles/Engine.dir/flags.make
CMakeFiles/Engine.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/elenak/Documents/SDL/Engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Engine.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Engine.dir/main.cpp.o -c /Users/elenak/Documents/SDL/Engine/main.cpp

CMakeFiles/Engine.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Engine.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/elenak/Documents/SDL/Engine/main.cpp > CMakeFiles/Engine.dir/main.cpp.i

CMakeFiles/Engine.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Engine.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/elenak/Documents/SDL/Engine/main.cpp -o CMakeFiles/Engine.dir/main.cpp.s

# Object files for target Engine
Engine_OBJECTS = \
"CMakeFiles/Engine.dir/Functions/function_parser.cpp.o" \
"CMakeFiles/Engine.dir/Objects/shapes.cpp.o" \
"CMakeFiles/Engine.dir/Parser/file.cpp.o" \
"CMakeFiles/Engine.dir/Parser/object_parser.cpp.o" \
"CMakeFiles/Engine.dir/Physics/collider.cpp.o" \
"CMakeFiles/Engine.dir/Render/event.cpp.o" \
"CMakeFiles/Engine.dir/Render/window.cpp.o" \
"CMakeFiles/Engine.dir/engine.cpp.o" \
"CMakeFiles/Engine.dir/main.cpp.o"

# External object files for target Engine
Engine_EXTERNAL_OBJECTS =

Engine: CMakeFiles/Engine.dir/Functions/function_parser.cpp.o
Engine: CMakeFiles/Engine.dir/Objects/shapes.cpp.o
Engine: CMakeFiles/Engine.dir/Parser/file.cpp.o
Engine: CMakeFiles/Engine.dir/Parser/object_parser.cpp.o
Engine: CMakeFiles/Engine.dir/Physics/collider.cpp.o
Engine: CMakeFiles/Engine.dir/Render/event.cpp.o
Engine: CMakeFiles/Engine.dir/Render/window.cpp.o
Engine: CMakeFiles/Engine.dir/engine.cpp.o
Engine: CMakeFiles/Engine.dir/main.cpp.o
Engine: CMakeFiles/Engine.dir/build.make
Engine: /usr/local/Cellar/sdl2/2.0.16/lib/libSDL2.dylib
Engine: CMakeFiles/Engine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/elenak/Documents/SDL/Engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable Engine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Engine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Engine.dir/build: Engine
.PHONY : CMakeFiles/Engine.dir/build

CMakeFiles/Engine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Engine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Engine.dir/clean

CMakeFiles/Engine.dir/depend:
	cd /Users/elenak/Documents/SDL/Engine/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/elenak/Documents/SDL/Engine /Users/elenak/Documents/SDL/Engine /Users/elenak/Documents/SDL/Engine/cmake-build-debug /Users/elenak/Documents/SDL/Engine/cmake-build-debug /Users/elenak/Documents/SDL/Engine/cmake-build-debug/CMakeFiles/Engine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Engine.dir/depend
