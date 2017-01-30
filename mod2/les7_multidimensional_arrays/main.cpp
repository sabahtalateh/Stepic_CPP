#include <iostream>
#include <stddef.h>

using namespace std;

int **create_array_2d(size_t a, size_t b) {
    int **m = new int *[a];
    for (size_t i = 0; i != a; ++i)
        m[i] = new int[b];

    return m;
}

int **create_array_2d_effective(size_t a, size_t b) {
    int **m = new int *[a];
    m[0] = new int [a * b];
    for (int i = 1; i != a; ++i)
        m[i] = m[i-1] + b;

    return m;
}

void free_array_2d(int **m, size_t a, size_t b) {
    for (size_t i = 0; i != a; ++i) {
        delete[] m[i];
    }

    delete[] m;
}

void free_array_2d_effective(int **m) {
    delete [] m[0];
    delete [] m;
}

int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
    int ** transposed = create_array_2d_effective(cols, rows);

    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            transposed[j][i] = m[i][j];
        }
    }

    return transposed;
}

void swap_min(int *m[], unsigned rows, unsigned cols)
{
    int min = m[0][0];
    unsigned min_row_n = 0;

    for (std::size_t i = 0; i != (rows); i++) {
        for (std::size_t j = 0; j != (cols); j++) {
            if (m[i][j] < min) {
                min = m[i][j];
                min_row_n = (unsigned int) i;
            }
        }
    }

    if (min_row_n != 0) {
        int * t = m[min_row_n];
        m[min_row_n] = m[0];
        m[0] = t;
    }
}

int main() {

    int **m = create_array_2d_effective(2,3);
    m[0][0] = 2;
    m[0][1] = 4;
    m[0][2] = 5;

    m[1][0] = 1;
    m[1][1] = 2;
    m[1][2] = 2;

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    swap_min(m, 2, 3);

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }



//    int **matrix = create_array_2d_effective(2,3);
//    matrix[0][0] = 1;
//    matrix[0][1] = 1;
//    matrix[0][2] = 1;
//
//    matrix[1][0] = 2;
//    matrix[1][1] = 2;
//    matrix[1][2] = 2;
//
//    for (size_t i = 0; i != 2; i++) {
//        for (size_t j = 0; j != 3; j++) {
//            cout << matrix[i][j] << ' ';
//        }
//        cout << endl;
//    }
//
//    cout << endl;
//    matrix[2][0] = 3;
//    matrix[2][1] = 3;
//    matrix[2][2] = 3;

//    int ** t = transpose((const int *const *) matrix, 2, 3);
//
//    for (size_t i = 0; i != 3; i++) {
//        for (size_t j = 0; j != 2; j++) {
//            cout << t[i][j] << ' ';
//        }
//        cout << endl;
//    }

//    for (size_t i = 0; i != 3; i++) {
//        for (size_t j = 0; j != 2; j++) {
//            cout << matrix[i][j] << ' ';
//        }
//        cout << endl;
//    }
//
//    cout << endl;
//
//    for (size_t i = 0; i != 3; i++) {
//        for (size_t j = 0; j != 2; j++) {
//            cout << t[i][j] << ' ';
//        }
//        cout << endl;
//    }


//    *(t[0]) = ;
//    t[0][1] = 1;
//    t[0][2] = 1;

    // Как эффективно выделить память под масив 5 на 4. т е 20 ячеек
    // Вот так пёс
//    int ** m = new int * [5];
//    m[0] = new int [5 * 4];
//    for (size_t i = 0; i != 5; ++i) {
//        m[i] = m[i - 1] + 4;
//    }
//
//    int ** m2d2 = create_array_2d(10, 10);
//
//    for (size_t i = 0; i != 10; i++) {
//        for (size_t j = 0; j != 10; j++) {
//            cout << m2d2[i][j] << ' ';
//        }
//        cout << endl;
//    }
//
//    int m2d[2][3] = {{1, 2, 3},
//                     {4, 5, 6}};
//
//    for (size_t i = 0; i != 2; i++) {
//        for (size_t j = 0; j != 3; j++) {
//            cout << m2d[i][j] << ' ';
//        }
//        cout << endl;
//    }
//
//    // Как выделяется под него хип
//    // Массив из 20 элементов 4 х 5
//    int **m2d1 = new int *[5];
//
//    for (size_t i = 0; i != 5; ++i) {
//        m2d1[i] = new int[4];
//    }


    return 0;
}