# Add the library for the source files
add_library(lexer_lib lexer.cc)

# Create an executable for your application if needed
add_executable(lexer main.cc)

# Link the library with the executable
target_link_libraries(lexer PRIVATE lexer_lib)