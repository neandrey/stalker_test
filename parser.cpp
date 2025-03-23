#include "parser.h"
using std::string;

map_list Parser::parser(const vec_str &v_list)
{
    for (auto s : v_list)
    {
        if (s.empty())
            continue;
        res_value[split(s).first] = split(s).second;
    }
    return res_value;
}

name_phone Parser::split(const std::string &s)
{
    size_t pos = 0;
    pos = s.find(delimeter_);
    string surname = s.substr(0, pos);
    string phone = s.substr(pos + 1, s.length());
    // int number = std::stoi(s.substr(pos + 1, s.length()));

    if (sort_value == k_surname)
        return name_phone(surname, phone);
    else if (sort_value == k_phone)
        return name_phone(phone, surname);
}