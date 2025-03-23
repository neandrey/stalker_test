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

pair_data Parser::split(const std::string &s)
{
    int i = 0;
    size_t pos_start = 0, pos_end = 0;
    vec_str temp;
    while ((pos_end = s.find(delimeter_, pos_start)) != std::string::npos)
    {
        if (i == 1)
            temp.push_back(s.substr(pos_start, pos_end - pos_start - 1));
        else
            temp.push_back(s.substr(pos_start, pos_end - pos_start));
        pos_start = pos_end + delimeter_.length();
        i++;
    }
    temp.push_back(s.substr(pos_start, s.length() - pos_start));

    if (sort_value == k_name)
        return pair_data(temp[0], s);
    else if (sort_value == k_surname)
        return pair_data(temp[1], s);
    else if (sort_value == k_phone)
        return pair_data(temp[2], s);
}