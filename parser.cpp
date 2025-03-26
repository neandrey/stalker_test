#include "parser.h"
#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
using std::string;

/**
 * @brief Парсим данные из файла
 *
 * @param v_list
 * @return l_multimap
 */
l_multimap Parser::parser(const vector_str &v_list)
{
    for (const auto &s : v_list)
    {
        if (s.empty())
            continue;
        pair_data key_and_value = choice_sort(split(s));
        res_multimap.insert({key_and_value.first, key_and_value.second});
    }
    return res_multimap;
}

/**
 * @brief разделяем строку на составляющие
 *
 * @param s
 * @return pair_data
 */
vector_str Parser::split(const std::string &s)
{
    int i = 0;
    size_t pos_start = 0, pos_end = 0;
    vector_str temp;
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
 * @return pair_data
 */
pair_data Parser::choice_sort(const vector_str &v)
{
    if (sort_value == sk_name)
        return pair_data(v[df_name], forming_string(v, df_name, df_surname, df_phone));
    else if (sort_value == sk_surname)
        return pair_data(v[df_surname], forming_string(v, df_surname, df_name, df_phone));
    else if (sort_value == sk_phone)
        return pair_data(v[df_phone], forming_string(v, df_phone, df_surname, df_name));
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
string Parser::forming_string(const vector_str &v, int first, int second, int three)
{
    return string(v[first] + ' ' + v[second] + ' ' + v[three]);
}

sort_key Parser::int_to_sort_key(int number)
{
    switch (number)
    {
    case 1:
        return sort_key::sk_name;
        break;
    case 2:
        return sort_key::sk_surname;
        break;
    case 3:
        return sort_key::sk_phone;
        break;

    default:
        cerr << "Номер " << number << " не имеет значения для ключа поиска" << endl;
        exit(1);
        break;
    }
}