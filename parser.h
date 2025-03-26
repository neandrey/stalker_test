#ifndef PARSER_H
#define PARSER_H
#include <vector>
#include <string>
#include <utility>
#include <map>

typedef std::pair<std::string, std::string> pair_data;
typedef std::vector<std::string> vector_str;
typedef std::multimap<std::string, std::string> l_multimap;

// данные для сортировке
enum sort_key
{
    sk_name = 1,
    sk_surname,
    sk_phone
};

class Parser
{
    // данные в файле
    enum data_file
    {
        df_surname,
        df_name,
        df_phone
    };

    std::string delimeter_;
    sort_key sort_value;
    l_multimap res_multimap;

    // help_func
    vector_str split(const std::string &s);
    pair_data choice_sort(const vector_str &v);
    std::string forming_string(const vector_str &, int, int, int);
    sort_key int_to_sort_key(int);

public:
    Parser(const std::string &delimeter, int sort_value = (int)sk_name)
        : delimeter_(delimeter),
          sort_value(int_to_sort_key(sort_value)) {}
    l_multimap parser(const vector_str &v_list);
};

#endif