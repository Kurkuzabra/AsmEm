#include "../include/command_factory.hpp"

CommandFactory::CommandFactory(stk::Stack<int> &stack_) : stack(stack_){}
CommandFactory::CommandFactory(stk::Stack<int> &&stack_) : stack(stack_){}

CommandCreator *CommandFactory::get_creator(std::string cmd__)
{

    if (cmd__ == "push")
    {
        return new PushCreator(stack);
    }
    else
    {
        throw std::overflow_error("abdedf");
    }
}