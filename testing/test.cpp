#include <iostream>
#include <stdexcept>
#include <vector>
#include <gtest/gtest.h>
#include "../include/stack.hpp"


using namespace stk;
using namespace std;

TEST(push, test1)
{
    Stack<int> stack = Stack<int>();
    stack.push(5);
    stack.push(-1000);
    stack.push(777);
    EXPECT_TRUE(stack.top() == 777);
}

TEST(push, test2)
{
    Stack<double> stack = Stack<double>();
    EXPECT_THROW
    (
        for(int i = 0; i < 10000000; i++)
        {
            stack.push(static_cast<double>(i));
        },
        std::overflow_error
    );
}

TEST(pop, test1)
{
    Stack<int> sta = Stack<int>();
    Stack<int> &stack = sta;
    stack.push(5);
    stack.push(-1000);
    stack.pop();
    stack.push(777);
    stack.push(2345);
    stack.push(-2352);
    stack.pop();
    stack.pop();
    std::cout << stack.top();
    EXPECT_TRUE(stack.top() == 777);
}

TEST(pop, test2)
{
    Stack<int> stack = Stack<int>();
    EXPECT_THROW(stack.top(), std::overflow_error);
}

TEST(pop, test3)
{
    Stack<int> stack = Stack<int>();
    EXPECT_THROW(stack.pop(), std::underflow_error);
}

TEST(copy, test1)
{
    Stack<int> stack = Stack<int>();
    stack.push(5);
    stack.push(-1000);
    stack.pop();
    stack.push(777);
    stack.push(2345);
    stack.push(-2352);
    stack.pop();
    stack.pop();
    Stack<int> new_stack = Stack<int>(stack);
    new_stack.pop();
    EXPECT_TRUE(stack.top() == 777 && new_stack.top() == 5);
}

TEST(move_constructor, test1)
{
    Stack<int> stack = Stack<int>();
    stack.push(5);
    stack.push(-1000);
    stack.pop();
    stack.push(777);
    stack.push(2345);
    stack.push(-2352);
    stack.pop();
    stack.pop();
    Stack<int> new_stack = Stack<int>(std::move(stack));
    new_stack.pop();
    EXPECT_TRUE(new_stack.top() == 5);
}

TEST(destructor, test1)
{
    Stack<int> *stack = new Stack<int>();
    stack->push(5);
    stack->push(-1000);
    stack->pop();
    stack->push(777);
    stack->push(2345);
    stack->push(-2352);
    stack->pop();
    stack->pop();
    stack->push(4444);
    stack->push(21411);
    stack->push(-2352);
    EXPECT_NO_THROW(free(stack));
}

TEST(move_push, test1)
{
    Stack<vector<int>> stack = Stack<vector<int>>();
    vector<int> a = vector<int>(1);
    stack.push(std::move(a));
    EXPECT_TRUE(stack.top() == vector<int>(1));
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}