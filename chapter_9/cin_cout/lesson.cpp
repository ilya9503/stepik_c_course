/*
    Потоки в языке С:
        #include <stdio.h>
        stdout - стандартный поток вывода + буфер вывода,           putchar(), printf()
        stderr - стандартный поток ошибок + буфер вывода ошибок,    perror()
        stdin - стандартный поток ввода + буфер ввода,              getchar(), scanf()

    Потоки в языке С++:
        #include <iostream>
        cin – объект класса istream для работы с потоком stdin;
            Работает со строками как scanf() в Си, считывает строку до пробельного символа
            Если нужно считать полную строку, используем getline()

        cout – объект класса ostream для работы с потоком stdout.
            << - перегруженный оператор, используется для
                Побитовый сдвиг влево
                Вывод в поток

        std::ws - пропуск пробелов
        std::cin.ignore(n, delim) - пропуск символов во входном потоке
        istream& ignore (streamsize n = 1, int delim = EOF);
            n - Maximum number of characters to extract (and ignore)
            delim - Delimiting character: The function stops extracting characters as soon as
                an extracted character compares equal to this

*/
#include <iostream>

int main()
{
    char str[100] = "Hi, Ilya!";
    short old = 99;
    double weight = 82.54;

    // На Си нужно указывать спецификатор для каждого типа
    //printf("%s\n%d\n%.2f\n", str, old, weight);

    // В С++ используются перегрузки функций, компилятор автоматически выбирает реализацию
/*
    std::cout << str << "\n";
    std::cout << old << '\n';
    std::cout << weight << std::endl;
*/
    std::cin >> str;    // работа входного потока со строкой
    //getline(cin, str);

    std::cin >> old >> weight;
    std::cout << str << '\n' << old << "\n" << weight << std::endl;



    return 0;
}