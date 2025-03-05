#include <iostream>
#include <string>

void get_line(char* buff, size_t max_buff)
{
    std::string line;
    getline(std::cin, line);

    int i = 0;
    for(;i < line.length() && i < max_buff-1; ++i)
        buff[i] = line[i];
    buff[i] = '\0';
}

int main(void)
{
    char str[100];
//  get_line(str, sizeof(str));

    // здесь продолжайте функцию main
    size_t str_size = sizeof(str) / sizeof(*str);
    
    auto gl = [&str, str_size] () {
        std::string line;
        getline(std::cin, line);
    
        int i = 0;
        for(;i < line.length() && i < str_size-1; ++i)
            str[i] = line[i];
        str[i] = '\0';
    };

    gl();
    std::cout << str << std::endl;

    return 0;
}