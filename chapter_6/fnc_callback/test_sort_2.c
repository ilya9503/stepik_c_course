#include <stdio.h>
#include <string.h>


int match_ab(const char a, const char b);

void sort_string( char *str, size_t max_len, int ( * match ) ( const char a, const char b ) ) {
    max_len = strlen( str );
    char temp;
    int pos;
    for ( int i = 0; i < max_len - 1; i++ ) {
        pos = i;
        for ( int j = i + 1; j < max_len; ++j ) 
            if ( match( str[pos], str[j] ) ) 
                pos = j;
        if ( pos != i ) {
            temp = str[i];
            str[i] = str[pos];
            str[pos] = temp;
        }             
    }
}

int main(void)
{
    char str[ 100 ] = {"Super podvig 325"};
    /*
    fgets( str, sizeof( str ) - 1, stdin );
    char* ptr_n = strrchr(str, '\n');
    if(ptr_n != NULL)
        *ptr_n = '\0';
    */
    sort_string( str, strlen( str ), match_ab );
    puts( str );

    return 0;
}

int match_ab(const char a, const char b) {
    char numbers[] = "0123456789";

    if ( strchr( numbers, a ) != NULL && strchr( numbers, b ) == NULL )
        return 0;

    if ( strchr( numbers, a ) == NULL && strchr( numbers, b ) != NULL )
        return 1;
       
    return a > b; 
}