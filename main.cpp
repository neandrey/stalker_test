#include "readfile.h"
#include "parser.h"
#include <iostream>
using namespace std;

const string pwd = "Для сортировки по Имени введите:   0\n"
                   "Для сортировки по Фамилии введите: 1\n"
                   "Для сортировки по Номеру введите:  2\n"
                   "Введите ключ сортировки: ";

int get_number(int, int, const string &);

int main()
{
    vector<string> v_data;
    try
    {
        ReadFile rf("test.txt");
        v_data = rf.readlines();
    }
    catch (const runtime_error &e)
    {
        cout << e.what() << endl;
        return 1;
    }

    int number;
    key_sort in_value;

    number = get_number(0, 2, pwd);

    switch (number)
    {
    case 0:
        in_value = k_name;
        break;

    case 1:
        in_value = k_surname;
        break;

    case 2:
        in_value = k_phone;
        break;
    }

    Parser pr(" ", in_value);
    for (const auto p : pr.parser(v_data))
        cout << p.second << endl;
}

int get_number(int min, int max, const string &s)
{
    cout << s;
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