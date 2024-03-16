#include "../include/command_creators.hpp"

PushCreator::PushCreator(stk::Stack<int> &stack_)
{
    command = new Push(stack_);
    stage = 0;
}
void PushCreator::nextSet(const std::string value_)
{
    switch (stage)
    {
    case 0:
        command->value = std::stoi(value_);
        break;
    }
    stage++;
}
Command* PushCreator::get_cmd()
{
    return static_cast<Command *>(command);
}
