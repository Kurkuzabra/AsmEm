#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include "stack.hpp"

struct ExData
{
    stk::Stack<int>& stack;
    std::vector<int> labels;
    std::vector<int> entrypoints;
    std::vector<int> endpoints;
    std::vector<int> returnpoints;
    std::vector<std::string> label_names;
    std::vector<std::pair<int, std::string>> unmatched_links;
    std::map<std::string, int> registers = 
    {
        {"ax", 0},
        {"bx", 0},
        {"cx", 0},
    };
    int iteration = 0;
    int depth = 0;

    ExData(stk::Stack<int>& stack_) : stack(stack_), labels({}), entrypoints({}), endpoints({}), returnpoints({}) {}
    ExData& operator=(ExData dt_)
    {
        entrypoints = dt_.entrypoints;
        endpoints = dt_.endpoints;
        return *this;
    }
};