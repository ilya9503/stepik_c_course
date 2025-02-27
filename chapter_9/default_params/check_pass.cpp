#include <iostream>
#include <string>
using std::string;

bool check_password(string pass, const char* chars="$%!?@#")
{
    return pass.length() >= 8 && pass.find(chars);
}

int main()
{
    string pass;
    std::cin >> pass;
    std::cout << (check_password(pass) ? "yes" : "no") << std::endl;

    return 0;
}