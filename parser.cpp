#include "parser.h"
using std::string;

/**
 * @brief Парсим данные из файла
 *
 * @param v_list
 * @return l_multimap
 */
vector_pair_t Parser::parser(const vector_str_t &v_list)
{
    vector_pair_t v_res;
    for (const auto &s : v_list)
    {
        if (s.empty())
            continue;
        v_res.push_back(key_and_data(split(s)));
        // res_multimap.insert({key_and_value.first, key_and_value.second});
    }
    return v_res;
}

/**
 * @brief разделяем строку на составляющие
 *
 * @param s
 * @return pair_data_t
 */
vector_str_t Parser::split(const std::string &s)
{
    int i = 0;
    size_t pos_start = 0, pos_end = 0;
    vector_str_t temp;
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

    return temp;
}

/**
 * @brief Сортируем по ключу
 *
 * @param v
 * @return pair_data_t
 */
pair_data_t Parser::key_and_data(const vector_str_t &v)
{
    if (sort_value == sk_name)
        return pair_data_t(v[df_name], forming_string(v, df_name, df_surname, df_phone));
    else if (sort_value == sk_surname)
        return pair_data_t(v[df_surname], forming_string(v, df_surname, df_name, df_phone));
    else if (sort_value == sk_phone)
        return pair_data_t(v[df_phone], forming_string(v, df_phone, df_surname, df_name));
}

/**
 * @brief  Формируем строку
 *
 * @param v
 * @param first
 * @param second
 * @param three
 * @return string
 */
string Parser::forming_string(const vector_str_t &v, int first, int second, int three)
{
    return string(v[first] + ' ' + v[second] + ' ' + v[three]);
}
