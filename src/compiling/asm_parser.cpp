#include "../../include/asm_parser.hpp"
// #include "../../include/exceptions.hpp"

bool AsmParser::parse_command()
{
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
        delete creator;
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
    delete creator;
    return true;
}

void AsmParser::set_gotos()
{
    for (int i = 0; i < dt.unmatched_links.size(); i++)
    {
        bool found = false;
        for (int j = 0; j < dt.label_names.size(); j++)
        {
            if (dt.label_names[j] == dt.unmatched_links[i].second)
            {
                static_cast<Linakble*>(commands[dt.unmatched_links[i].first])->value = dt.labels[j];
                found = true;
                break;
            }
        }
        if (!found)
        {
            throw custom_exception("not found");
        }
    }
}

AsmParser::AsmParser(std::string& input_, stk::Stack<int>& stack__) : parser(TokenParser(input_)),
    factory(CommandFactory()), dt(ExData(stack__)) {};

void AsmParser::parse_all()
{
    while(parse_command());
    set_gotos();
}

std::vector<Command*>& AsmParser::get_cmds()
{
    return commands;
}

ExData& AsmParser::get_ex_data()
{
    return dt;
}

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