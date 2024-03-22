#pragma once
#include <vector>
#include <iostream>
#include <exception>
#include "stack.hpp"

struct ExData
{
    stk::Stack<int>& stack;
    std::vector<int> labels;
    std::vector<int> entrypoints;
    std::vector<int> endpoints;
    std::vector<int> returnpoints;
    std::vector<std::string> label_names;
    int iteration = 0;
    int depth = 0;

    ExData(stk::Stack<int>& stack_) : stack(stack_), labels({}), entrypoints({}), endpoints({}), returnpoints({}) {}
};