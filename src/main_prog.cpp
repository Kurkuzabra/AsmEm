#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <fstream>

#include "../include/asm_parser.hpp"
#include "../include/executor.hpp"
#include "../include/serialization.hpp"

AsmParser read_from_asm_file(char* filename)
{
    std::ifstream inFile;
    inFile.open(filename);
    std::stringstream strStream;
    strStream << inFile.rdbuf();
    std::string input = strStream.str();
    inFile.close();

    stk::Stack<int> comp_stk = stk::Stack<int>();
    AsmParser parser = AsmParser(input, comp_stk);
    parser.parse_all();

    return parser;
}

int main(int argc, char **argv)
{
    auto s = Serialize();
    char *filename = argv[1];
    auto parser = read_from_asm_file(filename);
    auto commands = parser.get_cmds();
    auto dt = parser.get_ex_data();
    std::ofstream out("out.txt", std::ios::binary);

    Serialize::serialize(out, commands);
    Serialize::serialize(out, dt);

    out.close();
    
    std::ifstream in("out.txt", std::ios::binary);

    std::vector<Command*> comms = Serialize::deserialize_commands(in);
    ExData dt1 = Serialize::deserialize_dt(in);

    

    in.close();

    auto base_stk = stk::Stack<int>();
    Executor ex = Executor(base_stk, comms, dt1);
    ex.execute();
}