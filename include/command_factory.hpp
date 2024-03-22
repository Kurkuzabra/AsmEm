#pragma once
#include "command_creators.hpp"

class CommandFactory
{
public:

    CommandFactory();

    CommandCreator* get_creator(std::string, ExData& dt);
};