# Install script for directory: /usr/local/src/opentx/opentx-2.0.14/companion/src

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "0")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF(EXISTS "$ENV{DESTDIR}/usr/local/bin/companion" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/bin/companion")
    FILE(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/local/bin/companion"
         RPATH "")
  ENDIF()
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/usr/local/bin/companion")
FILE(INSTALL DESTINATION "/usr/local/bin" TYPE EXECUTABLE FILES "/usr/local/src/opentx/opentx-2.0.14/companion/lbuild/companion")
  IF(EXISTS "$ENV{DESTDIR}/usr/local/bin/companion" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/bin/companion")
    FILE(RPATH_REMOVE
         FILE "$ENV{DESTDIR}/usr/local/bin/companion")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/local/bin/companion")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/applications" TYPE FILE FILES "/usr/local/src/opentx/opentx-2.0.14/companion/src/companion.desktop")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/usr/share/icons/hicolor/16x16/apps/companion.png")
FILE(INSTALL DESTINATION "/usr/share/icons/hicolor/16x16/apps" TYPE FILE FILES "/usr/local/src/opentx/opentx-2.0.14/companion/src/images/linuxicons/16x16/companion.png")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/usr/share/icons/hicolor/22x22/apps/companion.png")
FILE(INSTALL DESTINATION "/usr/share/icons/hicolor/22x22/apps" TYPE FILE FILES "/usr/local/src/opentx/opentx-2.0.14/companion/src/images/linuxicons/22x22/companion.png")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/usr/share/icons/hicolor/24x24/apps/companion.png")
FILE(INSTALL DESTINATION "/usr/share/icons/hicolor/24x24/apps" TYPE FILE FILES "/usr/local/src/opentx/opentx-2.0.14/companion/src/images/linuxicons/24x24/companion.png")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/usr/share/icons/hicolor/32x32/apps/companion.png")
FILE(INSTALL DESTINATION "/usr/share/icons/hicolor/32x32/apps" TYPE FILE FILES "/usr/local/src/opentx/opentx-2.0.14/companion/src/images/linuxicons/32x32/companion.png")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/usr/share/icons/hicolor/48x48/apps/companion.png")
FILE(INSTALL DESTINATION "/usr/share/icons/hicolor/48x48/apps" TYPE FILE FILES "/usr/local/src/opentx/opentx-2.0.14/companion/src/images/linuxicons/48x48/companion.png")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/usr/share/icons/hicolor/128x128/apps/companion.png")
FILE(INSTALL DESTINATION "/usr/share/icons/hicolor/128x128/apps" TYPE FILE FILES "/usr/local/src/opentx/opentx-2.0.14/companion/src/images/linuxicons/128x128/companion.png")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/usr/share/icons/hicolor/256x256/apps/companion.png")
FILE(INSTALL DESTINATION "/usr/share/icons/hicolor/256x256/apps" TYPE FILE FILES "/usr/local/src/opentx/opentx-2.0.14/companion/src/images/linuxicons/256x256/companion.png")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/usr/share/icons/hicolor/512x512/apps/companion.png")
FILE(INSTALL DESTINATION "/usr/share/icons/hicolor/512x512/apps" TYPE FILE FILES "/usr/local/src/opentx/opentx-2.0.14/companion/src/images/linuxicons/512x512/companion.png")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/usr/share/icons/hicolor/scalable/apps/companion.svg")
FILE(INSTALL DESTINATION "/usr/share/icons/hicolor/scalable/apps" TYPE FILE FILES "/usr/local/src/opentx/opentx-2.0.14/companion/src/images/linuxicons/scalable/companion.svg")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/etc/udev/rules.d/45-companion-taranis.rules")
FILE(INSTALL DESTINATION "/etc/udev/rules.d" TYPE FILE FILES "/usr/local/src/opentx/opentx-2.0.14/companion/src/../targets/linux/45-companion-taranis.rules")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("/usr/local/src/opentx/opentx-2.0.14/companion/lbuild/modeledit/cmake_install.cmake")
  INCLUDE("/usr/local/src/opentx/opentx-2.0.14/companion/lbuild/simulation/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

IF(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
ELSE(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
ENDIF(CMAKE_INSTALL_COMPONENT)

FILE(WRITE "/usr/local/src/opentx/opentx-2.0.14/companion/lbuild/${CMAKE_INSTALL_MANIFEST}" "")
FOREACH(file ${CMAKE_INSTALL_MANIFEST_FILES})
  FILE(APPEND "/usr/local/src/opentx/opentx-2.0.14/companion/lbuild/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
ENDFOREACH(file)
