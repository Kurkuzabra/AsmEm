#pragma once
#include "commands.hpp"

class CommandCreator
{
public:
    int stage;

public:
    virtual void nextSet(const std::string) = 0;
    virtual Command* get_cmd() = 0;
};

class PushCreator : public CommandCreator
{
private:
    Push* command;

public:
    PushCreator(stk::Stack<int>&);
    void nextSet(const std::string);
    Command* get_cmd();
};