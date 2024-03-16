#pragma once
#include "command_creators.hpp"

class CommandFactory
{
private:
    stk::Stack<int>& stack;
public:

    CommandFactory(stk::Stack<int>&);
    CommandFactory(stk::Stack<int>&&);

    CommandCreator* get_creator(std::string);
};