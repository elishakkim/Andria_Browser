# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "Andria_autogen"
  "CMakeFiles/Andria_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Andria_autogen.dir/ParseCache.txt"
  )
endif()
