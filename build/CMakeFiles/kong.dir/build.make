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

# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_SOURCE_DIR = /root/Job/dejavu

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/Job/dejavu/build

# Include any dependencies generated for this target.
include CMakeFiles/kong.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/kong.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/kong.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/kong.dir/flags.make

CMakeFiles/kong.dir/kong/Buffer.cc.o: CMakeFiles/kong.dir/flags.make
CMakeFiles/kong.dir/kong/Buffer.cc.o: ../kong/Buffer.cc
CMakeFiles/kong.dir/kong/Buffer.cc.o: CMakeFiles/kong.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Job/dejavu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/kong.dir/kong/Buffer.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/kong.dir/kong/Buffer.cc.o -MF CMakeFiles/kong.dir/kong/Buffer.cc.o.d -o CMakeFiles/kong.dir/kong/Buffer.cc.o -c /root/Job/dejavu/kong/Buffer.cc

CMakeFiles/kong.dir/kong/Buffer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kong.dir/kong/Buffer.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Job/dejavu/kong/Buffer.cc > CMakeFiles/kong.dir/kong/Buffer.cc.i

CMakeFiles/kong.dir/kong/Buffer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kong.dir/kong/Buffer.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Job/dejavu/kong/Buffer.cc -o CMakeFiles/kong.dir/kong/Buffer.cc.s

CMakeFiles/kong.dir/kong/Epoller.cc.o: CMakeFiles/kong.dir/flags.make
CMakeFiles/kong.dir/kong/Epoller.cc.o: ../kong/Epoller.cc
CMakeFiles/kong.dir/kong/Epoller.cc.o: CMakeFiles/kong.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Job/dejavu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/kong.dir/kong/Epoller.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/kong.dir/kong/Epoller.cc.o -MF CMakeFiles/kong.dir/kong/Epoller.cc.o.d -o CMakeFiles/kong.dir/kong/Epoller.cc.o -c /root/Job/dejavu/kong/Epoller.cc

CMakeFiles/kong.dir/kong/Epoller.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kong.dir/kong/Epoller.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Job/dejavu/kong/Epoller.cc > CMakeFiles/kong.dir/kong/Epoller.cc.i

CMakeFiles/kong.dir/kong/Epoller.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kong.dir/kong/Epoller.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Job/dejavu/kong/Epoller.cc -o CMakeFiles/kong.dir/kong/Epoller.cc.s

CMakeFiles/kong.dir/kong/httpconn.cc.o: CMakeFiles/kong.dir/flags.make
CMakeFiles/kong.dir/kong/httpconn.cc.o: ../kong/httpconn.cc
CMakeFiles/kong.dir/kong/httpconn.cc.o: CMakeFiles/kong.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Job/dejavu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/kong.dir/kong/httpconn.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/kong.dir/kong/httpconn.cc.o -MF CMakeFiles/kong.dir/kong/httpconn.cc.o.d -o CMakeFiles/kong.dir/kong/httpconn.cc.o -c /root/Job/dejavu/kong/httpconn.cc

CMakeFiles/kong.dir/kong/httpconn.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kong.dir/kong/httpconn.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Job/dejavu/kong/httpconn.cc > CMakeFiles/kong.dir/kong/httpconn.cc.i

CMakeFiles/kong.dir/kong/httpconn.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kong.dir/kong/httpconn.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Job/dejavu/kong/httpconn.cc -o CMakeFiles/kong.dir/kong/httpconn.cc.s

CMakeFiles/kong.dir/kong/httprequest.cc.o: CMakeFiles/kong.dir/flags.make
CMakeFiles/kong.dir/kong/httprequest.cc.o: ../kong/httprequest.cc
CMakeFiles/kong.dir/kong/httprequest.cc.o: CMakeFiles/kong.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Job/dejavu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/kong.dir/kong/httprequest.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/kong.dir/kong/httprequest.cc.o -MF CMakeFiles/kong.dir/kong/httprequest.cc.o.d -o CMakeFiles/kong.dir/kong/httprequest.cc.o -c /root/Job/dejavu/kong/httprequest.cc

