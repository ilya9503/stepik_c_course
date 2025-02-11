#include <iostream>

enum { total_marks=23 };

int main()
{
    short marks[total_marks] = {0};

    // здесь продолжайте программу
    int count = 0;
    while (count < total_marks && std::cin >> marks[count])
        ++count;
        
    // новый цикл for для коллекций из стандарта С++11
    for (short& ref_marks : marks) {
        ref_marks = (ref_marks < 3) ? 0 : ref_marks;
        std::cout << ref_marks << ' ';
    }

    std::cout << std::endl;
    
    return 0;
}