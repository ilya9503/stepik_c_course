/*
    9.11 Чтение и запись данных в файл в текстовом режиме
*/
#include <iostream>
#include <fstream>
 
using std::ios;
 
int main()
{
    // ------------- запись данных в файл --------------------------------
    std::ofstream ofs("out_course.dat");    // открытие файла на запись

    if(ofs.is_open()) {                     // проверка корректного открытия
        ofs << 10 << " " << -5.34 << " " << -34 << std::endl;       // операция записи в файл
        ofs << "I'm Ilya Savchenko" << std::endl;       // операция записи в файл
    }

    // ------------- чтение данных из файла --------------------------------
    int data_i1 {}, data_i2 {};             // инициализируем переменные, куда будем читать
    double data_d1 {};
    std::string str;
 
    std::ifstream ifs("out_course.dat");    // создаем и открываем файловый поток на чтение существующего файла
    
    if(ifs.is_open()) {                     // проверка корректного открытия
        // Переменные должны соответствовать типам данных, которые читаем!
        ifs >> data_i1 >> data_d1 >> data_i2;
        while(str.length() == 0 && !ifs.eof())    // все пустые строки будут пропускаться
            getline(ifs, str);                    // запишет строку полностью до символа \n
        //ifs >> str;     // запишет строку до символа пробела
    }
    std::cout << data_i1 << " " << data_d1 << " " << data_i2 << std::endl;       // операция чтения из файла
    std::cout << str << std::endl;
 
    ifs.close();            // закрытие файла (входного потока)
 
    ofs.close();            // закрытие файла (выходного потока)

    return 0;
}