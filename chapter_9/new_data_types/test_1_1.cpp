#include <iostream>

int main() {
    int x;
    bool fl_even = true;
    while (std::cin >> x && x) {
        fl_even &= ~x;
    }
    fl_even ? std::cout << "even" : std::cout << "no";

    return 0;
}