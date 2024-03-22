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

    bool parse(TokenType type) {
        std::regex_search(input_.cbegin() + offset_, input_.cend(), last_match_, token_regex_.at(type));
        if (!last_match_.empty())
        {
            tokens_.push_back({last_match_.str(), type});
            offset_ += last_match_.position() + last_match_.length();
            return true;
        }
        else
        {
            return false;
        }
    }

    void thenParse(TokenType type) {
        bool res__ = parse(type);
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
            {TokenType::WORD,  std::regex("[a-zA-Z_][a-zA-Z0-9:_]*")},
    };
};

std::map<std::string, std::pair<int, std::vector<TokenType>>> str_cmd = 
{
    {"push", std::make_pair(1, std::vector<TokenType>{TokenType::INTEGER_VALUE})},
    {"jmp", std::make_pair(1, std::vector<TokenType>{TokenType::WORD})},
    {"jeq", std::make_pair(1, std::vector<TokenType>{TokenType::WORD})},
    {"jne", std::make_pair(1, std::vector<TokenType>{TokenType::WORD})},
    {"ja", std::make_pair(1, std::vector<TokenType>{TokenType::WORD})},
    {"jae", std::make_pair(1, std::vector<TokenType>{TokenType::WORD})},
    {"jb", std::make_pair(1, std::vector<TokenType>{TokenType::WORD})},
    {"jbe", std::make_pair(1, std::vector<TokenType>{TokenType::WORD})},
    {"call", std::make_pair(1, std::vector<TokenType>{TokenType::WORD})},
    {"ret", std::make_pair(0, std::vector<TokenType>{})},
    {"pop", std::make_pair(0, std::vector<TokenType>{})},
    {"add", std::make_pair(0, std::vector<TokenType>{})},
    {"sub", std::make_pair(0, std::vector<TokenType>{})},
    {"mul", std::make_pair(0, std::vector<TokenType>{})},
    {"div", std::make_pair(0, std::vector<TokenType>{})},
    {"out", std::make_pair(0, std::vector<TokenType>{})},
    {"in", std::make_pair(0, std::vector<TokenType>{})},
    {"beg", std::make_pair(0, std::vector<TokenType>{})},
    {"end", std::make_pair(0, std::vector<TokenType>{})},
};

class AsmParser
{
public:

    TokenParser parser;
    CommandFactory factory;
    std::vector<Command*> commands;
    ExData dt;

    bool parse_command()
    {
    for(int i = 0; i < dt.entrypoints.size(); i++)
    {
        std::cout << dt.entrypoints[i] << "   aaa" << std::endl;
    }
        bool parse_res = parser.parse(TokenType::WORD);
        if (!parse_res)
        {
            return false;
        }
        const std::string& token = parser.getLastToken();
        if (str_cmd.count(token) == 0 && token[token.length() - 1] == ':')
        {
            std::cout<<token.substr(0, token.length() - 1)<<std::endl;
            CommandCreator* creator = factory.get_creator(token.substr(0, token.length() - 1), dt);
            commands.push_back(creator->get_cmd());
            dt.iteration++;
            return true;
        }

        int& values_length = str_cmd.at(token).first;
        std::vector<TokenType>& values = str_cmd.at(token).second;

        CommandCreator* creator = factory.get_creator(token, dt);
        for (int i = 0; i < values_length; i++)
        {
            parser.thenParse(values[i]);
            creator->nextSet(parser.getLastToken(), dt);
        }
        commands.push_back(creator->get_cmd());
        dt.iteration++;
        return true;
    }

public:

    AsmParser(std::string& input_, stk::Stack<int>& stack__) : parser(TokenParser(input_)),
        factory(CommandFactory()), dt(ExData(stack__)) {
            std::cout << dt.entrypoints.size() << "   aaa" << std::endl;
        };

    void parse_all()
    {
        while(parse_command());
    }

    std::vector<Command*>& get_cmds()
    {
        return commands;
    }

    ExData& get_ex_data()
    {
        return dt;
    }

};

class Executor
{
private:
    std::vector<Command*> commands;
    ExData dt;

public:
    Executor(stk::Stack<int>& base_stk_, std::vector<Command*> comms_, ExData dt_) : dt(ExData(base_stk_)), commands(comms_)
    {
        dt.endpoints = dt_.endpoints;
        dt.entrypoints = dt_.entrypoints;
        dt.labels = dt_.labels;
        dt.label_names = dt.label_names;
        dt.iteration = 0;
    };

    void execute()
    {
        std::cout << dt.labels[0] << std::endl;
        int en_en_iter = 0;
        for (; dt.iteration < commands.size(); dt.iteration++)
        {
            if (en_en_iter >= dt.entrypoints.size())
            {
                break;
            }
            if (dt.depth > 0 || (dt.iteration >= dt.entrypoints[en_en_iter] && dt.iteration <= dt.endpoints[en_en_iter]))
            {
                commands[dt.iteration]->doit(dt);
            }
            else if (dt.iteration >= dt.endpoints[en_en_iter])
            {
                en_en_iter++;
            }

        }
    }
};

int main() {
    std::string input = "funk: push 500 out ret \n beg push 10 push 430 push 430 push 430 push 430 label1: out jeq label1 end";
    auto comp_stk = stk::Stack<int>();
    auto parser = AsmParser(input, comp_stk);
    parser.parse_all();
    
    auto tokens = parser.parser.getTokens();
    // for (int i = 0; i < tokens.size(); i++)
    // {
    //     std::cout<<tokens[i].value<<std::endl;
    // }
    auto commands = parser.get_cmds();
    auto dt = parser.get_ex_data();
    auto base_stk = stk::Stack<int>();
    std::cout << "b " << base_stk.size << std::endl;
    Executor ex = Executor(base_stk, commands, dt);
    ex.execute();
}