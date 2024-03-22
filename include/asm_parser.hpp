#pragma once
#include "token_parser.hpp"
#include "command_factory.hpp"

static std::map<std::string, std::pair<int, std::vector<TokenType>>> str_cmd = 
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
    {"pushr", std::make_pair(1, std::vector<TokenType>{TokenType::WORD})},
    {"popr", std::make_pair(1, std::vector<TokenType>{TokenType::WORD})},
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

    bool parse_command();
    void set_gotos();

public:

    AsmParser(std::string& input_, stk::Stack<int>& stack__);
    void parse_all();
    std::vector<Command*>& get_cmds();
    ExData& get_ex_data();

};