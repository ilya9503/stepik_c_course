#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    // здесь продолжайте программу
    string URL;
    std::getline(cin, URL, '\n');
    
    // std::string::erase OR std::string::replace
    std::size_t found = 0;
    while (found != string::npos) {
        found = URL.find("--");
        if(found != string::npos)
            URL.replace(found, 2, "-");
    }

/*
    Красивое короткое решение, но 2 раза вызываетсяя find

    while (s.find("--") != -1)
        s.replace(s.find("--"), 2, "-");

*/
    
    cout << URL << endl;

    return 0;
}

