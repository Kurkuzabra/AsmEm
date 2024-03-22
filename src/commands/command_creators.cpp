#include "../../include/command_creators.hpp"

PushrCreator::PushrCreator(ExData& dt)
{
    command = new Pushr();
    stage = 0;
}
void PushrCreator::nextSet(const std::string value_, ExData& dt)
{
    switch (stage)
    {
    case 0:
        command->reg = value_;
        stage++;
        break;
    }
}
Command* PushrCreator::get_cmd()
{
    return static_cast<Command *>(command);
}

PoprCreator::PoprCreator(ExData& dt)
{
    command = new Popr();
    stage = 0;
}
void PoprCreator::nextSet(const std::string value_, ExData& dt)
{
    switch (stage)
    {
    case 0:
        command->reg = value_;
        stage++;
        break;
    }
}
Command* PoprCreator::get_cmd()
{
    return static_cast<Command *>(command);
}

RetCreator::RetCreator(ExData& dt)
{
    command = new Ret();
    stage = 0;
}
void RetCreator::nextSet(const std::string value_, ExData& dt) {}
Command* RetCreator::get_cmd()
{
    return static_cast<Command *>(command);
}

CallCreator::CallCreator(ExData& dt)
{
    command = new Call();
    stage = 0;
}
void CallCreator::nextSet(const std::string value_, ExData& dt)
{
    switch (stage)
    {
    case 0:
        std::cout << "aoooa" << std::endl;
        for (int i = 0; i < dt.label_names.size(); i++)
        {
            if (dt.label_names[i] == value_)
            {
                command->value = dt.labels[i];
                stage++;
                return;
            }
        }
        command->value = -1;
        dt.unmatched_links.push_back(std::make_pair(dt.iteration, value_));
    }
    
}
Command* CallCreator::get_cmd()
{
    return static_cast<Command *>(command);
}

JmpCreator::JmpCreator(ExData& dt)
{
    command = new Jmp();
    stage = 0;
}
void JmpCreator::nextSet(const std::string value_, ExData& dt)
{
    switch (stage)
    {
    case 0:
        for (int i = 0; i < dt.label_names.size(); i++)
        {
            if (dt.label_names[i] == value_)
            {
                command->value = dt.labels[i];
                stage++;
                return;
            }
        }
        command->value = -1;
        dt.unmatched_links.push_back(std::make_pair(dt.iteration, value_));
    }
    
}
Command* JmpCreator::get_cmd()
{
    return static_cast<Command *>(command);
}
JeqCreator::JeqCreator(ExData& dt)
{
    command = new Jeq();
    stage = 0;
}
void JeqCreator::nextSet(const std::string value_, ExData& dt)
{
    switch (stage)
    {
    case 0:
        for (int i = 0; i < dt.label_names.size(); i++)
        {
            if (dt.label_names[i] == value_)
            {
                command->value = dt.labels[i];
                stage++;
                return;
            }
        }
        command->value = -1;
        dt.unmatched_links.push_back(std::make_pair(dt.iteration, value_));
    }
    
}
Command* JeqCreator::get_cmd()
{
    return static_cast<Command *>(command);
}
JneCreator::JneCreator(ExData& dt)
{
    command = new Jne();
    stage = 0;
}
void JneCreator::nextSet(const std::string value_, ExData& dt)
{
    switch (stage)
    {
    case 0:
        for (int i = 0; i < dt.label_names.size(); i++)
        {
            if (dt.label_names[i] == value_)
            {
                command->value = dt.labels[i];
                stage++;
                return;
            }
        }
        command->value = -1;
        dt.unmatched_links.push_back(std::make_pair(dt.iteration, value_));
    }
    
}
Command* JneCreator::get_cmd()
{
    return static_cast<Command *>(command);
}
JaCreator::JaCreator(ExData& dt)
{
    command = new Ja();
    stage = 0;
}
void JaCreator::nextSet(const std::string value_, ExData& dt)
{
    switch (stage)
    {
    case 0:
        for (int i = 0; i < dt.label_names.size(); i++)
        {
            if (dt.label_names[i] == value_)
            {
                command->value = dt.labels[i];
                stage++;
                return;
            }
        }
        command->value = -1;
        dt.unmatched_links.push_back(std::make_pair(dt.iteration, value_));
    }
    
}
Command* JaCreator::get_cmd()
{
    return static_cast<Command *>(command);
}
JaeCreator::JaeCreator(ExData& dt)
{
    command = new Jae();
    stage = 0;
}
void JaeCreator::nextSet(const std::string value_, ExData& dt)
{
    switch (stage)
    {
    case 0:
        for (int i = 0; i < dt.label_names.size(); i++)
        {
            if (dt.label_names[i] == value_)
            {
                command->value = dt.labels[i];
                stage++;
                return;
            }
        }
        command->value = -1;
        dt.unmatched_links.push_back(std::make_pair(dt.iteration, value_));
    }
    
}
Command* JaeCreator::get_cmd()
{
    return static_cast<Command *>(command);
}
JbCreator::JbCreator(ExData& dt)
{
    command = new Jb();
    stage = 0;
}
void JbCreator::nextSet(const std::string value_, ExData& dt)
{
    switch (stage)
    {
    case 0:
        for (int i = 0; i < dt.label_names.size(); i++)
        {
            if (dt.label_names[i] == value_)
            {
                command->value = dt.labels[i];
                stage++;
                return;
            }
        }
        command->value = -1;
        dt.unmatched_links.push_back(std::make_pair(dt.iteration, value_));
    }
    
}
Command* JbCreator::get_cmd()
{
    return static_cast<Command *>(command);
}
JbeCreator::JbeCreator(ExData& dt)
{
    command = new Jbe();
    stage = 0;
}
void JbeCreator::nextSet(const std::string value_, ExData& dt)
{
    switch (stage)
    {
    case 0:
        for (int i = 0; i < dt.label_names.size(); i++)
        {
            if (dt.label_names[i] == value_)
            {
                command->value = dt.labels[i];
                stage++;
                return;
            }
        }
        command->value = -1;
        dt.unmatched_links.push_back(std::make_pair(dt.iteration, value_));
    }
    
}
Command* JbeCreator::get_cmd()
{
    return static_cast<Command *>(command);
}

