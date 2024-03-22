#pragma once
#include "commands.hpp"

class Executor
{
private:
    std::vector<Command*> commands;
    ExData dt;

public:
    Executor(stk::Stack<int>& base_stk_, std::vector<Command*> comms_, ExData dt_);
    void execute();
};