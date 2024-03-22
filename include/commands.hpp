#pragma once
#include <vector>
#include <iostream>
#include <exception>
#include "stack.hpp"
#include "executor_data.hpp"

class Command
{
private:
    
public:
    virtual void doit(ExData&);
    // virtual void serialize();
};

class Ret : public Command
{
public:
    int value;
    Ret();
    void doit(ExData&);
};

class Call : public Command
{
public:
    int value;
    Call();
    void doit(ExData&);
};

class Jmp : public Command
{
public:
    int value;
    Jmp();
    void doit(ExData&);
};

class Jeq : public Command
{
public:
    int value;
    Jeq();
    void doit(ExData&);
};
class Jne : public Command
{
public:
    int value;
    Jne();
    void doit(ExData&);
};
class Ja : public Command
{
public:
    int value;
    Ja();
    void doit(ExData&);
};
class Jae : public Command
{
public:
    int value;
    Jae();
    void doit(ExData&);
};
class Jb : public Command
{
public:
    int value;
    Jb();
    void doit(ExData&);
};
class Jbe : public Command
{
public:
    int value;
    Jbe();
    void doit(ExData&);
};



class Label : public Command
{
public:
    Label() {}
    void doit(ExData&) {}
};

class Beg : public Command
{
public:
    Beg() {}
    void doit(ExData&) {}
};

class End : public Command
{
public:
    End() {}
    void doit(ExData&) {}
};

class Push : public Command
{
public:
    int value;
    Push();
    void doit(ExData&);
};

class Pop : public Command
{
public:
    Pop();
    void doit(ExData&);
};

class Add : public Command
{
public:
    Add();
    void doit(ExData&);
};

class Sub : public Command
{
public:
    Sub();
    void doit(ExData&);
};

class Mul : public Command
{
public:
    Mul();
    void doit(ExData&);
};

class Div : public Command
{
public:
    Div();
    void doit(ExData&);
};

class Out : public Command
{
public:
    Out();
    void doit(ExData&);
};

class In : public Command
{
public:
    In();
    void doit(ExData&);
};