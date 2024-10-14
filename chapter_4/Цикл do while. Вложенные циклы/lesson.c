#include <stdio.h>

int main(void)
{
    int pass_code = 13;
    int enter_code;
    int c;

    // Пример применения цикла do-while
    do {
        printf("Please enter the secret code: ");
        scanf("%d", &enter_code);
        
        // Очистка буфера входного потока stdin после каждого ввода
        while ((c = getchar()) != '\n' && c != EOF)
            {   }
    } while (enter_code != pass_code);
    
    printf("Access is allowed\n");

    return 0;
}