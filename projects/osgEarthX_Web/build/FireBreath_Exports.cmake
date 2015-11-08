# Generated by CMake 3.1.1

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.5)
   message(FATAL_ERROR "CMake >= 2.6.0 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.6)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_targetsDefined)
set(_targetsNotDefined)
set(_expectedTargets)
foreach(_expectedTarget boost_thread boost_system ScriptingCore PluginCore NpapiCore ActiveXCore UnitTest++)
  list(APPEND _expectedTargets ${_expectedTarget})
  if(NOT TARGET ${_expectedTarget})
    list(APPEND _targetsNotDefined ${_expectedTarget})
  endif()
  if(TARGET ${_expectedTarget})
    list(APPEND _targetsDefined ${_expectedTarget})
  endif()
endforeach()
if("${_targetsDefined}" STREQUAL "${_expectedTargets}")
  set(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT "${_targetsDefined}" STREQUAL "")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_targetsDefined}\nTargets not yet defined: ${_targetsNotDefined}\n")
endif()
unset(_targetsDefined)
unset(_targetsNotDefined)
unset(_expectedTargets)


# Create imported target boost_thread
add_library(boost_thread STATIC IMPORTED)

# Create imported target boost_system
add_library(boost_system STATIC IMPORTED)

# Create imported target ScriptingCore
add_library(ScriptingCore STATIC IMPORTED)

# Create imported target PluginCore
add_library(PluginCore STATIC IMPORTED)

# Create imported target NpapiCore
add_library(NpapiCore STATIC IMPORTED)

# Create imported target ActiveXCore
add_library(ActiveXCore STATIC IMPORTED)

# Create imported target UnitTest++
add_library(UnitTest++ STATIC IMPORTED)

