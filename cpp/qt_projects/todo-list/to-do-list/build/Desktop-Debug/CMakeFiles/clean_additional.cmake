# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/to-do-list_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/to-do-list_autogen.dir/ParseCache.txt"
  "to-do-list_autogen"
  )
endif()
