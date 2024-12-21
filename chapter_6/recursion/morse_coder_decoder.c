#include <stdio.h>
#include <string.h>

char to_uppercase(char);
int find_code(char*, const char**, size_t);
void msg_to_morse(char*, char*, const char**, const char*);
void morse_to_msg(char*, char*, const char**, size_t, const char**);

int main(void)
{
    char str[100] = {0};
    int choise = 0;

    puts("For coding message to Morse enter 0, for decoding enter 1:");

    if(scanf("%d", &choise) != 1) {
        printf("Input error!");
        return 0;
    }

    if(choise)
        puts("Enter code:");
    else
        puts("Enter message:");
    fflush(stdin);  // очистим буфер ввода, чтобы ввод fgets() был корректен

    fgets(str, sizeof(str)-1, stdin);
    char* ptr_n = strrchr(str, '\n');
    if(ptr_n != NULL)
        *ptr_n = '\0';

    // здесь продолжайте функцию main
    const char symbols[] = "AJS2BKT3CLU4DMV5ENW6FOX7GPY8HQZ9IR10 ";
    const char* symbols_1[] = { "A", "J", "S", "2", "B", "K", "T",      // Пришлось переделать из-за конвертации символов в строки
                        "3", "C", "L", "U", "4", "D", "M",
                        "V", "5", "E", "N", "W", "6", "F",
                        "O", "X", "7", "G", "P", "Y", "8",
                        "H", "Q", "Z", "9", "I", "R", "1",
                        "0", " "};
    const char* morse[] = {".-", ".---",	"...", "..---", "-...", "-.-", "-", 
                     "...--", "-.-.", ".-..", "..-", "....-", "-..", "--", 
                     "...-", ".....", ".", "-.", ".--", "-....", "..-.", 
                     "---", "-..-", "--...", "--.", ".--.", "-.--", 
                     "---..", "....", "--.-", "--..", "----.", "..", ".-.", 
                     ".----", "-----", "-...-"};
    size_t morse_len = sizeof(morse) / sizeof(*morse);
    char res[100] = {0};

    if(choise)
        morse_to_msg(res, str, morse, morse_len, symbols_1);
    else
        msg_to_morse(res, str, morse, symbols);
    
    printf("%s", res);

    return 0;
}

// Кодирование сообщения в код Морзе
void msg_to_morse(char* dest, char* src, const char** codes, const char* symbols)
{
    char* ptr_src = src;
    while(*(ptr_src)) {
        // 1. Ищем n-ый символ из src в symbols (Заменяем прописные на заглавные при необходимости)
        char* ptr = strchr(symbols, to_uppercase(*ptr_src));
        // 2. Сопоставляем его с позицией в таблице codes
        strcat(dest, codes[ptr - symbols]);
        // 3. Добавляем пробел
        if(*(ptr_src+1))
            strcat(dest, " ");
        ++ptr_src;
    }
}

// Раскодирование кода Морзе в сообщение
void morse_to_msg(char* dest, char* src, const char** table, size_t table_len, const char** symbols)
{
    // 1. Получаем код n-ого символа до знака пробел
    char* space = strchr(src, ' ');          // указатель на пробел
    char char_code[6] = {0};                 // код n-ого символа
    char zeros[6] = {0};
    strncat(char_code, src, space - src);    // вырезаем кусок из строки
    // 2. Ищем кусок в таблице
    int index = find_code(char_code, table, table_len); 
    // 3. Вставляем символ в результирующую строку symbols[index]
    strncat(dest, symbols[index], 1);
    // 4. Сдвигаемся на пробел
    ++space;
    char* space_old = space;
    // 5. Обнуляем код символа
    strncpy(char_code, zeros, 6);            

    while(space != NULL && *space != 0) {   // условие для пробела в конце
        space_old = space;
        space = strchr(space, ' ');
        strncat(char_code, space_old, space - space_old);
        index = find_code(char_code, table, table_len);
        strncat(dest, symbols[index], 1);
        strncpy(char_code, zeros, 6);
        if(space != NULL)
            ++space;
    }
}

// Функция поиска позиции символа в таблицы кодов Морзе
int find_code(char* char_code, const char** table, size_t table_len)
{
    for (int i = 0; i < table_len; ++i)
        if(! strcmp(table[i], char_code))
            return i;
}

// Функция замены строчных буквы на заглавные
char to_uppercase(char ch)
{
    if(ch >= 'a' && ch <= 'z')
        ch -= 32;
    return ch;
}