#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x;
    double y;
};

struct Segment {
    Point p1;
    Point p2;
};

double length(Segment s) {
    // . - доступ по значению
    double dx = s.p1.x - s.p2.x;
    double dy = s.p1.y - s.p2.y;

    return sqrt(dx * dx + dy * dy);
}

double length (Segment * s) {
    // -> - доступ по указателю
    double dx = s->p1.x - s->p2.x;
    double dy = s->p1.y - s->p2.y;

    return sqrt(dx * dx + dy * dy);
}

int main() {

    Point p1 = {2,2};
    Point p2 = {5,10};
    Segment s1 = {p1, p2};

    cout << length(s1) << endl;
    cout << length(&s1) << endl;

    return 0;
}