# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\TodoApp_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TodoApp_autogen.dir\\ParseCache.txt"
  "TodoApp_autogen"
  )
endif()
