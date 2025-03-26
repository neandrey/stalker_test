#include "project_data.h"
#include "readfile.h"
#include "parser.h"
#include <iostream>
using namespace std;

int get_number(int, int, const string &);
sort_key int_to_sort_key(int);
void print_map(multimap_str_t &, sort_key);

int main()
{
    vector<string> v_data;
    try
    {
        ReadFile rf(FILENAME);
        v_data = rf.readlines();
    }
    catch (const runtime_error &e)
    {
        cout << e.what() << endl;
        return 1;
    }

    sort_key s_key;
    int number = get_number(MIN_VALUE, MAX_VALUE, pwd);
    try
    {
        s_key = int_to_sort_key(number);
    }
    catch (const runtime_error &e)
    {
        cout << e.what() << endl;
        return 1;
    }

    Parser pr(SYMB_DELIMETER, s_key);

    multimap_str_t m_map;

    // create_map
    for (auto v : pr.parser(v_data))
        m_map.insert({v.first, v.second});

    // print_value
    print_map(m_map, s_key);
}

// для сортировки в обратном порядке (ошибка)
//------------------------------------------------------
// FIXME
void print_map(multimap_str_t &m_map, sort_key s_key)
{
    if (s_key == sk_phone)
    {
        for (auto it = m_map.rbegin(); it != m_map.rend(); ++it)
            cout << it->second << endl;
    }
    else
    {
        for (const auto s : m_map)
            cout << s.second << endl;
    }
}
//------------------------------------------------------------------------
/**
 * @brief ввод числа для сортировки
 *
 * @param min
 * @param max
 * @param s
 * @return int
 */
int get_number(int min, int max, const string &pwd)
{
    cout << pwd;
    int number = min;
    while (true)
    {
        cin >> number;
        if ((number >= min) && (number <= max) && (cin.peek() == '\n'))
            break;
        else
        {
            cout << "Разрешено вводить только числа от " << min << " до " << max << endl;
            cin.clear();
            while (cin.get() != '\n')
            {
            }
        }
    }
    return number;
}
//--------------------------------------------
sort_key int_to_sort_key(int number)
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
        throw runtime_error("Введенное число " + to_string(number) +
                            "не соответствует ни одному ключу сортировки");
        break;
    }
}