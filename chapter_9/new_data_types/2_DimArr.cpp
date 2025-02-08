#include <iostream>

using std::cin;
using std::cout;
using std::endl;

enum {matrix_size=4};

int main()
{
    short matrix[matrix_size][matrix_size] = {0};

    // здесь продолжайте программу
    int count_rows = 0, count_cols = 0;
    
    while((count_rows != count_cols != matrix_size) && (cin >> matrix[count_rows][count_cols++])) {
        if(count_cols == matrix_size) {
            count_cols = 0;
            ++count_rows;
        }
    }
    
    for(int i = 0; i < matrix_size; ++i)
        for(int j = 0; j < matrix_size; ++j)
            cout << matrix[i][j] << ((j == matrix_size - 1) ? '\n' : ' ');
        /*
            if(j == matrix_size-1)
                cout << matrix[i][j] << endl;
            else
                cout << matrix[i][j] << ' ';
        */

    return 0;
}