CMakeFiles/kong.dir/kong/httprequest.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kong.dir/kong/httprequest.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Job/dejavu/kong/httprequest.cc > CMakeFiles/kong.dir/kong/httprequest.cc.i

CMakeFiles/kong.dir/kong/httprequest.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kong.dir/kong/httprequest.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Job/dejavu/kong/httprequest.cc -o CMakeFiles/kong.dir/kong/httprequest.cc.s

CMakeFiles/kong.dir/kong/httpresponse.cc.o: CMakeFiles/kong.dir/flags.make
CMakeFiles/kong.dir/kong/httpresponse.cc.o: ../kong/httpresponse.cc
CMakeFiles/kong.dir/kong/httpresponse.cc.o: CMakeFiles/kong.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Job/dejavu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/kong.dir/kong/httpresponse.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/kong.dir/kong/httpresponse.cc.o -MF CMakeFiles/kong.dir/kong/httpresponse.cc.o.d -o CMakeFiles/kong.dir/kong/httpresponse.cc.o -c /root/Job/dejavu/kong/httpresponse.cc

CMakeFiles/kong.dir/kong/httpresponse.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kong.dir/kong/httpresponse.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Job/dejavu/kong/httpresponse.cc > CMakeFiles/kong.dir/kong/httpresponse.cc.i

CMakeFiles/kong.dir/kong/httpresponse.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kong.dir/kong/httpresponse.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Job/dejavu/kong/httpresponse.cc -o CMakeFiles/kong.dir/kong/httpresponse.cc.s

CMakeFiles/kong.dir/kong/Log.cc.o: CMakeFiles/kong.dir/flags.make
CMakeFiles/kong.dir/kong/Log.cc.o: ../kong/Log.cc
CMakeFiles/kong.dir/kong/Log.cc.o: CMakeFiles/kong.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Job/dejavu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/kong.dir/kong/Log.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/kong.dir/kong/Log.cc.o -MF CMakeFiles/kong.dir/kong/Log.cc.o.d -o CMakeFiles/kong.dir/kong/Log.cc.o -c /root/Job/dejavu/kong/Log.cc

CMakeFiles/kong.dir/kong/Log.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kong.dir/kong/Log.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Job/dejavu/kong/Log.cc > CMakeFiles/kong.dir/kong/Log.cc.i

CMakeFiles/kong.dir/kong/Log.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kong.dir/kong/Log.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Job/dejavu/kong/Log.cc -o CMakeFiles/kong.dir/kong/Log.cc.s

CMakeFiles/kong.dir/kong/Mutex.cc.o: CMakeFiles/kong.dir/flags.make
CMakeFiles/kong.dir/kong/Mutex.cc.o: ../kong/Mutex.cc
CMakeFiles/kong.dir/kong/Mutex.cc.o: CMakeFiles/kong.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Job/dejavu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/kong.dir/kong/Mutex.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/kong.dir/kong/Mutex.cc.o -MF CMakeFiles/kong.dir/kong/Mutex.cc.o.d -o CMakeFiles/kong.dir/kong/Mutex.cc.o -c /root/Job/dejavu/kong/Mutex.cc

CMakeFiles/kong.dir/kong/Mutex.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kong.dir/kong/Mutex.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Job/dejavu/kong/Mutex.cc > CMakeFiles/kong.dir/kong/Mutex.cc.i

CMakeFiles/kong.dir/kong/Mutex.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kong.dir/kong/Mutex.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Job/dejavu/kong/Mutex.cc -o CMakeFiles/kong.dir/kong/Mutex.cc.s

