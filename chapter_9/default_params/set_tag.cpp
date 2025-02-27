#include <iostream>
#include <string.h>
#include <cstring>

using std::string;

void set_tag(char* str, size_t max_len, const char* append_str="h1")
{
    // "<h1>Hello C++</h1>"
    char temp[100] {0};
    char* res = temp;
    res = std::strcat(res, "<");
    res = std::strcat(res, append_str);
    res = std::strcat(res, ">");
    res = std::strncat(res, str, max_len);
    res = std::strcat(res, "</");
    res = std::strcat(res, append_str);
    res = std::strcat(res, ">");
    std::strcpy(str, res);
}

int main()
{
    std::string title, tag;


    getline(std::cin, title);
    getline(std::cin, tag);

    // здесь продолжайте функцию main
    char* title_cstr = new char[title.length() + 1]; // Выделяем память, аналог malloc()
    std::strcpy(title_cstr, title.c_str());          // Копируем строку

    char* tag_cstr = new char[tag.length() + 1];
    std::strcpy(tag_cstr, tag.c_str());

    char temp[100] {0};                 // копируем title во временную переменную для повторного вызова
    std::strcpy(temp, title_cstr);
    char* temp_ptr = temp;

    set_tag(title_cstr, std::strlen(title_cstr));
    std::cout << title_cstr << std::endl;

    set_tag(temp_ptr, std::strlen(temp_ptr), tag_cstr);
    std::cout << temp_ptr << std::endl;


    delete[] title_cstr; // Освобождаем память, аналог free()
    delete[] tag_cstr;

    return 0;
}