/*
    Для чтения из файла в бинарном доступе используется функция:
    Read block of data from stream
    size_t fread ( void * ptr, size_t size, size_t count, FILE * stream );
        ptr - pointer to a block of memory with a size of at least (size*count) bytes, converted to a void*
        size - Size, in bytes, of each element to be read.
        count - number of elements, each one with a size of size bytes
        stream - pointer to a FILE object that specifies an input stream
        Return value
            The total number of elements successfully read is returned

*/
#include <stdio.h>
 
int main(void)
{
    int r_var_i;
    double r_pi;
    char r_ch;
 
    FILE* in = fopen("my_file.txt", "rb");
    if(in == NULL) {
        perror("my_file.txt");
        return 1;
    }
 
    fread(&r_var_i, sizeof(r_var_i), 1, in);    // чтение из файла в бинарном режиме
    fread(&r_pi, sizeof(r_pi), 1, in);
    fread(&r_ch, sizeof(r_ch), 1, in);
 
    fclose(in);
 
    printf("r_var_i = %d, r_pi = %f, r_ch = %c\n", r_var_i, r_pi, r_ch);
 
    return 0;
}