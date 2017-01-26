#include <iostream>

using namespace std;

int **create_array_2d(size_t a, size_t b) {
    int **m = new int *[a];
    for (size_t i = 0; i != a; ++i)
        m[i] = new int[b];

    return m;
}

void free_array_2d(int **m, size_t a, size_t b) {
    for (size_t i = 0; i != a; ++i) {
        delete[] m[i];
    }

    delete[] m;
}

int main() {

    int ** m2d2 = create_array_2d(10, 10);

    for (size_t i = 0; i != 10; i++) {
        for (size_t j = 0; j != 10; j++) {
            cout << m2d2[i][j] << ' ';
        }
        cout << endl;
    }

    int m2d[2][3] = {{1, 2, 3},
                     {4, 5, 6}};

    for (size_t i = 0; i != 2; i++) {
        for (size_t j = 0; j != 3; j++) {
            cout << m2d[i][j] << ' ';
        }
        cout << endl;
    }

    // Как выделяется под него хип
    // Массив из 20 элементов 4 х 5
    int **m2d1 = new int *[5];

    for (size_t i = 0; i != 5; ++i) {
        m2d1[i] = new int[4];
    }


    return 0;
}