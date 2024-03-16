#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "../include/command_factory.hpp"

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

    bool isEmpty() const {
        return tokens_.empty();
    }

    void parse(TokenType type) {
        std::regex_search(input_.cbegin() + offset_, input_.cend(), last_match_, token_regex_.at(type));
        if (!last_match_.empty())
        {
            tokens_.push_back({last_match_.str(), type});
            offset_ += last_match_.position() + last_match_.length();
        }
    }

    void thenParse(TokenType type) {
        parse(type);
        if (last_match_.empty())
        {
            throw std::overflow_error("kkk");
        }
    }

    std::vector<Token> getTokens() const
    {
        return tokens_;
    }

    const std::string& getLastToken() const
    {
        return tokens_[tokens_.size() - 1].value;
    }

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
            {TokenType::WORD,  std::regex("[a-zA-Z_][a-zA-Z0-9_]*")},
    };
};

std::map<std::string, std::pair<int, std::vector<TokenType>>> str_cmd = 
{
    {"push", std::make_pair(1, std::vector<TokenType>{TokenType::INTEGER_VALUE})},
};

class AsmParser
{
public:

    TokenParser parser;
    CommandFactory factory;
    std::vector<Command*> commands;

    void parse_command()
    {

        parser.parse(TokenType::WORD);
        const std::string& token = parser.getLastToken();
        int& values_length = str_cmd.at(token).first;
        std::vector<TokenType>& values = str_cmd.at(token).second;
        CommandCreator* creator = factory.get_creator(token);
        for (int i = 0; i < values_length; i++)
        {
            parser.thenParse(values[i]);
            creator->nextSet(parser.getLastToken());
        }
        commands.push_back(creator->get_cmd());
    }

public:

    AsmParser(std::string& input_) : parser(TokenParser(input_)), factory(CommandFactory(stk::Stack<int>())) {};
    std::vector<Command*>& get_cmds()
    {
        return commands;
    }

};

int main() {
    std::string input = "push 500";
    auto parser = AsmParser(input);
    parser.parse_command();
    // parser.parse(TokenType::WORD)
    //         .orElse(TokenType::WORD)
    //         .thenParse(TokenType::WORD)
    //         .thenParse(TokenType::END_OF_FILE)
    //         .getTokens();

    auto tokens = parser.parser.getTokens();
    for (int i = 0; i < tokens.size(); i++)
    {
        std::cout<<tokens[i].value<<std::endl;
    }
    auto commands = parser.get_cmds();
    for (int i = 0; i < commands.size(); i++)
    {
        commands[i]->doit();
    }
}