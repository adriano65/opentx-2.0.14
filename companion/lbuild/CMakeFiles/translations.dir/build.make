# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /usr/local/src/opentx/opentx-v2.0.14a/companion/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /usr/local/src/opentx/opentx-v2.0.14a/companion/lbuild

# Utility rule file for translations.

# Include the progress variables for this target.
include CMakeFiles/translations.dir/progress.make

CMakeFiles/translations:
	cd /usr/local/src/opentx/opentx-v2.0.14a/companion/src && lupdate-qt4 /usr/local/src/opentx/opentx-v2.0.14a/companion/src -ts translations/companion_he.ts translations/companion_pl.ts translations/companion_pt.ts translations/companion_ru.ts translations/companion_de.ts translations/companion_fr.ts translations/companion_it.ts translations/companion_sv.ts translations/companion_cs.ts translations/companion_fi.ts translations/companion_nl.ts

translations: CMakeFiles/translations
translations: CMakeFiles/translations.dir/build.make
.PHONY : translations

# Rule to build all files generated by this target.
CMakeFiles/translations.dir/build: translations
.PHONY : CMakeFiles/translations.dir/build

CMakeFiles/translations.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/translations.dir/cmake_clean.cmake
.PHONY : CMakeFiles/translations.dir/clean

CMakeFiles/translations.dir/depend:
	cd /usr/local/src/opentx/opentx-v2.0.14a/companion/lbuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /usr/local/src/opentx/opentx-v2.0.14a/companion/src /usr/local/src/opentx/opentx-v2.0.14a/companion/src /usr/local/src/opentx/opentx-v2.0.14a/companion/lbuild /usr/local/src/opentx/opentx-v2.0.14a/companion/lbuild /usr/local/src/opentx/opentx-v2.0.14a/companion/lbuild/CMakeFiles/translations.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/translations.dir/depend
