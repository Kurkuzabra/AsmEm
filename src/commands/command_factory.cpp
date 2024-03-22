#include "../../include/command_factory.hpp"

CommandFactory::CommandFactory() {}

CommandCreator *CommandFactory::get_creator(std::string cmd__, ExData& dt)
{

    if (cmd__ == "push")
    {
        return new PushCreator(dt);
    }
    else if (cmd__ == "pop")
    {
        return new PopCreator(dt);
    }
    else if (cmd__ == "add")
    {
        return new AddCreator(dt);
    }
    else if (cmd__ == "sub")
    {
        return new SubCreator(dt);
    }
    else if (cmd__ == "mul")
    {
        return new MulCreator(dt);
    }
    else if (cmd__ == "div")
    {
        return new DivCreator(dt);
    }
    else if (cmd__ == "out")
    {
        return new OutCreator(dt);
    }
    else if (cmd__ == "in")
    {
        return new InCreator(dt);
    }
    else if (cmd__ == "beg")
    {
        return new BegCreator(dt);
    }
    else if (cmd__ == "end")
    {
        return new EndCreator(dt);
    }
    else if (cmd__ == "jmp")
    {
        return new JmpCreator(dt);
    }
    else if (cmd__ == "jeq")
    {
        return new JeqCreator(dt);
    }
    else if (cmd__ == "jne")
    {
        return new JneCreator(dt);
    }
    else if (cmd__ == "ja")
    {
        return new JaCreator(dt);
    }
    else if (cmd__ == "jae")
    {
        return new JaeCreator(dt);
    }
    else if (cmd__ == "jb")
    {
        return new JbCreator(dt);
    }
    else if (cmd__ == "jbe")
    {
        return new JbeCreator(dt);
    }
    else if (cmd__ == "call")
    {
        return new CallCreator(dt);
    }
    else if (cmd__ == "ret")
    {
        return new RetCreator(dt);
    }
    else if (cmd__ == "pushr")
    {
        return new PushrCreator(dt);
    }
    else if (cmd__ == "popr")
    {
        return new PoprCreator(dt);
    }
    else
    {
        dt.label_names.push_back(cmd__);
        return new LabelCreator(dt);
    }
}