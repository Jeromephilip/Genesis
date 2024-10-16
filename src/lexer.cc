#include "lexer.h"
#include <string>
#include <cctype>
#include <unordered_map>
#include <vector>
#include <iostream>

Lexer::Lexer(std::string input)
    : input(std::move(input)), curPos(0), peek(0), currentChar('\0'), keyIds({
        {"int", INT},
        {"string", STRING},
        {"func", FUNCTION},
        {"print", PRINT},
        {"char", CHAR},
        {"float", FLOAT}
    }) {
    readChar();  // Initialize with the first character
}
void Lexer::readChar() {
    currentChar = (peek >= input.length()) ? '\0' : input[peek];
    curPos = peek;
    peek += 1;
}

Token Lexer::nextToken() {
    Token token;
    skipWhiteSpace();  // Skip leading whitespace

    static const std::unordered_map<char, TokenType> singleCharTokens = {
        {'}', RBRACK}, {'{', LBRACK}, {')', RPAREN}, {'(', LPAREN}, 
        {'+', PLUS}, {',', COMMA}, {'=', ASSIGN}, {';', SEMICOLON}, 
        {':', COLON}
    };

    auto it = singleCharTokens.find(currentChar);
    if (it != singleCharTokens.end()) {
        token = Token{it->second, std::string(1, currentChar)};
    } else if (isalpha(currentChar)) {
        std::string identifier = findIdentifier();
        token = Token{keyIds.count(identifier) ? keyIds.at(identifier) : ILLEGAL, identifier};
    } else if (isdigit(currentChar)) {
        token = Token{INT, findIdentifier()};
    } else if (currentChar == '\0') {
        token = Token{END_FILE, ""};
    }

    readChar();
    return token;
}

void Lexer::skipWhiteSpace() {
    while (isspace(currentChar)) {
        readChar();
    }
}

std::string Lexer::findIdentifier() {
    std::string id;
    while (isalpha(currentChar)) {
        id += currentChar;
        readChar();  // Read the next character
    }
    return id;
}

void Lexer::printTokens(const std::__1::vector<Token>& tokens) const {
    for (const auto& token : tokens) {
        switch (token.type) {
            case RBRACK: std::cout << "RBRACK\n"; break;
            case LBRACK: std::cout << "LBRACK\n"; break;
            case LPAREN: std::cout << "LPAREN\n"; break;
            case RPAREN: std::cout << "RPAREN\n"; break;
            case FUNCTION: std::cout << "FUNCTION\n"; break;
            case ASSIGN: std::cout << "ASSIGN\n"; break;
            case PRINT: std::cout << "PRINT\n"; break;
            case PLUS: std::cout << "PLUS\n"; break;
            case COMMA: std::cout << "COMMA\n"; break;
            case SEMICOLON: std::cout << "SEMICOLON\n"; break;
            case COLON: std::cout << "COLON\n"; break;
            default: std::cout << "UNKNOWN TOKEN\n"; break;
        }
    }
}
