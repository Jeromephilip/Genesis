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

};

struct Token {
    tokenType type;
    std::string val;
};

#endif TOKEN_H