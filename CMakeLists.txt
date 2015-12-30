##---------------------------------------------------------------------------##
# A) Define your project name and set up major project options
##---------------------------------------------------------------------------##

INCLUDE(${CMAKE_SOURCE_DIR}/ProjectName.cmake)

# CMake requires that you declare the CMake project in the top-level file and
# not in an include file :-(
PROJECT(${PROJECT_NAME} NONE)

# Add support for extra repositories; everything handled by native above
SET(${PROJECT_NAME}_SUPPORT_EXTRA_REPOS FALSE)

# Disable Tribits generating HTML dependencies webpage and xml files
SET(${PROJECT_NAME}_DEPS_XML_OUTPUT_FILE OFF CACHE BOOL "" )

# Disable Tribits export system to save time configuring
SET(${PROJECT_NAME}_ENABLE_INSTALL_CMAKE_CONFIG_FILES OFF CACHE BOOL "")

# Disable Tribits export makefiles system to save time configuring
SET(${PROJECT_NAME}_ENABLE_EXPORT_MAKEFILES OFF CACHE BOOL "")

##---------------------------------------------------------------------------##
# B) Pull in the TriBITS system and execute
##---------------------------------------------------------------------------##

# Just use the TriBITS system in Trilinos
SET(${PROJECT_NAME}_TRIBITS_DIR
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake/tribits" CACHE PATH "" )
MESSAGE("${PROJECT_NAME}_TRIBITS_DIR = '${${PROJECT_NAME}_TRIBITS_DIR}'")
INCLUDE(${${PROJECT_NAME}_TRIBITS_DIR}/TriBITS.cmake)

# CMake requires this be in the top file and not in an include file :-(
CMAKE_MINIMUM_REQUIRED(VERSION ${TRIBITS_CMAKE_MINIMUM_REQUIRED})

# Do all of the processing for this Tribits project
TRIBITS_PROJECT()

##---------------------------------------------------------------------------##
## end of CMakeLists.txt
##---------------------------------------------------------------------------##
