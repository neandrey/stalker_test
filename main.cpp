#include "project_data.h"
#include "readfile.h"
#include "parser.h"
#include <iostream>
using namespace std;

int get_number(int, int, const string &);

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

    int number = get_number(MIN_VALUE, MAX_VALUE, pwd);
    Parser pr(SYMB_DELIMETER, number);

    // print
    for (const auto p : pr.parser(v_data))
        cout << p.second << endl;
}

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
