#include "../../include/commands.hpp"

void Command::doit(ExData&)
{
    std::cout << "undefined command\n";
}

Pushr::Pushr() {}
void Pushr::doit(ExData& dt)
{
    dt.stack.push(dt.registers.at(reg));
}
void Pushr::serialize(std::ofstream& out)
{
    const char *name = "pur";
    out.write(name, 3);
    out.write(reg.c_str(), 2);
}

Popr::Popr() {}
void Popr::doit(ExData& dt)
{
    dt.registers.at(reg) = dt.stack.top();
    dt.stack.pop();
}
void Popr::serialize(std::ofstream& out)
{
    const char *name = "por";
    out.write(name, 3);
    out.write(reg.c_str(), 2);
}


Ret::Ret() {}
void Ret::doit(ExData& dt)
{
    dt.depth--;
    dt.iteration = dt.returnpoints[dt.returnpoints.size() - 1];
    dt.returnpoints.pop_back();
}
void Ret::serialize(std::ofstream& out)
{
    const char *name = "ret";
    out.write(name, 3);
}

Call::Call() {}
void Call::doit(ExData& dt)
{
    dt.depth++;
    dt.returnpoints.push_back(dt.iteration);
    dt.iteration = value;
}
void Call::serialize(std::ofstream& out)
{
    const char *name = "cal";
    const char *data = reinterpret_cast<const char*>(&value);
    out.write(name, 3);
    out.write(data, sizeof(value));
}

Jmp::Jmp() {}
void Jmp::doit(ExData& dt)
{
    dt.iteration = value;
}
void Jmp::serialize(std::ofstream& out)
{
    const char *name = "jmp";
    const char *data = reinterpret_cast<const char*>(&value);
    out.write(name, 3);
    out.write(data, sizeof(value));
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
void Jeq::serialize(std::ofstream& out)
{
    const char *name = "jeq";
    const char *data = reinterpret_cast<const char*>(&value);
    out.write(name, 3);
    out.write(data, sizeof(value));
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
void Jne::serialize(std::ofstream& out)
{
    const char *name = "jne";
    const char *data = reinterpret_cast<const char*>(&value);
    out.write(name, 3);
    out.write(data, sizeof(value));
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
void Ja::serialize(std::ofstream& out)
{
    const char *name = "ja_";
    const char *data = reinterpret_cast<const char*>(&value);
    out.write(name, 3);
    out.write(data, sizeof(value));
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
void Jae::serialize(std::ofstream& out)
{
    const char *name = "jae";
    const char *data = reinterpret_cast<const char*>(&value);
    out.write(name, 3);
    out.write(data, sizeof(value));
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
void Jb::serialize(std::ofstream& out)
{
    const char *name = "jb_";
    const char *data = reinterpret_cast<const char*>(&value);
    out.write(name, 3);
    out.write(data, sizeof(value));
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
void Jbe::serialize(std::ofstream& out)
{
    const char *name = "jbe";
    const char *data = reinterpret_cast<const char*>(&value);
    out.write(name, 3);
    out.write(data, sizeof(value));
}

Push::Push() {}
void Push::doit(ExData& dt)
{
    dt.stack.push(value);
}
void Push::serialize(std::ofstream& out)
{
    const char *name = "pus";
    const char *data = reinterpret_cast<const char*>(&value);
    out.write(name, 3);
    out.write(data, sizeof(value));
}

Pop::Pop() {}
void Pop::doit(ExData& dt)
{
    dt.stack.pop();
}
void Pop::serialize(std::ofstream& out)
{
    const char *name = "pop";
    out.write(name, 3);
}

Add::Add() {}
void Add::doit(ExData& dt)
{
    int a = dt.stack.top();
    dt.stack.pop();
    int b = dt.stack.top();
    dt.stack.pop();
    dt.stack.push(a + b);
}
void Add::serialize(std::ofstream& out)
{
    const char *name = "add";
    out.write(name, 3);
}

Sub::Sub() {}
void Sub::doit(ExData& dt)
{
    int a = dt.stack.top();
    dt.stack.pop();
    int b = dt.stack.top();
    dt.stack.pop();
    dt.stack.push(b - a);
}
void Sub::serialize(std::ofstream& out)
{
    const char *name = "sub";
    out.write(name, 3);
}

Mul::Mul() {}
void Mul::doit(ExData& dt)
{
    int a = dt.stack.top();
    dt.stack.pop();
    int b = dt.stack.top();
    dt.stack.pop();
    dt.stack.push(a * b);
}
void Mul::serialize(std::ofstream& out)
{
    const char *name = "mul";
    out.write(name, 3);
}

Div::Div() {}
void Div::doit(ExData& dt)
{
    int a = dt.stack.top();
    dt.stack.pop();
    int b = dt.stack.top();
    dt.stack.pop();
    dt.stack.push(b / a);
}
void Div::serialize(std::ofstream& out)
{
    const char *name = "div";
    out.write(name, 3);
}

Out::Out() {}
void Out::doit(ExData& dt)
{
    int a = dt.stack.top();
    dt.stack.pop();
    std::cout << a;
}
void Out::serialize(std::ofstream& out)
{
    const char *name = "out";
    out.write(name, 3);
}

In::In() {}
void In::doit(ExData& dt)
{
    int a;
    std::cin >> a;
    dt.stack.push(a);
}
void In::serialize(std::ofstream& out)
{
    const char *name = "in_";
    out.write(name, 3);
}

void End::serialize(std::ofstream& out)
{
    const char *name = "end";
    out.write(name, 3);
}
void Beg::serialize(std::ofstream& out)
{
    const char *name = "beg";
    out.write(name, 3);
}
void Label::serialize(std::ofstream& out)
{
    const char *name = "lab";
    out.write(name, 3);
}