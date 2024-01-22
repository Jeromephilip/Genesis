#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <string>

enum tokenType {
    ILLEGAL,
    END_FILE,

    RBRACK,
    LBRACK,
    LPAREN,
    RPAREN,

    FUNCTION,
    VAR,
    ASSIGN,
    PRINT,

    PLUS,
    COMMA,
    SEMICOLON,
    COLON

    INT,
    STRING,
    CHAR,
    FLOAT
};

struct Token {
    tokenType type;
    std::string val;
};

#endif