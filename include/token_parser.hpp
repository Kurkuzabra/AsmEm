#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <regex>

enum class TokenType {
    UNDEFINED,
    WHITE_SPACES,
    NEWLINE,
    END_OF_FILE,
    INTEGER_VALUE,
    WORD,
};

struct Token {
    std::string value;
    TokenType type;
};

class TokenParser {
public:
    explicit TokenParser(std::string &input) : input_(input) {};
    bool isEmpty() const;
    bool parse(TokenType);
    void thenParse(TokenType);
    std::vector<Token> getTokens() const;
    const std::string& getLastToken() const;

private:
    std::string &input_;
    std::smatch last_match_;
    long long offset_ = 0;
    std::vector<Token> tokens_;
    std::map<TokenType, std::regex> token_regex_ = {
            {TokenType::UNDEFINED,     std::regex(".*")},
            {TokenType::WHITE_SPACES,  std::regex(R"(\s+)")},
            {TokenType::NEWLINE,       std::regex("\n")},
            {TokenType::END_OF_FILE,   std::regex("\0")},
            {TokenType::INTEGER_VALUE, std::regex("[-+]?[0-9]+")},
            {TokenType::WORD,  std::regex("[a-zA-Z_][a-zA-Z0-9:_]*")},
    };
};