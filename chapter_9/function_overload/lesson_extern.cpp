/*
    В языке Си функции имеют уникальный имена
    Компоновщик, встречая имя функции в объектном файле, подставляет вместо него соответствующий код вызова
    Для функции
        int modul(int x);
        Метка в С       modul
        Метка в С++     _Z5moduli (компилятор g++)
    Здесь _Z – это специальный префикс, означающий начало метки функции;
    число 5 – количество символов в имени функции;
    i – внутреннее обозначение стандартного типа int;

    Другие компиляторы языка С++ и даже разные версии одного и того же компилятора,
        могут по разному строить эти метки

    Для того, чтобы писать функции для языков С и С++ одновременно, используется директива extern "C"

*/

#include <iostream>

using std::cout;
using std::endl;

#ifdef __cplusplus                  // эту метку понимают компиляторы С++, и не понимают С
extern "C" {                        // существует в языке С++ и не существует в языке С
#endif
void show_msg(const char* msg)      // эта функция будет работать как в С, так и в С++
{
    puts("-----------------------");
    puts(msg);
    puts("-----------------------");
}
 
#ifdef __cplusplus
}
#endif

int main()
{
    show_msg("Hello, Ilya!");

    return 0;
}