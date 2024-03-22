#include "../../include/executor.hpp"

Executor::Executor(stk::Stack<int>& base_stk_, std::vector<Command*> comms_, ExData dt_) : dt(ExData(base_stk_)), commands(comms_)
{
    dt.endpoints = dt_.endpoints;
    dt.entrypoints = dt_.entrypoints;
    dt.labels = dt_.labels;
    dt.label_names = dt.label_names;
    dt.iteration = 0;
};

void Executor::execute()
{
    int en_en_iter = 0;
    for (; dt.iteration < commands.size(); dt.iteration++)
    {
        if (en_en_iter >= dt.entrypoints.size())
        {
            break;
        }
        if (dt.depth > 0 || (dt.iteration >= dt.entrypoints[en_en_iter] && dt.iteration <= dt.endpoints[en_en_iter]))
        {
            commands[dt.iteration]->doit(dt);
        }
        else if (dt.iteration >= dt.endpoints[en_en_iter])
        {
            en_en_iter++;
        }
    }
}