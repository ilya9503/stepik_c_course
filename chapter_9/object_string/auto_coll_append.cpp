#include <iostream>
#include <string>
enum {max_cities = 10};
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    // здесь продолжайте программу
    string cities[max_cities];
    string res;
    int count = 0;
    while (count < max_cities && cin >> cities[count++]);
/*
    for(int i = 0; i < count; ++i) {
        if(cities[i].length() > 5) {
            res.append(cities[i]);
            res.append(" ");
        }
    }
*/
    /*  Both string::size and string::length are synonyms and return the exact same value    */
    for(auto i : cities) {
        if(i.length() > 5) {
            res.append(i);
            res.append(" ");
        }
    }    
    cout << res << endl;
    
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}