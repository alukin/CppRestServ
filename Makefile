# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/al/projects/CppRestServ

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/al/projects/CppRestServ

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/al/projects/CppRestServ/CMakeFiles /home/al/projects/CppRestServ//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/al/projects/CppRestServ/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named restserver

# Build rule for target.
restserver: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 restserver
.PHONY : restserver

# fast build rule for target.
restserver/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/restserver.dir/build.make CMakeFiles/restserver.dir/build
.PHONY : restserver/fast

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/restserver.dir/build.make CMakeFiles/restserver.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/restserver.dir/build.make CMakeFiles/restserver.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/restserver.dir/build.make CMakeFiles/restserver.dir/main.cpp.s
.PHONY : main.cpp.s

src/HTTPAPIServer.o: src/HTTPAPIServer.cpp.o

.PHONY : src/HTTPAPIServer.o

# target to build an object file
src/HTTPAPIServer.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/restserver.dir/build.make CMakeFiles/restserver.dir/src/HTTPAPIServer.cpp.o
.PHONY : src/HTTPAPIServer.cpp.o

src/HTTPAPIServer.i: src/HTTPAPIServer.cpp.i

.PHONY : src/HTTPAPIServer.i

# target to preprocess a source file
src/HTTPAPIServer.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/restserver.dir/build.make CMakeFiles/restserver.dir/src/HTTPAPIServer.cpp.i
.PHONY : src/HTTPAPIServer.cpp.i

src/HTTPAPIServer.s: src/HTTPAPIServer.cpp.s

.PHONY : src/HTTPAPIServer.s

# target to generate assembly for a file
src/HTTPAPIServer.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/restserver.dir/build.make CMakeFiles/restserver.dir/src/HTTPAPIServer.cpp.s
.PHONY : src/HTTPAPIServer.cpp.s

src/Injectable.o: src/Injectable.cpp.o

.PHONY : src/Injectable.o

# target to build an object file
src/Injectable.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/restserver.dir/build.make CMakeFiles/restserver.dir/src/Injectable.cpp.o
.PHONY : src/Injectable.cpp.o

src/Injectable.i: src/Injectable.cpp.i

.PHONY : src/Injectable.i

# target to preprocess a source file
src/Injectable.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/restserver.dir/build.make CMakeFiles/restserver.dir/src/Injectable.cpp.i
.PHONY : src/Injectable.cpp.i

src/Injectable.s: src/Injectable.cpp.s

.PHONY : src/Injectable.s

# target to generate assembly for a file
src/Injectable.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/restserver.dir/build.make CMakeFiles/restserver.dir/src/Injectable.cpp.s
.PHONY : src/Injectable.cpp.s

src/PipesResource.o: src/PipesResource.cpp.o

.PHONY : src/PipesResource.o

# target to build an object file
src/PipesResource.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/restserver.dir/build.make CMakeFiles/restserver.dir/src/PipesResource.cpp.o
.PHONY : src/PipesResource.cpp.o

src/PipesResource.i: src/PipesResource.cpp.i

.PHONY : src/PipesResource.i

# target to preprocess a source file
src/PipesResource.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/restserver.dir/build.make CMakeFiles/restserver.dir/src/PipesResource.cpp.i
.PHONY : src/PipesResource.cpp.i

src/PipesResource.s: src/PipesResource.cpp.s

.PHONY : src/PipesResource.s

# target to generate assembly for a file
src/PipesResource.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/restserver.dir/build.make CMakeFiles/restserver.dir/src/PipesResource.cpp.s
.PHONY : src/PipesResource.cpp.s

src/RequestRouter.o: src/RequestRouter.cpp.o

.PHONY : src/RequestRouter.o

# target to build an object file
src/RequestRouter.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/restserver.dir/build.make CMakeFiles/restserver.dir/src/RequestRouter.cpp.o
.PHONY : src/RequestRouter.cpp.o

src/RequestRouter.i: src/RequestRouter.cpp.i

.PHONY : src/RequestRouter.i

# target to preprocess a source file
src/RequestRouter.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/restserver.dir/build.make CMakeFiles/restserver.dir/src/RequestRouter.cpp.i
.PHONY : src/RequestRouter.cpp.i

