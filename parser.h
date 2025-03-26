#ifndef PARSER_H
#define PARSER_H
#include "project_data.h"

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
    // l_multimap res_multimap;

    // help_func
    vector_str_t split(const std::string &s);
    pair_data_t key_and_data(const vector_str_t &v);
    std::string forming_string(const vector_str_t &, int, int, int);

public:
    Parser(const std::string &delimeter, sort_key sort_value = sk_name)
        : delimeter_(delimeter),
          sort_value(sort_value) {}
    vector_pair_t parser(const vector_str_t &v_list);
};

#endif