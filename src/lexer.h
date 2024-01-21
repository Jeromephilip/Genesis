#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <string>
#include "token.h"

class Lexer {
    std::string input;
    int position;
    int peek;
    char currentChar;

    Lexer(std::string input, int position, char currentChar); // constructor
    
    std::string readChar(); // read the current character

    Token returnToken();// return the corresponding token type
};

#endif LEXER_H