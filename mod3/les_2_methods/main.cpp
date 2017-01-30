#include <iostream>
#include <cmath>

#include "point.h"
#include "string.cpp"

using namespace std;


struct Segment {
    Point p1;
    Point p2;

    double length() {
        double dx = p1.x - p2.x;
        double dy = p1.y - p2.y;

        return sqrt(dx * dx + dy * dy);
    }
};

int main() {

    cout << sizeof(String) << endl;

    String str1("Hello");
    cout << str1.size << endl;
    cout << str1.str << endl;

    String str2(1, '_');
    cout << str2.size << endl;
    cout << str2.str << endl;

    String str3(" World");


    cout << "++++" << endl;
    str1.append(str3);
    cout << str1.size << endl;
    cout << str1.str << endl;
    cout << "++++" << endl;

    Segment s1 = {{0.4, 1.8}, {2.2, 18.6}};
    cout << s1.length() << endl;

    Point p1 = {1,1};
    p1.shift(2,2);
    cout << p1.x << " " << p1.y << endl;

    Point p2(2);
    cout << p2.x << " " << p2.y << endl;

    return 0;
}