/*
    Пространства имен и обращение к ним
*/

#include <iostream>

// Так же допускается добавлять сразу все объекты в одно пространство
namespace firstSpace {
void foo()
{
    std::cout << "function from firstSpace: foo()" << std::endl;
}

struct point {
    double x, y;
};
}

// Так разносить пространства имен допускается, когда проект разнесен на модули
/*
namespace firstSpace {
struct point {
    double x, y;
};
}
*/

namespace secondSpace {
void foo()
{
    std::cout << "function from secondSpace: foo()" << std::endl;
}

inline namespace params {   // Ключевое слово inline
int global_a = 5;
}
}

int main()
{
    firstSpace::foo();
    secondSpace::foo();
    firstSpace::point pt {};
    secondSpace::params::global_a;  // обращение без и с ключевым словом inline
    secondSpace::global_a;          // влияние ключевого слова inline, теперь ПИ params можно опускать

    return 0;
}