src/RequestRouter.s: src/RequestRouter.cpp.s

.PHONY : src/RequestRouter.s

# target to generate assembly for a file
src/RequestRouter.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/restserver.dir/build.make CMakeFiles/restserver.dir/src/RequestRouter.cpp.s
.PHONY : src/RequestRouter.cpp.s

src/ResourceFactory.o: src/ResourceFactory.cpp.o

.PHONY : src/ResourceFactory.o

# target to build an object file
src/ResourceFactory.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/restserver.dir/build.make CMakeFiles/restserver.dir/src/ResourceFactory.cpp.o
.PHONY : src/ResourceFactory.cpp.o

src/ResourceFactory.i: src/ResourceFactory.cpp.i

.PHONY : src/ResourceFactory.i

# target to preprocess a source file
src/ResourceFactory.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/restserver.dir/build.make CMakeFiles/restserver.dir/src/ResourceFactory.cpp.i
.PHONY : src/ResourceFactory.cpp.i

src/ResourceFactory.s: src/ResourceFactory.cpp.s

.PHONY : src/ResourceFactory.s

# target to generate assembly for a file
src/ResourceFactory.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/restserver.dir/build.make CMakeFiles/restserver.dir/src/ResourceFactory.cpp.s
.PHONY : src/ResourceFactory.cpp.s

src/StaticContentServ.o: src/StaticContentServ.cpp.o

.PHONY : src/StaticContentServ.o

# target to build an object file
src/StaticContentServ.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/restserver.dir/build.make CMakeFiles/restserver.dir/src/StaticContentServ.cpp.o
.PHONY : src/StaticContentServ.cpp.o

src/StaticContentServ.i: src/StaticContentServ.cpp.i

.PHONY : src/StaticContentServ.i

# target to preprocess a source file
src/StaticContentServ.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/restserver.dir/build.make CMakeFiles/restserver.dir/src/StaticContentServ.cpp.i
.PHONY : src/StaticContentServ.cpp.i

src/StaticContentServ.s: src/StaticContentServ.cpp.s

.PHONY : src/StaticContentServ.s

# target to generate assembly for a file
src/StaticContentServ.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/restserver.dir/build.make CMakeFiles/restserver.dir/src/StaticContentServ.cpp.s
.PHONY : src/StaticContentServ.cpp.s

src/UserResource.o: src/UserResource.cpp.o

.PHONY : src/UserResource.o

# target to build an object file
src/UserResource.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/restserver.dir/build.make CMakeFiles/restserver.dir/src/UserResource.cpp.o
.PHONY : src/UserResource.cpp.o

src/UserResource.i: src/UserResource.cpp.i

.PHONY : src/UserResource.i

# target to preprocess a source file
src/UserResource.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/restserver.dir/build.make CMakeFiles/restserver.dir/src/UserResource.cpp.i
.PHONY : src/UserResource.cpp.i

src/UserResource.s: src/UserResource.cpp.s

.PHONY : src/UserResource.s

# target to generate assembly for a file
src/UserResource.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/restserver.dir/build.make CMakeFiles/restserver.dir/src/UserResource.cpp.s
.PHONY : src/UserResource.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... restserver"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... src/HTTPAPIServer.o"
	@echo "... src/HTTPAPIServer.i"
	@echo "... src/HTTPAPIServer.s"
	@echo "... src/Injectable.o"
	@echo "... src/Injectable.i"
	@echo "... src/Injectable.s"
	@echo "... src/PipesResource.o"
	@echo "... src/PipesResource.i"
	@echo "... src/PipesResource.s"
	@echo "... src/RequestRouter.o"
	@echo "... src/RequestRouter.i"
	@echo "... src/RequestRouter.s"
	@echo "... src/ResourceFactory.o"
	@echo "... src/ResourceFactory.i"
	@echo "... src/ResourceFactory.s"
	@echo "... src/StaticContentServ.o"
	@echo "... src/StaticContentServ.i"
	@echo "... src/StaticContentServ.s"
	@echo "... src/UserResource.o"
	@echo "... src/UserResource.i"
	@echo "... src/UserResource.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