CMakeFiles/kong.dir/kong/sqlconnpool.cc.o: CMakeFiles/kong.dir/flags.make
CMakeFiles/kong.dir/kong/sqlconnpool.cc.o: ../kong/sqlconnpool.cc
CMakeFiles/kong.dir/kong/sqlconnpool.cc.o: CMakeFiles/kong.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Job/dejavu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/kong.dir/kong/sqlconnpool.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/kong.dir/kong/sqlconnpool.cc.o -MF CMakeFiles/kong.dir/kong/sqlconnpool.cc.o.d -o CMakeFiles/kong.dir/kong/sqlconnpool.cc.o -c /root/Job/dejavu/kong/sqlconnpool.cc

CMakeFiles/kong.dir/kong/sqlconnpool.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kong.dir/kong/sqlconnpool.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Job/dejavu/kong/sqlconnpool.cc > CMakeFiles/kong.dir/kong/sqlconnpool.cc.i

CMakeFiles/kong.dir/kong/sqlconnpool.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kong.dir/kong/sqlconnpool.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Job/dejavu/kong/sqlconnpool.cc -o CMakeFiles/kong.dir/kong/sqlconnpool.cc.s

CMakeFiles/kong.dir/kong/Thread.cc.o: CMakeFiles/kong.dir/flags.make
CMakeFiles/kong.dir/kong/Thread.cc.o: ../kong/Thread.cc
CMakeFiles/kong.dir/kong/Thread.cc.o: CMakeFiles/kong.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Job/dejavu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/kong.dir/kong/Thread.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/kong.dir/kong/Thread.cc.o -MF CMakeFiles/kong.dir/kong/Thread.cc.o.d -o CMakeFiles/kong.dir/kong/Thread.cc.o -c /root/Job/dejavu/kong/Thread.cc

CMakeFiles/kong.dir/kong/Thread.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kong.dir/kong/Thread.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Job/dejavu/kong/Thread.cc > CMakeFiles/kong.dir/kong/Thread.cc.i

CMakeFiles/kong.dir/kong/Thread.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kong.dir/kong/Thread.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Job/dejavu/kong/Thread.cc -o CMakeFiles/kong.dir/kong/Thread.cc.s

CMakeFiles/kong.dir/kong/Timer.cc.o: CMakeFiles/kong.dir/flags.make
CMakeFiles/kong.dir/kong/Timer.cc.o: ../kong/Timer.cc
CMakeFiles/kong.dir/kong/Timer.cc.o: CMakeFiles/kong.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Job/dejavu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/kong.dir/kong/Timer.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/kong.dir/kong/Timer.cc.o -MF CMakeFiles/kong.dir/kong/Timer.cc.o.d -o CMakeFiles/kong.dir/kong/Timer.cc.o -c /root/Job/dejavu/kong/Timer.cc

CMakeFiles/kong.dir/kong/Timer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kong.dir/kong/Timer.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Job/dejavu/kong/Timer.cc > CMakeFiles/kong.dir/kong/Timer.cc.i

CMakeFiles/kong.dir/kong/Timer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kong.dir/kong/Timer.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Job/dejavu/kong/Timer.cc -o CMakeFiles/kong.dir/kong/Timer.cc.s

CMakeFiles/kong.dir/kong/Util.cc.o: CMakeFiles/kong.dir/flags.make
CMakeFiles/kong.dir/kong/Util.cc.o: ../kong/Util.cc
CMakeFiles/kong.dir/kong/Util.cc.o: CMakeFiles/kong.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Job/dejavu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/kong.dir/kong/Util.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/kong.dir/kong/Util.cc.o -MF CMakeFiles/kong.dir/kong/Util.cc.o.d -o CMakeFiles/kong.dir/kong/Util.cc.o -c /root/Job/dejavu/kong/Util.cc

CMakeFiles/kong.dir/kong/Util.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kong.dir/kong/Util.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Job/dejavu/kong/Util.cc > CMakeFiles/kong.dir/kong/Util.cc.i

CMakeFiles/kong.dir/kong/Util.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kong.dir/kong/Util.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Job/dejavu/kong/Util.cc -o CMakeFiles/kong.dir/kong/Util.cc.s

