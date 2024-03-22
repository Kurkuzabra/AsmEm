#pragma once
#include "commands.hpp"
#include "executor_data.hpp"

enum class BinaryToken
{
    INTEGER_VALUE,
    REGISTER,
};

static std::map<std::string, std::pair<int, std::vector<BinaryToken>>> bin_cmd = 
{
    {"pus", std::make_pair(1, std::vector<BinaryToken>{BinaryToken::INTEGER_VALUE})},
    {"jmp", std::make_pair(1, std::vector<BinaryToken>{BinaryToken::INTEGER_VALUE})},
    {"jeq", std::make_pair(1, std::vector<BinaryToken>{BinaryToken::INTEGER_VALUE})},
    {"jne", std::make_pair(1, std::vector<BinaryToken>{BinaryToken::INTEGER_VALUE})},
    {"ja_", std::make_pair(1, std::vector<BinaryToken>{BinaryToken::INTEGER_VALUE})},
    {"jae", std::make_pair(1, std::vector<BinaryToken>{BinaryToken::INTEGER_VALUE})},
    {"jb_", std::make_pair(1, std::vector<BinaryToken>{BinaryToken::INTEGER_VALUE})},
    {"jbe", std::make_pair(1, std::vector<BinaryToken>{BinaryToken::INTEGER_VALUE})},
    {"cal", std::make_pair(1, std::vector<BinaryToken>{BinaryToken::INTEGER_VALUE})},
    {"pur", std::make_pair(1, std::vector<BinaryToken>{BinaryToken::REGISTER})},
    {"por", std::make_pair(1, std::vector<BinaryToken>{BinaryToken::REGISTER})},
    {"ret", std::make_pair(0, std::vector<BinaryToken>{})},
    {"pop", std::make_pair(0, std::vector<BinaryToken>{})},
    {"add", std::make_pair(0, std::vector<BinaryToken>{})},
    {"sub", std::make_pair(0, std::vector<BinaryToken>{})},
    {"mul", std::make_pair(0, std::vector<BinaryToken>{})},
    {"div", std::make_pair(0, std::vector<BinaryToken>{})},
    {"out", std::make_pair(0, std::vector<BinaryToken>{})},
    {"in_", std::make_pair(0, std::vector<BinaryToken>{})},
    {"beg", std::make_pair(0, std::vector<BinaryToken>{})},
    {"end", std::make_pair(0, std::vector<BinaryToken>{})},
};

class Serialize
{
public:
    static void serialize(std::ofstream&, std::vector<Command*>);
    static ExData deserialize_dt(std::ifstream&);
    static void serialize(std::ofstream&, ExData&);
    static std::string deserialize_reg(std::ifstream&);
    static int deserialize_int(std::ifstream&);
    static std::vector<Command*> deserialize_commands(std::ifstream&);
};