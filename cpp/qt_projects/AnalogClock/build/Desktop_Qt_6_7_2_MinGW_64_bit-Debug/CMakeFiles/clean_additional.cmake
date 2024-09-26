# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "AnalogClock_autogen"
  "CMakeFiles\\AnalogClock_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\AnalogClock_autogen.dir\\ParseCache.txt"
  )
endif()
