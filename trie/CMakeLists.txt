cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories("../")
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(testTrie trie_gtest.cpp)
target_link_libraries(testTrie ${GTEST_LIBRARIES} pthread)