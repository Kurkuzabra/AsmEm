#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include "stack.hpp"
#include "executor_data.hpp"

class Command
{
private:
    
public:
    virtual void doit(ExData&);
    virtual void serialize(std::ofstream&) {}
};

class Linakble : public Command
{
public:
    int value;
};


class Pushr : public Command
{
public:
    std::string reg;
    Pushr();
    void doit(ExData&);
    void serialize(std::ofstream&);
};

class Popr : public Command
{
public:
    std::string reg;
    Popr();
    void doit(ExData&);
    void serialize(std::ofstream&);
};

class Ret : public Command
{
public:
    int value;
    Ret();
    void doit(ExData&);
    void serialize(std::ofstream&);
};

class Call : public Linakble
{
public:
    Call();
    void doit(ExData&);
    void serialize(std::ofstream&);
};

class Jmp : public Linakble
{
public:
    Jmp();
    void doit(ExData&);
    void serialize(std::ofstream&);
};

class Jeq : public Linakble
{
public:
    Jeq();
    void doit(ExData&);
    void serialize(std::ofstream&);
};
class Jne : public Linakble
{
public:
    Jne();
    void doit(ExData&);
    void serialize(std::ofstream&);
};
class Ja : public Linakble
{
public:
    Ja();
    void doit(ExData&);
    void serialize(std::ofstream&);
};
class Jae : public Linakble
{
public:
    Jae();
    void doit(ExData&);
    void serialize(std::ofstream&);
};
class Jb : public Linakble
{
public:
    Jb();
    void doit(ExData&);
    void serialize(std::ofstream&);
};
class Jbe : public Linakble
{
public:
    Jbe();
    void doit(ExData&);
    void serialize(std::ofstream&);
};



class Label : public Command
{
public:
    Label() {}
    void doit(ExData&) {}
    void serialize(std::ofstream&);
};

class Beg : public Command
{
public:
    Beg() {}
    void doit(ExData&) {}
    void serialize(std::ofstream&);
};

class End : public Command
{
public:
    End() {}
    void doit(ExData&) {}
    void serialize(std::ofstream&);
};

class Push : public Command
{
public:
    int value;
    Push();
    void doit(ExData&);
    void serialize(std::ofstream&);
};

class Pop : public Command
{
public:
    Pop();
    void doit(ExData&);
    void serialize(std::ofstream&);
};

class Add : public Command
{
public:
    Add();
    void doit(ExData&);
    void serialize(std::ofstream&);
};

class Sub : public Command
{
public:
    Sub();
    void doit(ExData&);
    void serialize(std::ofstream&);
};

class Mul : public Command
{
public:
    Mul();
    void doit(ExData&);
    void serialize(std::ofstream&);
};

class Div : public Command
{
public:
    Div();
    void doit(ExData&);
    void serialize(std::ofstream&);
};

class Out : public Command
{
public:
    Out();
    void doit(ExData&);
    void serialize(std::ofstream&);
};

class In : public Command
{
public:
    In();
    void doit(ExData&);
    void serialize(std::ofstream&);
};