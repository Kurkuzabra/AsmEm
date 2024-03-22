#include "../../include/serialization.hpp"

void Serialize::serialize(std::ofstream &out, std::vector<Command *> commands)
{
    std::string serialized = "";
    for (int i = 0; i < commands.size(); i++)
    {
        commands[i]->serialize(out);
    }
}

void Serialize::serialize(std::ofstream &out, ExData& dt)
{
    int dt_entry_size__ = dt.entrypoints.size();
    int dt_end_size__ = dt.endpoints.size();
    out.write(static_cast<const char *>("dt_"), 3);
    out.write(reinterpret_cast<char*>(&dt_entry_size__), 4);
    for (int i = 0; i < dt_entry_size__; i++)
    {
        out.write(reinterpret_cast<char*>(&dt.entrypoints[i]), 4);
    }
    out.write(reinterpret_cast<char*>(&dt_end_size__), 4);
    for (int i = 0; i < dt_end_size__; i++)
    {
        out.write(reinterpret_cast<char*>(&dt.endpoints[i]), 4);
    }
}

ExData Serialize::deserialize_dt(std::ifstream &in)
{
    int dt_entry_size_ = Serialize::deserialize_int(in);
    std::vector<int> enrtypoints__{};
    for (int i = 0; i < dt_entry_size_; i++)
    {
        enrtypoints__.push_back(Serialize::deserialize_int(in));
    }
    int dt_end_size_ = Serialize::deserialize_int(in);
    std::vector<int> endpoints__{};
    for (int i = 0; i < dt_end_size_; i++)
    {
        endpoints__.push_back(Serialize::deserialize_int(in));
    }
    auto base_stk = stk::Stack<int>();
    auto dt = ExData(base_stk);
    dt.entrypoints = enrtypoints__;
    dt.endpoints = endpoints__;
    return dt;
}

std::string Serialize::deserialize_reg(std::ifstream &in)
{
    char r[3];
    r[2] = '\0';
    in.read(r, 2);
    std::string reg__ = static_cast<std::string>(r);
    return reg__;
}

int Serialize::deserialize_int(std::ifstream &in)
{
    char r[5];
    r[4] = '\0';
    in.read(r, 4);
    int ans__ = *reinterpret_cast<int *>(r);
    return ans__;
}

std::vector<Command*> Serialize::deserialize_commands(std::ifstream &in)
{
    std::vector<Command*> comms__;
    while (!in.eof())
    {
        char r[4];
        r[3] = '\0';
        in.read(r, 3);
        std::string cmd__ = static_cast<std::string>(r);
        if (cmd__ == "pus")
        {
            auto t__ = new Push();
            int value__ = deserialize_int(in);
            t__->value = value__;
            comms__.push_back(t__);
        }
        else if (cmd__ == "pop")
        {
            auto t__ = new Pop();
            comms__.push_back(t__);
        }
        else if (cmd__ == "add")
        {
            auto t__ = new Add();
            comms__.push_back(t__);
        }
        else if (cmd__ == "sub")
        {
            auto t__ = new Sub();
            comms__.push_back(t__);
        }
        else if (cmd__ == "mul")
        {
            auto t__ = new Mul();
            comms__.push_back(t__);
        }
        else if (cmd__ == "div")
        {
            auto t__ = new Div();
            comms__.push_back(t__);
        }
        else if (cmd__ == "out")
        {
            auto t__ = new Out();
            comms__.push_back(t__);
        }
        else if (cmd__ == "in_")
        {
            auto t__ = new In();
            comms__.push_back(t__);
        }
        else if (cmd__ == "beg")
        {
            auto t__ = new Beg();
            comms__.push_back(t__);
        }
        else if (cmd__ == "end")
        {
            auto t__ = new End();
            comms__.push_back(t__);
        }
        else if (cmd__ == "jmp")
        {
            auto t__ = new Jmp();
            int value__ = deserialize_int(in);
            t__->value = value__;
            comms__.push_back(t__);
        }
        else if (cmd__ == "jeq")
        {
            auto t__ = new Jeq();
            int value__ = deserialize_int(in);
            t__->value = value__;
            comms__.push_back(t__);
        }
        else if (cmd__ == "jne")
        {
            auto t__ = new Jne();
            int value__ = deserialize_int(in);
            t__->value = value__;
            comms__.push_back(t__);
        }
        else if (cmd__ == "ja_")
        {
            auto t__ = new Ja();
            int value__ = deserialize_int(in);
            t__->value = value__;
            comms__.push_back(t__);
        }
        else if (cmd__ == "jae")
        {
            auto t__ = new Jae();
            int value__ = deserialize_int(in);
            t__->value = value__;
            comms__.push_back(t__);
        }
        else if (cmd__ == "jb_")
        {
            auto t__ = new Jb();
            int value__ = deserialize_int(in);
            t__->value = value__;
            comms__.push_back(t__);
        }
        else if (cmd__ == "jbe")
        {
            auto t__ = new Jbe();
            int value__ = deserialize_int(in);
            t__->value = value__;
            comms__.push_back(t__);
        }
        else if (cmd__ == "cal")
        {
            auto t__ = new Call();
            int value__ = deserialize_int(in);
            t__->value = value__;
            comms__.push_back(t__);
        }
        else if (cmd__ == "ret")
        {
            auto t__ = new Ret();
            comms__.push_back(t__);
        }
        else if (cmd__ == "pur")
        {
            auto t__ = new Pushr();
            std::string reg__ = deserialize_reg(in);
            t__->reg = reg__;
            comms__.push_back(t__);
        }
        else if (cmd__ == "por")
        {
            auto t__ = new Popr();
            std::string reg__ = deserialize_reg(in);
            t__->reg = reg__;
            comms__.push_back(t__);
        }
        else if (cmd__ == "lab")
        {
            auto t__ = new Label();
            comms__.push_back(t__);
        }
        else if (cmd__ == "dt_")
        {
            break;
        }
    }
    return comms__;
}