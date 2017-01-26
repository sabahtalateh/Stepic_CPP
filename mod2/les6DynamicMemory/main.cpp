#include <iostream>

using namespace std;


char * resize(const char *str, unsigned size, unsigned new_size)
{
    char * new_mem = new char [new_size];

    int limit = size;
    if (new_size < size) {
        limit = new_size;
    }

    for (int i = 0; i < limit; i++) {
        new_mem[i] = str[i];
    }

    delete [] str;

    return new_mem;
}

char *getline2()
{
    const int BUF_LEN = 50;

    int len = BUF_LEN;
    int i = 0;

    char * str=(char*)malloc(BUF_LEN*sizeof(char)), c;
    while(std::cin.get(c) && c!='\n') {
        if(i==len)
            str=(char*)realloc(str, (size_t) len += BUF_LEN);
        str[i++] = c;
    }

//    char * rez = new char[i+1];
//    for(int j = 0; j < i; ++j)
//        rez[j] = str[j];
//    rez[i] = 0;
//
//    free(str);
    return str;
}

char * getline1()
{
    unsigned initial_size = 2;
    unsigned current_size = initial_size;

    char * str = new char [initial_size];
    char symbol;
    int i = 0;
    unsigned resizeCount = 1;

    while (cin.get(symbol)) {

        if (i >= initial_size) {
            str = resize(str, current_size * resizeCount, current_size * (++resizeCount));
            resizeCount++;
        }

        if (symbol == '\n') {
            str[i] = '\0';

            return str;
        } else {
            str[i] = symbol;
            i++;
        }
    }

    str[i] = '\0';
    return str;
}



//char * append_symbol()

char * addsymbol(char * str, char symbol) {

}



int main()
{
    char * pp = getline1();

    for (int i = 0; i < strlen(pp); i++) {
        cout << pp[i];
    }



//    cout << endl << endl;
//
//
//
//    char * string1 = new char [10000];
//    string1[0] = 'Y';
//    string1[1] = 'E';
//    string1[2] = 'S';
//    string1[3] = '_';
//    string1[4] = 'A';
//    string1[5] = 'H';
//    string1[6] = 'A';
//    char * string2 = resize((const char *) string1, sizeof(string1), 2 * sizeof(char));
//    cout << string2 << endl;
//
//    int * int1 = new int [100];
//    int1[0] = 2;
//    int1[1] = 2;
//    int1[2] = 8;
//
//    int * int2 = (int *) resize((const char *) int1, sizeof(int1), 2 * sizeof(int));
//
//    cout << int2[2] << endl;


//    cout << *string1 << endl;
//    cout << sizeof(char) << endl;

//    cout << endl;


    // C Like memory allocations
//    // 1000 int массив
//    int * m = (int *) malloc(1000 * sizeof(int));
//    m[10] = 10;
//
//    m = (int *) realloc(m, 2000 * sizeof(int));
//    cout << *(m + 10) << endl;
//
//    free(m);
//
//    cout << *(m + 10) << endl;
//
//    // массив из 0 - то же что и malloc(3000 * sizeof(int))
//    int * n = (int *)calloc(3000, sizeof(int));
//    cout << *(n + 10) << endl;
//
//    free(n);
//    n = 0;
//
//    // C++ Like memory allocations
//    // Выделение Тип int значение 5
//    int * five = new int(5);
//    cout << *five << endl;
//
//    //  Освобождение памяти
//    delete five;
//    cout << *five << endl;
//
//    int * arr = new int[1000];
//    cout << *arr << endl;
//    delete [] m;
//
//    // Выделение на стеке дешевле
//    // В куче фрагментация будет если много елкого выделять
//
//    // Утечки
//    int * arr1 = new int [1000];
//    arr1 = new int [2000];          // Будет утечка так как указателя на память которую занимал arr1 больше нет чтобы избежать вызывайте delete [] m
//
//    int * arr2 = new int [10000];
//    delete arr2;                    // Надо delete [] arr2 - неопределённое поведение
//
//    int * six = new int(6);
//    free(six);                      // C Like и C++ Like нельзя вместе
//
//    int * q1 = (int *) malloc(2000 * sizeof(int));
//    free(q1);       // 2 раза нельзя
//    //free(q1);
//
//    int * q2 = (int *) malloc(2000 * sizeof(int));
//    free(q2);   // Так можно
//    q2 = 0;     // Поэтому после освобождения обнуляй указатель беач
//    free(q2);

    return 0;
}