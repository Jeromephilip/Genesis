# Add the test executable
add_executable(lexer_test lexer_test.cc)

# Add the src directory to the include path
target_include_directories(lexer_test PRIVATE ${CMAKE_SOURCE_DIR}/src)

# Link Google Test and the lexer library
target_link_libraries(lexer_test PRIVATE gtest gtest_main lexer_lib)

# Enable Google Test discovery
include(GoogleTest)
gtest_discover_tests(lexer_test)
