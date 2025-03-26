#include "project_data.h"
#include "readfile.h"
#include "parser.h"
#include <iostream>
using namespace std;

int get_number(int, int, const string &);
sort_key int_to_sort_key(int);

template <typename T>
void print_map(const T &);

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

    map_str_t m_str;
    map_int_t m_int;

    // create_map
    if (s_key == sort_key::sk_phone)
        for (auto v : pr.parser(v_data))
            m_int.insert({std::stoi(v.first), v.second});
    else
        for (auto v : pr.parser(v_data))
            m_str.insert({v.first, v.second});

    // print_value
    if (s_key == sort_key::sk_phone)
        print_map(m_int);
    else
        print_map(m_str);
}

// для сортировки в обратном порядке (ошибка)
//------------------------------------------------------
// FIXME
template <typename T>
void print_map(const T &m_map)
{
    for (const auto s : m_map)
        cout << s.second << endl;
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