#include "readfile.h"

using std::runtime_error;
using std::string;
using std::vector;

ReadFile::ReadFile(const string &filename)
{
    if (open(filename))
        throw runtime_error("Не удалось откртыть файл " + filename);
}

void ReadFile::close()
{
    if (in.is_open())
        in.close();
}

bool ReadFile::open(const string &filename)
{
    in.open(filename);
    return (is_open()) ? false : true;
}

vector<string> ReadFile::readlines()
{
    vector<string> res;
    string line;

    if (!is_open())
        throw runtime_error("Файл не был открыт: " + filename);

    while (getline(in, line))
    {
        if (line.empty() and line_count == 0)
            throw runtime_error("Нет данных в файле: " + filename);

        res.push_back(line);
        line_count++;
    }
    return res;
}
