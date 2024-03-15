#include <iostream>
#include <stdexcept>
#include <gtest/gtest.h>
#include "../include/stack.hpp"


using namespace stk;

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
    Stack<int> stack = Stack<int>();
    stack.push(5);
    stack.push(-1000);
    stack.pop();
    stack.push(777);
    stack.push(2345);
    stack.push(-2352);
    stack.pop();
    stack.pop();
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

int main(int argc, char** argv)
{
        testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}