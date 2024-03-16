#pragma once
#include <vector>
#include <iostream>
#include <exception>
#include "stack.hpp"

class Command
{
private:
    
public:
    virtual void doit();
    // virtual void serialize();
};

class Push : public Command
{
private:
    stk::Stack<int>& stack;

public:
    int value;
    Push(stk::Stack<int>&);
    void doit();
};