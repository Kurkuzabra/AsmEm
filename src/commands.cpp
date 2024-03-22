#include "../include/commands.hpp"

void Command::doit(ExData&)
{
    std::cout << "undefined command\n";
}

Ret::Ret() {}
void Ret::doit(ExData& dt)
{
    dt.depth--;
    dt.iteration = dt.returnpoints[dt.returnpoints.size() - 1];
    dt.returnpoints.pop_back();
}

Call::Call() {}
void Call::doit(ExData& dt)
{
    dt.depth++;
    dt.returnpoints.push_back(dt.iteration);
    dt.iteration = value;
}

Jmp::Jmp() {}
void Jmp::doit(ExData& dt)
{
    dt.iteration = value;
}
Jeq::Jeq() {}
void Jeq::doit(ExData& dt)
{
    int a = dt.stack.top();
    dt.stack.pop();
    if (a == dt.stack.top())
    {
        dt.iteration = value;
    }
    dt.stack.push(a);
}
Jne::Jne() {}
void Jne::doit(ExData& dt)
{
    int a = dt.stack.top();
    dt.stack.pop();
    if (a != dt.stack.top())
    {
        dt.iteration = value;
    }
    dt.stack.push(a);
}
Ja::Ja() {}
void Ja::doit(ExData& dt)
{
    int a = dt.stack.top();
    dt.stack.pop();
    if (a > dt.stack.top())
    {
        dt.iteration = value;
    }
    dt.stack.push(a);
}
Jae::Jae() {}
void Jae::doit(ExData& dt)
{
    int a = dt.stack.top();
    dt.stack.pop();
    if (a >= dt.stack.top())
    {
        dt.iteration = value;
    }
    dt.stack.push(a);
}
Jb::Jb() {}
void Jb::doit(ExData& dt)
{
    int a = dt.stack.top();
    dt.stack.pop();
    if (a < dt.stack.top())
    {
        dt.iteration = value;
    }
    dt.stack.push(a);
}
Jbe::Jbe() {}
void Jbe::doit(ExData& dt)
{
    int a = dt.stack.top();
    dt.stack.pop();
    if (a <= dt.stack.top())
    {
        dt.iteration = value;
    }
    dt.stack.push(a);
}

Push::Push() {}
void Push::doit(ExData& dt)
{
    dt.stack.push(value);
}

Pop::Pop() {}
void Pop::doit(ExData& dt)
{
    dt.stack.pop();
}

Add::Add() {}
void Add::doit(ExData& dt)
{
    int a = dt.stack.top();
    dt.stack.pop();
    int b = dt.stack.top();
    dt.stack.push(a);
    dt.stack.push(a + b);
}

Sub::Sub() {}
void Sub::doit(ExData& dt)
{
    int a = dt.stack.top();
    dt.stack.pop();
    int b = dt.stack.top();
    dt.stack.push(a);
    dt.stack.push(a - b);
}

Mul::Mul() {}
void Mul::doit(ExData& dt)
{
    int a = dt.stack.top();
    dt.stack.pop();
    int b = dt.stack.top();
    dt.stack.push(a);
    dt.stack.push(a * b);
}

Div::Div() {}
void Div::doit(ExData& dt)
{
    int a = dt.stack.top();
    dt.stack.pop();
    int b = dt.stack.top();
    dt.stack.push(a);
    dt.stack.push(a / b);
}

Out::Out() {}
void Out::doit(ExData& dt)
{
    int a = dt.stack.top();
    dt.stack.pop();
    std::cout << a;
}

In::In() {}
void In::doit(ExData& dt)
{
    int a;
    std::cin >> a;
    dt.stack.push(a);
}