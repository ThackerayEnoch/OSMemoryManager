# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\OperatingSystemWorkQtVersion_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\OperatingSystemWorkQtVersion_autogen.dir\\ParseCache.txt"
  "OperatingSystemWorkQtVersion_autogen"
  )
endif()
