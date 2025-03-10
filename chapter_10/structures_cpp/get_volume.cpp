#include <iostream>
using std::cin;
using std::cout;
using std::endl;

struct volume {
    int width, height, depth;
    int get_volume() {return width*height*depth;}
};

int main(void)
{
    volume data;
    cin >> data.width >> data.height >> data.depth;
    cout << data.get_volume() << endl;

    return 0;
}