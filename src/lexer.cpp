#include "lexer.h"
#include <string>
#include <ctype>

Lexer::Lexer(std::string input) {
    this->input = input;
    this->curPos = 0;
    this->peek = 0; // char to peek at
    this->currentChar = "";
};  

void Lexer::readChar() {
    if (this->peek >= input.length()) {
        this->currentChar = '\0';
    } else {
        this->currentChar = this->input[peek];
    }

    this->curPos = this->peek;
    this->peek += 1;
}

Token Lexer::nextToken() {
    Token t;

    this->skipWhiteSpace();

    if (this->currentChar == "}") {
        t = Token{RBRACK, this->currentChar};
    } else if (this->currentChar == "{") {
        t = Token{LBRACK, this->currentChar};
    } else if (this->currentChar == ")") {
        t = Token{RBRACK, this->currentChar};
    } else if (this->currentChar == "(") {
        t = Token{LBRACK, this->currentChar};
    } else if (this->currentChar == "+") {
        t = Token{PLUS, this->currentChar};
    } else if (this->currentChar == ",") {
        t = Token{COMMA, this->currentChar};
    } else if (this->currentChar == "=") {
        t = Token{ASSIGN, this->currentChar};
    } else if (this->currentChar == ";") {
        t = Token{SEMICOLON, this->currentChar};
    } else if (this->currentChar == ":") {
        t = Token{COLON, this->currentChar};
    } else if (isalpha(this->currentChar)) {
        id = this->findIdentifier();
        if (keyIds.find(id) != keyIds.end()) {
            t = Token{keyIds[id], id};
        }
    } else {
        t = Token{END_FILE, ""};
    }
    this->readChar();
    return t;
}

void Lexer::skipWhiteSpace() {
    if (this->currentChar == " " || this->currentChar == "\n" || this->currentChar == "\t" || this->currentChar == "\r") {
        this->readChar();
    }
}

std::string Lexer::findIdentifier() {
    std::string id = "";
    while (isalpha(this->currentChar)) {
        id += this->currentChar;
    }
    return id;
}

void Lexer::printTokens(const std::vector<Token> tokens) {
    for (auto c : tokens) {
        if (c.type == tokenType::RBRACK) {
            std::cout << "RBRACK" << std::endl;
        } else if (c.type == tokenType::LBRACK) {
            std::cout << "LBRACK" << std::endl;
        } else if (c.type == tokenType::LPAREN) {
            std::cout << "LPAREN" << std::endl;
        } else if (c.type == tokenType::RPAREN) {
            std::cout << "RPAREN" << std::endl;
        } else if (c.type == tokenType::FUNCTION) {
            std::cout << "FUNCTION" << std::endl;
        } else if (c.type == tokenType::VAR) {
            std::cout << "VAR" << std::endl;
        } else if (c.type == tokenType::ASSIGN) {
            std::cout << "ASSIGN" << std::endl;
        } else if (c.type == tokenType::PRINT) {
            std::cout << "PRINT" << std::endl;
        } else if (c.type == tokenType::PLUS) {
            std::cout << "PLUS" << std::endl;
        } else if (c.type == tokenType::COMMA) {
            std::cout << "COMMA" << std::endl;
        } else if (c.type == tokenType::SEMICOLON) {
            std::cout << "SEMICOLON" << std::endl;
        } else if (c.type == tokenType::COLON) {
            std::cout << "COLON" << std::endl;
        }
    }
}