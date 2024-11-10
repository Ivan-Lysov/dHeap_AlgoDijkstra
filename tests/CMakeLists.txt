set(target ${MP2_TESTS})


file(GLOB_RECURSE hdrs "*.h*")
file(GLOB_RECURSE srcs "*.cpp")

include_directories("${MP2_INCLUDE}" "../gtest")

add_executable(${target} ${srcs} ${hdrs})
target_link_libraries(${target} gtest ${MP2_LIBRARY})