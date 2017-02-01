#include <iostream>

using namespace std;

#include "Cls.h"

template <class T>
void dumpobject(T const *t) {
    unsigned char const *p = reinterpret_cast<unsigned char const *>(t);
    for (size_t n = 0 ; n < sizeof(T) ; ++n)
        printf("%02d ", p[n]);
    printf("\n");
}

char &get_c(Cls &cls) {

    cout << *(char*)(&cls);

    return *(char*)(&cls);
}


double &get_d(Cls &cls) {
    return *(double*)((char*)(&cls) + 8);
}


int &get_i(Cls &cls) {
    return *(int*)((char*)(&cls) + 16);
}

int main() {

    int const * a = new int [10][10];

//    a[2] = 3;


//    int * y =int  (int *) x;
//
//    cout << *y;

//    Cls *cls = new Cls('a', 27.9, 1);
//
//    get_c(*cls);
//
//    double & d = get_d(*cls);

//    cout << &d;

//    char & c = get_c(*cls);
//    cout << c;
//    c = 'b';
//    cout << c;
//    cout << cls->getC();

//    cout << cls;

//    cout << &(cls + 1);

//    get_c(*cls);

//    cout << get_c(*cls) << endl;
//    cout << cls << endl;


    return 0;
}