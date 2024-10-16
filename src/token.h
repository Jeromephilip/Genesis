#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <string>

enum TokenType {
    ILLEGAL,
    END_FILE,

    RBRACK,  // }
    LBRACK,  // {
    LPAREN,  // (
    RPAREN,  // )

    FUNCTION,
    VAR,
    ASSIGN,  // =
    PRINT,

    PLUS,    // +
    COMMA,   // ,
    SEMICOLON, // ;
    COLON,   // :

    INT,
    STRING,
    CHAR,
    FLOAT
};

struct Token {
    TokenType type;
    std::string val;  // Changed from char to std::string for flexibility

    Token() : type(ILLEGAL), val("") {}  // Default constructor

    Token(TokenType t, const std::string& v) : type(t), val(v) {}  // Parameterized constructor

    // Overload the << operator for easy printing of Token
    friend std::ostream& operator<<(std::ostream& os, const Token& token) {
        os << "Type: " << token.type << ", Value: " << token.val;
        return os;
    }
};

#endif
