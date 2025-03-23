#include "readfile.h"
#include "parser.h"
#include <iostream>
using namespace std;

int main()
{
    ReadFile rf("test.txt");
    vector<string> v_data = rf.readlines();

    Parser pr1(";", k_surname);
    for (const auto p : pr1.parser(v_data))
    {
        cout << p.first << " " << p.second << endl;
    }

    cout << endl;

    Parser pr2(";", k_phone);
    for (const auto p : pr2.parser(v_data))
    {
        cout << p.first << " " << p.second << endl;
    }
}