# Import target "boost_thread" for configuration "Debug"
set_property(TARGET boost_thread APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(boost_thread PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "E:/OpenSceneGraph/osgEarthX/projects/osgEarthX_Web/build/boost/libs/thread/Debug/boost_thread.lib"
  )

# Import target "boost_system" for configuration "Debug"
set_property(TARGET boost_system APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(boost_system PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "E:/OpenSceneGraph/osgEarthX/projects/osgEarthX_Web/build/boost/libs/system/Debug/boost_system.lib"
  )

# Import target "ScriptingCore" for configuration "Debug"
set_property(TARGET ScriptingCore APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(ScriptingCore PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "boost_thread;boost_system"
  IMPORTED_LOCATION_DEBUG "E:/OpenSceneGraph/osgEarthX/projects/osgEarthX_Web/build/ScriptingCore/Debug/ScriptingCore.lib"
  )

# Import target "PluginCore" for configuration "Debug"
set_property(TARGET PluginCore APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(PluginCore PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "E:/OpenSceneGraph/osgEarthX/projects/osgEarthX_Web/build/PluginCore/Debug/PluginCore.lib"
  )

# Import target "NpapiCore" for configuration "Debug"
set_property(TARGET NpapiCore APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(NpapiCore PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "boost_thread;boost_system"
  IMPORTED_LOCATION_DEBUG "E:/OpenSceneGraph/osgEarthX/projects/osgEarthX_Web/build/NpapiCore/Debug/NpapiCore.lib"
  )

# Import target "ActiveXCore" for configuration "Debug"
set_property(TARGET ActiveXCore APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(ActiveXCore PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "boost_thread;boost_system;PluginCore;ScriptingCore"
  IMPORTED_LOCATION_DEBUG "E:/OpenSceneGraph/osgEarthX/projects/osgEarthX_Web/build/ActiveXCore/Debug/ActiveXCore.lib"
  )

# Import target "UnitTest++" for configuration "Debug"
set_property(TARGET UnitTest++ APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(UnitTest++ PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "E:/OpenSceneGraph/osgEarthX/projects/osgEarthX_Web/build/unittest-cpp/UnitTest++/Debug/UnitTest++.lib"
  )

# Import target "boost_thread" for configuration "Release"
set_property(TARGET boost_thread APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(boost_thread PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "E:/OpenSceneGraph/osgEarthX/projects/osgEarthX_Web/build/boost/libs/thread/Release/boost_thread.lib"
  )

# Import target "boost_system" for configuration "Release"
set_property(TARGET boost_system APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(boost_system PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "E:/OpenSceneGraph/osgEarthX/projects/osgEarthX_Web/build/boost/libs/system/Release/boost_system.lib"
  )

# Import target "ScriptingCore" for configuration "Release"
set_property(TARGET ScriptingCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(ScriptingCore PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "boost_thread;boost_system"
  IMPORTED_LOCATION_RELEASE "E:/OpenSceneGraph/osgEarthX/projects/osgEarthX_Web/build/ScriptingCore/Release/ScriptingCore.lib"
  )

# Import target "PluginCore" for configuration "Release"
set_property(TARGET PluginCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(PluginCore PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "E:/OpenSceneGraph/osgEarthX/projects/osgEarthX_Web/build/PluginCore/Release/PluginCore.lib"
  )

# Import target "NpapiCore" for configuration "Release"
set_property(TARGET NpapiCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(NpapiCore PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "boost_thread;boost_system"
  IMPORTED_LOCATION_RELEASE "E:/OpenSceneGraph/osgEarthX/projects/osgEarthX_Web/build/NpapiCore/Release/NpapiCore.lib"
  )

# Import target "ActiveXCore" for configuration "Release"
set_property(TARGET ActiveXCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(ActiveXCore PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "boost_thread;boost_system;PluginCore;ScriptingCore"
  IMPORTED_LOCATION_RELEASE "E:/OpenSceneGraph/osgEarthX/projects/osgEarthX_Web/build/ActiveXCore/Release/ActiveXCore.lib"
  )

# Import target "UnitTest++" for configuration "Release"
set_property(TARGET UnitTest++ APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(UnitTest++ PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "E:/OpenSceneGraph/osgEarthX/projects/osgEarthX_Web/build/unittest-cpp/UnitTest++/Release/UnitTest++.lib"
  )

# Import target "boost_thread" for configuration "MinSizeRel"
set_property(TARGET boost_thread APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(boost_thread PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_MINSIZEREL "CXX"
  IMPORTED_LOCATION_MINSIZEREL "E:/OpenSceneGraph/osgEarthX/projects/osgEarthX_Web/build/boost/libs/thread/MinSizeRel/boost_thread.lib"
  )

# Import target "boost_system" for configuration "MinSizeRel"
set_property(TARGET boost_system APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(boost_system PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_MINSIZEREL "CXX"
  IMPORTED_LOCATION_MINSIZEREL "E:/OpenSceneGraph/osgEarthX/projects/osgEarthX_Web/build/boost/libs/system/MinSizeRel/boost_system.lib"
  )

# Import target "ScriptingCore" for configuration "MinSizeRel"
set_property(TARGET ScriptingCore APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(ScriptingCore PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_MINSIZEREL "CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_MINSIZEREL "boost_thread;boost_system"
  IMPORTED_LOCATION_MINSIZEREL "E:/OpenSceneGraph/osgEarthX/projects/osgEarthX_Web/build/ScriptingCore/MinSizeRel/ScriptingCore.lib"
  )

# Import target "PluginCore" for configuration "MinSizeRel"
set_property(TARGET PluginCore APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(PluginCore PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_MINSIZEREL "CXX"
  IMPORTED_LOCATION_MINSIZEREL "E:/OpenSceneGraph/osgEarthX/projects/osgEarthX_Web/build/PluginCore/MinSizeRel/PluginCore.lib"
  )

# Import target "NpapiCore" for configuration "MinSizeRel"
set_property(TARGET NpapiCore APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(NpapiCore PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_MINSIZEREL "CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_MINSIZEREL "boost_thread;boost_system"
  IMPORTED_LOCATION_MINSIZEREL "E:/OpenSceneGraph/osgEarthX/projects/osgEarthX_Web/build/NpapiCore/MinSizeRel/NpapiCore.lib"
  )

# Import target "ActiveXCore" for configuration "MinSizeRel"
set_property(TARGET ActiveXCore APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(ActiveXCore PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_MINSIZEREL "CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_MINSIZEREL "boost_thread;boost_system;PluginCore;ScriptingCore"
  IMPORTED_LOCATION_MINSIZEREL "E:/OpenSceneGraph/osgEarthX/projects/osgEarthX_Web/build/ActiveXCore/MinSizeRel/ActiveXCore.lib"
  )

# Import target "UnitTest++" for configuration "MinSizeRel"
set_property(TARGET UnitTest++ APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(UnitTest++ PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_MINSIZEREL "CXX"
  IMPORTED_LOCATION_MINSIZEREL "E:/OpenSceneGraph/osgEarthX/projects/osgEarthX_Web/build/unittest-cpp/UnitTest++/MinSizeRel/UnitTest++.lib"
  )

# Import target "boost_thread" for configuration "RelWithDebInfo"
set_property(TARGET boost_thread APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(boost_thread PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "CXX"
  IMPORTED_LOCATION_RELWITHDEBINFO "E:/OpenSceneGraph/osgEarthX/projects/osgEarthX_Web/build/boost/libs/thread/RelWithDebInfo/boost_thread.lib"
  )

# Import target "boost_system" for configuration "RelWithDebInfo"
set_property(TARGET boost_system APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(boost_system PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "CXX"
  IMPORTED_LOCATION_RELWITHDEBINFO "E:/OpenSceneGraph/osgEarthX/projects/osgEarthX_Web/build/boost/libs/system/RelWithDebInfo/boost_system.lib"
  )

# Import target "ScriptingCore" for configuration "RelWithDebInfo"
set_property(TARGET ScriptingCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(ScriptingCore PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELWITHDEBINFO "boost_thread;boost_system"
  IMPORTED_LOCATION_RELWITHDEBINFO "E:/OpenSceneGraph/osgEarthX/projects/osgEarthX_Web/build/ScriptingCore/RelWithDebInfo/ScriptingCore.lib"
  )

# Import target "PluginCore" for configuration "RelWithDebInfo"
set_property(TARGET PluginCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(PluginCore PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "CXX"
  IMPORTED_LOCATION_RELWITHDEBINFO "E:/OpenSceneGraph/osgEarthX/projects/osgEarthX_Web/build/PluginCore/RelWithDebInfo/PluginCore.lib"
  )

# Import target "NpapiCore" for configuration "RelWithDebInfo"
set_property(TARGET NpapiCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(NpapiCore PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELWITHDEBINFO "boost_thread;boost_system"
  IMPORTED_LOCATION_RELWITHDEBINFO "E:/OpenSceneGraph/osgEarthX/projects/osgEarthX_Web/build/NpapiCore/RelWithDebInfo/NpapiCore.lib"
  )

# Import target "ActiveXCore" for configuration "RelWithDebInfo"
set_property(TARGET ActiveXCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(ActiveXCore PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELWITHDEBINFO "boost_thread;boost_system;PluginCore;ScriptingCore"
  IMPORTED_LOCATION_RELWITHDEBINFO "E:/OpenSceneGraph/osgEarthX/projects/osgEarthX_Web/build/ActiveXCore/RelWithDebInfo/ActiveXCore.lib"
  )

# Import target "UnitTest++" for configuration "RelWithDebInfo"
set_property(TARGET UnitTest++ APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(UnitTest++ PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "CXX"
  IMPORTED_LOCATION_RELWITHDEBINFO "E:/OpenSceneGraph/osgEarthX/projects/osgEarthX_Web/build/unittest-cpp/UnitTest++/RelWithDebInfo/UnitTest++.lib"
  )

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)
