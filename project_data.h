#ifndef PROJECT_DATA
#define PROJECT_DATA
#include <string>
#include <vector>
#include <map>

typedef std::pair<std::string, std::string> pair_data_t;
typedef std::vector<std::string> vector_str_t;
typedef std::vector<pair_data_t> vector_pair_t;
typedef std::multimap<std::string, std::string> map_str_t;
typedef std::multimap<int, std::string> map_int_t;

#define FILENAME "test.txt"
#define SYMB_DELIMETER " "

#define MIN_VALUE 1
#define MAX_VALUE 3

// данные для сортировке
enum sort_key
{
    sk_name = 1,
    sk_surname,
    sk_phone
};

const std::string pwd = "Для сортировки по Имени введите:   1\n"
                        "Для сортировки по Фамилии введите: 2\n"
                        "Для сортировки по Номеру введите:  3\n"
                        "Введите ключ сортировки: ";

#endif