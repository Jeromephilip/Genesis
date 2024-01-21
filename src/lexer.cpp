#include "lexer.h"
#include <string>

Lexer::Lexer(std::string input) {
    this->input = input;
    this->curPos = 0;
    this->peek = 0; // char to peek at
    this.curChar = input[0]
};  

std::string Lexer::readChar() {
    if (this->peek >= input.length) {
        this->curChar = '';
    } else {
        this->currentChar = this->input[peek];
    }

    this->curPos = this->peek;
    this->peek += 1
}

Token Lexer::returnToken() {
    switch (this->curChar) {
        case '}':
            return RBRACK;
        case '{':
            return LBRACK;
        case ')':
            return RBRACE;
        case '(':
            return LBRACE;
        case '+':
            return PLUS;
        case ',':
            return COMMA;
        case '=':
            return ASSIGN;
        case ';':
            return SEMICOLON;
        case '':
            return END_FILE;
    }
}


