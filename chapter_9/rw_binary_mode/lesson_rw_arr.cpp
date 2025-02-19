/*
    Бинарный режим (представление на уровне отдельных байт)
    Бинарный режим позволяет сохранять данные в файл в том же виде, в котором они представлены в ячейках памяти устройства
    Метод write:
        std::ostream::write - Write block of data
        ostream& write (const char* s, streamsize n);
        Inserts the first n characters of the array pointed by s into the stream.
    Метод read:
        std::istream::read - Read block of data
        istream& read (char* s, streamsize n);
        Extracts n characters from the stream and stores them in the array pointed to by s
*/
#include <iostream>
#include <fstream>
 
using std::ios;
 
int main()
{
    // ------------- Запись данных в файл --------------------------------

    double pow[] {4.3, -54.33, 0.01};   // запишем в файл этот массив
 
    std::ofstream ofs("out_course.dat", ios::out | ios::binary);    // открываем файл на запись, в бинарном режиме
 
    if(ofs.is_open()) {
        //ofs << pow;   // сохранит адрес массива в файле
        //(char*)pow - приводим указатель к типу char (1 байт)
        ofs.write((char*)pow, sizeof(pow));
    }

    // в файл запишется 24 байта 8 * 3
 
    ofs.close();

    // ------------- Чтение данных из файла --------------------------------

    double read_pow[5] {0}; // читать из файла будем в этот массив
 
    std::ifstream ifs("out_course.dat", ios::in | ios::binary);    // открываем файл на чтение, в бинарном режиме
 
    if(ifs.is_open()) {
        ifs.read((char *)read_pow, sizeof(pow));
    }
 
    for(double x : read_pow)
        std::cout << x << " ";
 
    ifs.close();

    return 0;
}