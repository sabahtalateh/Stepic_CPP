#include <iostream>

#include "String.h"
#include "IntArray.h"

using namespace std;

//void foo(String & string) {
//    string.str = "22";
//    cout << string.str << endl;
//}

int main() {

    const int * const i =  new int [10];

//    i[0] = 1;

    IntArray * a = new IntArray(2);



    int t1 = 2;
    int t2 = 2;



//    cout << i[0];
    cout << ++t1 << endl;
    cout << t2++ << endl;

//    String const * s1 = new String("CPP YEAH!");
//    String * s2 = new String(*s1);
//
//    String * s3 = new String("CPP..... Oh no...");
//    s1 = s3;
//
//    s3->str = "III";
//
//    cout << s1->str << endl;
//    cout << s2->str << endl;
//    cout << s3->str << endl;

//    String * s1 = new String("WW");
//    s1 = s;
//    s1->str = "22";

//    cout << s->str << endl;
//    cout << s1->str << endl;

//    foo(*s);
//
//    cout << s->str << endl;

//    cout << s->size;

    return 0;
}