LabelCreator::LabelCreator(ExData& dt)
{
    command = new Label();
    dt.labels.push_back(dt.iteration);
    stage = 0;
}
void LabelCreator::nextSet(const std::string value_, ExData& dt) {}
Command* LabelCreator::get_cmd()
{
    return static_cast<Command *>(command);
}

BegCreator::BegCreator(ExData& dt)
{
    command = new Beg();
    dt.entrypoints.push_back(dt.iteration);
    stage = 0;
}
void BegCreator::nextSet(const std::string value_, ExData& dt) {}
Command* BegCreator::get_cmd()
{
    return static_cast<Command *>(command);
}

EndCreator::EndCreator(ExData& dt)
{
    command = new End();
    dt.endpoints.push_back(dt.iteration);
    stage = 0;
}
void EndCreator::nextSet(const std::string value_, ExData& dt) {}
Command* EndCreator::get_cmd()
{
    return static_cast<Command *>(command);
}

PushCreator::PushCreator(ExData& dt)
{
    command = new Push();
    stage = 0;
}
void PushCreator::nextSet(const std::string value_, ExData& dt)
{
    switch (stage)
    {
    case 0:
        command->value = std::stoi(value_);
        break;
    }
    stage++;
}
Command* PushCreator::get_cmd()
{
    return static_cast<Command *>(command);
}

PopCreator::PopCreator(ExData& dt)
{
    command = new Pop();
    stage = 0;
}
void PopCreator::nextSet(const std::string value_, ExData& dt) {}
Command* PopCreator::get_cmd()
{
    return static_cast<Command *>(command);
}

AddCreator::AddCreator(ExData& dt)
{
    command = new Add();
    stage = 0;
}
void AddCreator::nextSet(const std::string value_, ExData& dt) {}
Command* AddCreator::get_cmd()
{
    return static_cast<Command *>(command);
}

SubCreator::SubCreator(ExData& dt)
{
    command = new Sub();
    stage = 0;
}
void SubCreator::nextSet(const std::string value_, ExData& dt) {}
Command* SubCreator::get_cmd()
{
    return static_cast<Command *>(command);
}

MulCreator::MulCreator(ExData& dt)
{
    command = new Mul();
    stage = 0;
}
void MulCreator::nextSet(const std::string value_, ExData& dt) {}
Command* MulCreator::get_cmd()
{
    return static_cast<Command *>(command);
}

DivCreator::DivCreator(ExData& dt)
{
    command = new Div();
    stage = 0;
}
void DivCreator::nextSet(const std::string value_, ExData& dt) {}
Command* DivCreator::get_cmd()
{
    return static_cast<Command *>(command);
}

OutCreator::OutCreator(ExData& dt)
{
    command = new Out();
    stage = 0;
}
void OutCreator::nextSet(const std::string value_, ExData& dt) {}
Command* OutCreator::get_cmd()
{
    return static_cast<Command *>(command);
}

InCreator::InCreator(ExData& dt)
{
    command = new In();
    stage = 0;
}
void InCreator::nextSet(const std::string value_, ExData& dt) {}
Command* InCreator::get_cmd()
{
    return static_cast<Command *>(command);
}