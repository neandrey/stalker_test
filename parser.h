#ifndef PARSER_H
#define PARSER_H
#include <vector>
#include <string>
#include <utility>
#include <map>

enum key_sort
{
    k_name,
    k_surname,
    k_phone
};

typedef std::pair<std::string, std::string> pair_data;
typedef std::vector<std::string> vec_str;
typedef std::map<std::string, std::string> map_list;

class Parser
{
    std::string delimeter_;
    key_sort sort_value;
    pair_data split(const std::string &s);
    map_list res_value;

public:
    Parser(const std::string &delimeter, key_sort SortVal = k_surname)
        : delimeter_(delimeter),
          sort_value(SortVal) {}
    map_list parser(const vec_str &v_list);
};

#endif