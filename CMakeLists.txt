cmake_minimum_required(VERSION 3.10)

# Set project name
project(genesis)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include FetchContent module to download Google Test
include(FetchContent)

# Download and add Google Test
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)

# Fetch Google Test content
FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

# Add subdirectories for source and tests
add_subdirectory(src)
add_subdirectory(tests)
