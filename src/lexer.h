#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <string>
#include <vector>
#include "token.h"
#include <unordered_map>

class Lexer {
    private:
        std::string input;
        int curPos;
        int peek;
        std::string currentChar;
        std::unordered_map<std::string, tokenType> keyIds = {
            {"int", INT},
            {"string", STRING},
            {"func", FUNCTION},
            {"print", PRINT},
            {"char", CHAR},
            {"float", FLOAT}
        };
    public:
        Lexer(std::string ); // constructor
        void readChar(); // read the current character
        Token nextToken();// return the corresponding token type
        void printTokens(const std::vector<Token> );
        bool skipWhiteSpace();
        std::string findIdentifier();
};

#endif