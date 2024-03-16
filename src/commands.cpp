#include "../include/commands.hpp"

void Command::doit()
{
    std::cout << "undefined command\n";
}

Push::Push(stk::Stack<int> &stack_) : stack(stack_){};
void Push::doit()
{
    std::cout << "push==" << value << std::endl;
}