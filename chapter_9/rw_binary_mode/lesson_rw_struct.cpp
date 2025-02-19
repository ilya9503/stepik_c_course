#include <iostream>
#include <fstream>
 
using std::ios;

struct person {
    char fio[100];
    short old;
    unsigned int salary;
    double weight;
};

int main()
{
    // ------------- Запись данных в файл --------------------------------

    struct person ps[] {{"Ilya Savchenko", 102, 1000001, 82.6},
                        {"Bjarne Stroustrup", 56, 100001, 78.2},
                        {"Dennis Ritchie", 62, 10001, 88.9},
                        {"Kenneth Thompson", 58, 10002, 75.3},
                    };
 
    std::ofstream ofs("out_course_str.dat", ios::out | ios::binary);    // открываем файл на запись, в бинарном режиме        
 
    if(ofs.is_open()) {
        // перебор массива структур (for для коллекций)
        for(auto& p : ps)
            // записываем последовательно каждую ячейку массива ps
            // (char *)&p адрес 0 ячейки массива ps, приводим к типу char
            // & потому что не массив, а структура!
            ofs.write((char *)&p, sizeof(p));
    }
 
    ofs.close();
 
    // ------------- Чтение данных из файла --------------------------------

    struct person ps_r[10]; // сюда читаем из файла
    int count = 0;          // счетчик прочитанных структур
 
    std::ifstream ifs("out_course_str.dat", ios::in | ios::binary);    // открываем файл на чтение, в бинарном режиме
 
    if(ifs.is_open()) {
        while(ifs.read((char *)&ps_r[count], sizeof(person))) {
            count++;
        }
    }
 
    ifs.close();
 
    std::cout << count << std::endl;
    for(int i = 0; i < count; ++i) {
        std::cout << ps_r[i].fio << "\n";
        std::cout << ps_r[i].old << " " << ps_r[i].salary << " " << ps_r[i].weight << std::endl;
    }
 
    return 0;
}