#include <iostream>

using namespace std;

#include "Cls.h"

char &get_c(Cls &cls) {

    cout << &cls;

}

int main() {

    Cls *cls = new Cls('a', 1.0, 1);

//    cout << &(cls + 1);

    get_c(*cls);

//    cout << get_c(*cls) << endl;
//    cout << cls << endl;


    return 0;
}