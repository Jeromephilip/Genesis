#include "gtest/gtest.h"
#include "token.h"
#include "lexer.h"
#include <string>

TEST(LexerTest, TokenizeSymbols1) {
    // Arrange
    std::string s = ":;+=\n";
    // Lexer *l = new Lexer(s);
    std::unique_ptr<Lexer> l(new Lexer(s));
    
    // Act
    std::vector<Token> tokens;
    for (char c : s) {
        tokens.push_back(l->nextToken());
    }

    l->printTokens(tokens);
    // Assert
    ASSERT_EQ(tokens.size(), 5);
    ASSERT_EQ(tokens[0].type, TokenType::COLON);
    ASSERT_EQ(tokens[1].type, TokenType::SEMICOLON);
    ASSERT_EQ(tokens[2].type, TokenType::PLUS);
    ASSERT_EQ(tokens[3].type, TokenType::ASSIGN);
}