CMakeFiles/kong.dir/kong/WebServer.cc.o: CMakeFiles/kong.dir/flags.make
CMakeFiles/kong.dir/kong/WebServer.cc.o: ../kong/WebServer.cc
CMakeFiles/kong.dir/kong/WebServer.cc.o: CMakeFiles/kong.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Job/dejavu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/kong.dir/kong/WebServer.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/kong.dir/kong/WebServer.cc.o -MF CMakeFiles/kong.dir/kong/WebServer.cc.o.d -o CMakeFiles/kong.dir/kong/WebServer.cc.o -c /root/Job/dejavu/kong/WebServer.cc

CMakeFiles/kong.dir/kong/WebServer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kong.dir/kong/WebServer.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Job/dejavu/kong/WebServer.cc > CMakeFiles/kong.dir/kong/WebServer.cc.i

CMakeFiles/kong.dir/kong/WebServer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kong.dir/kong/WebServer.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Job/dejavu/kong/WebServer.cc -o CMakeFiles/kong.dir/kong/WebServer.cc.s

# Object files for target kong
kong_OBJECTS = \
"CMakeFiles/kong.dir/kong/Buffer.cc.o" \
"CMakeFiles/kong.dir/kong/Epoller.cc.o" \
"CMakeFiles/kong.dir/kong/httpconn.cc.o" \
"CMakeFiles/kong.dir/kong/httprequest.cc.o" \
"CMakeFiles/kong.dir/kong/httpresponse.cc.o" \
"CMakeFiles/kong.dir/kong/Log.cc.o" \
"CMakeFiles/kong.dir/kong/Mutex.cc.o" \
"CMakeFiles/kong.dir/kong/sqlconnpool.cc.o" \
"CMakeFiles/kong.dir/kong/Thread.cc.o" \
"CMakeFiles/kong.dir/kong/Timer.cc.o" \
"CMakeFiles/kong.dir/kong/Util.cc.o" \
"CMakeFiles/kong.dir/kong/WebServer.cc.o"

# External object files for target kong
kong_EXTERNAL_OBJECTS =

../lib/libkong.so: CMakeFiles/kong.dir/kong/Buffer.cc.o
../lib/libkong.so: CMakeFiles/kong.dir/kong/Epoller.cc.o
../lib/libkong.so: CMakeFiles/kong.dir/kong/httpconn.cc.o
../lib/libkong.so: CMakeFiles/kong.dir/kong/httprequest.cc.o
../lib/libkong.so: CMakeFiles/kong.dir/kong/httpresponse.cc.o
../lib/libkong.so: CMakeFiles/kong.dir/kong/Log.cc.o
../lib/libkong.so: CMakeFiles/kong.dir/kong/Mutex.cc.o
../lib/libkong.so: CMakeFiles/kong.dir/kong/sqlconnpool.cc.o
../lib/libkong.so: CMakeFiles/kong.dir/kong/Thread.cc.o
../lib/libkong.so: CMakeFiles/kong.dir/kong/Timer.cc.o
../lib/libkong.so: CMakeFiles/kong.dir/kong/Util.cc.o
../lib/libkong.so: CMakeFiles/kong.dir/kong/WebServer.cc.o
../lib/libkong.so: CMakeFiles/kong.dir/build.make
../lib/libkong.so: CMakeFiles/kong.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/Job/dejavu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX shared library ../lib/libkong.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/kong.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/kong.dir/build: ../lib/libkong.so
.PHONY : CMakeFiles/kong.dir/build

CMakeFiles/kong.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/kong.dir/cmake_clean.cmake
.PHONY : CMakeFiles/kong.dir/clean

CMakeFiles/kong.dir/depend:
	cd /root/Job/dejavu/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/Job/dejavu /root/Job/dejavu /root/Job/dejavu/build /root/Job/dejavu/build /root/Job/dejavu/build/CMakeFiles/kong.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/kong.dir/depend

