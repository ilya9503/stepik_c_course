/*
    Функция открытия потока:
        FILE* fopen(const char* path, const char* mode);
            path - путь к файлу относительный или абсолютный
            mode - режим доступа к файлу (чтение/запись, текстовый/бинарный)
            FILE* - указатель на открытый поток. NULL - если открыть не удалось

        Алгоритм отработки fopen():
            1. Системный запрос (вызов) к ОС на открытие указанного файла
            2. ОС выполняет необходимые действия и в случае успеха возвращает дескриптор файлового потока или NULL
            3. Создает входной/выходной буфер на чтение/запись

        Данные из файла читаются не по байту, а сразу порцией байт и помещаются во входной буфер.
            И то же самое с записью.
        Данные сначала попадают в выходной буфер и при достижении определенного размера, переносятся в файл

        Но все же, почему бы данные сразу не читать и записывать в файлы?
        Чтобы это делать наша программа каждый раз должна обращаться к ОС, то есть выполнять системные вызовы,
            а это не быстрый процесс..
        
    fputc() - побайтная запись в файл. Write character to stream
        int fgetc(FILE* stream);
    fgetc() - побайтное чтение из файла. Get character from stream
        int fputc(int ch, FILE* stream);

    Немного про потоки:
    This library uses what are called streams to operate with physical devices such as keyboards, printers, terminals
        or with any other type of files supported by the system.
    Streams are an abstraction to interact with these in an uniform way;
    All streams have similar properties independently of the individual characteristics of the physical media they are associated with.

    Streams are handled in the cstdio library as pointers to FILE objects.
    A pointer to a FILE object uniquely identifies a stream, and is used as a parameter in the operations involving that stream.

    FILE - Object containing information to control a stream
    Object type that identifies a stream and contains the information needed to control it,
        including a pointer to its buffer, its position indicator and all its state indicators.
    Дескриптор на файловый поток
    Файловый дескриптор — натуральное число (идентификатор), закреплённое за определённым потоком ввода-вывода.
    При создании нового потока ввода-вывода (который может быть связан как с файлами, так и с каталогами, сокетами и FIFO),
        ядро возвращает его файловый дескриптор создавшему его процессу. Файловый дескриптор может использоваться для получения доступа к потоку.

*/
#include <stdio.h>

int main(void)
{
    char str[] = "Function fputc() in action.";     // строка, которую будем записывать в файл
    char buff[100];                                 // буфер, куда будем считывать из файла

    /*  Открываем файл  на запись   */
    FILE* fp = fopen("my_file.txt", "w");   // fp - объект типа FILE. Содержит информацию о потоке (так же дескриптор файла)
    if(fp == NULL)
        return 1;

    // Побайтная запись строки в файл, пока не достигнем завершающего нуля строки
    for(int i = 0; str[i]; ++i) 
        fputc(str[i], fp);

    fclose(fp); // Закрываем файл на запись

    /*  Открываем файл  на чтение   */
    FILE* in = fopen("my_file.txt", "r");
    if(in == NULL) {
        puts("File open error");
        return 2;
    }

    /*  Читаем по-символьно в ch и записываем ch в buff[i] пока не достигнем конца файла EOF    */
    char ch;
    int i = 0;
    while((ch = fgetc(in)) != EOF)
        buff[i++] = ch;
    buff[i] = '\0'; // в конце добавляем завершающий нуль для корректной Си-строки
    puts(buff);
    
    /*
        Вызывать функцию fclose() строго обязательно после успешного открытия файла.
        Что делает fclose():
            1. Помещает все данные в файл из выходного буфера
            2. Освобождает все ресурсы, связанные с открытым файловым потоком, в том числе, память, занимаемую буфером
            3. Формирует системный вызов к ОС для освобождения файлового дескриптора
        Функция возвращает 0, если закрытие файла прошло успешно и -1, если возникли какие-либо ошибки
        Обработать эти ошибки не получится, тк они обычно связаны с системными вызовами, а это уже зона действия ОС 
    */
    fclose(fp); // Закрываем файл на чтение

    return 0;
}