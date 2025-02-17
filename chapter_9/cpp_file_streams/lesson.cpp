/*
    В языке С++ существует набор классов, упрощающих работу с файловыми потоками (или, попросту, с файлами). Они следующие:
        ifstream (Input file stream class) – для чтения данных из файла;
        ofstream (Output file stream) – для записи данных в файл;
        fstream (Input/output file stream class) – для записи и чтения данных из файла.

    И аналогичные им классы с дополнительной буквой w, означающей работу с данными типа wchar_t:
        wifstream – для чтения данных из файла;
        wofstream – для записи данных в файл;
        wfstream – для записи и чтения данных из файла.

    Чтобы связать выходной и входной потоки с определенными файлами, используется метод open()

    Режимы доступа к файлам:
        ios::in – для чтения (только для объектов классов ifstream или fstream);
        ios::out – для записи; прежние данные удаляются (только для объектов классов ofstream или fstream);
        ios::app – для дозаписи; прежние данные не удаляются;
        ios::ate – при открытии указатель файла смещается в конец;
        ios::binary – открытие файла в бинарном режиме доступа.
*/

#include <iostream>     // istream (input stream) + ostream (output stream)
#include <fstream>      // Header providing file stream classes

using std::cout;
using std::cin;
using std::endl;

int main()
{
    using std::ios;
    std::ofstream ofs("ofs.dat", ios::out | ios::binary);               // класс для записи данных в файл
    std::ifstream ifs("ifs.dat", ios::app | ios::binary);     // класс для чтения данных из файла, открытие на дозапись

//    ofs.open("ofs.dat");    // метод open(). Создастся пустой файл в рабочем каталоге
//    ifs.open("ifs.dat");
    ofs.open("my_table.txt", ios::app);

    // Проверка корректности открытия потоков
    cout << (ofs.is_open() ? "Файл ofs.dat открыт" : "Ошибка открытия файла ofs.dat") << endl;
    cout << (ifs.is_open() ? "Файл ifs.dat открыт" : "Ошибка открытия файла ifs.dat") << endl;    

    ofs.close();
    ifs.close();

    return 0;
}