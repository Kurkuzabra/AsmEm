#pragma once
#include "commands.hpp"

class CommandCreator
{
public:
    int stage;

public:
    virtual void nextSet(const std::string, ExData&) = 0;
    virtual Command* get_cmd() = 0;
};

class PushrCreator : public CommandCreator
{
private:
    Pushr* command;

public:
    PushrCreator(ExData&);
    void nextSet(const std::string, ExData&);
    Command* get_cmd();
};

class PoprCreator : public CommandCreator
{
private:
    Popr* command;

public:
    PoprCreator(ExData&);
    void nextSet(const std::string, ExData&);
    Command* get_cmd();
};

class RetCreator : public CommandCreator
{
private:
    Ret* command;

public:
    RetCreator(ExData&);
    void nextSet(const std::string, ExData&);
    Command* get_cmd();
};

class CallCreator : public CommandCreator
{
private:
    Call* command;

public:
    CallCreator(ExData&);
    void nextSet(const std::string, ExData&);
    Command* get_cmd();
};

class JmpCreator : public CommandCreator
{
private:
    Jmp* command;

public:
    JmpCreator(ExData&);
    void nextSet(const std::string, ExData&);
    Command* get_cmd();
};
class JeqCreator : public CommandCreator
{
private:
    Jeq* command;

public:
    JeqCreator(ExData&);
    void nextSet(const std::string, ExData&);
    Command* get_cmd();
};
class JneCreator : public CommandCreator
{
private:
    Jne* command;

public:
    JneCreator(ExData&);
    void nextSet(const std::string, ExData&);
    Command* get_cmd();
};
class JaCreator : public CommandCreator
{
private:
    Ja* command;

public:
    JaCreator(ExData&);
    void nextSet(const std::string, ExData&);
    Command* get_cmd();
};
class JaeCreator : public CommandCreator
{
private:
    Jae* command;

public:
    JaeCreator(ExData&);
    void nextSet(const std::string, ExData&);
    Command* get_cmd();
};
class JbCreator : public CommandCreator
{
private:
    Jb* command;

public:
    JbCreator(ExData&);
    void nextSet(const std::string, ExData&);
    Command* get_cmd();
};
class JbeCreator : public CommandCreator
{
private:
    Jbe* command;

public:
    JbeCreator(ExData&);
    void nextSet(const std::string, ExData&);
    Command* get_cmd();
};

class LabelCreator : public CommandCreator
{
private:
    Label* command;

public:
    LabelCreator(ExData&);
    void nextSet(const std::string, ExData&);
    Command* get_cmd();
};

class BegCreator : public CommandCreator
{
private:
    Beg* command;

public:
    BegCreator(ExData&);
    void nextSet(const std::string, ExData&);
    Command* get_cmd();
};

class EndCreator : public CommandCreator
{
private:
    End* command;

public:
    EndCreator(ExData&);
    void nextSet(const std::string, ExData&);
    Command* get_cmd();
};

class PushCreator : public CommandCreator
{
private:
    Push* command;

public:
    PushCreator(ExData&);
    void nextSet(const std::string, ExData&);
    Command* get_cmd();
};

class PopCreator : public CommandCreator
{
private:
    Pop* command;

public:
    PopCreator(ExData&);
    void nextSet(const std::string, ExData&);
    Command* get_cmd();
};

class AddCreator : public CommandCreator
{
private:
    Add* command;

public:
    AddCreator(ExData&);
    void nextSet(const std::string, ExData&);
    Command* get_cmd();
};

class SubCreator : public CommandCreator
{
private:
    Sub* command;

public:
    SubCreator(ExData&);
    void nextSet(const std::string, ExData&);
    Command* get_cmd();
};

class MulCreator : public CommandCreator
{
private:
    Mul* command;

public:
    MulCreator(ExData&);
    void nextSet(const std::string, ExData&);
    Command* get_cmd();
};

class DivCreator : public CommandCreator
{
private:
    Div* command;

public:
    DivCreator(ExData&);
    void nextSet(const std::string, ExData&);
    Command* get_cmd();
};

class OutCreator : public CommandCreator
{
private:
    Out* command;

public:
    OutCreator(ExData&);
    void nextSet(const std::string, ExData&);
    Command* get_cmd();
};

class InCreator : public CommandCreator
{
private:
    In* command;

public:
    InCreator(ExData&);
    void nextSet(const std::string, ExData&);
    Command* get_cmd();
};