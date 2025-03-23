#ifndef READFILE_H
#define READFILE_H

#include <string>
#include <fstream>
#include <stdexcept>
#include <vector>

class ReadFile
{
    size_t line_count = 0;
    std::string filename;
    std::ifstream in;

    bool is_open() const { return in.is_open(); }
    bool open(const std::string &filename);
    void close();

public:
    ReadFile(const std::string &filename);
    ~ReadFile() { close(); }
    std::vector<std::string> readlines();
};

#endif