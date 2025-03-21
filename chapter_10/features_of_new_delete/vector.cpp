#include <iostream>

struct vector {
    int x, y, z;
    // "Deleted vector: <значение x>, <значение y>, <значение z>"
    ~vector() { std::cout << "Deleted vector: " << this->x << ", " << this->y << ", " << this->z << std::endl; }
};

int main()
{
    int x, y, z;
    std::cin >> x >> y >> z;

    vector* obj {new vector{x, y, z}};

    delete obj;
    obj = nullptr;

    return 0;
}