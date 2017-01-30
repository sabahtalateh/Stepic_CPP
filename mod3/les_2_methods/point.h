#ifndef LES_2_METHODS_POINT_H
#define LES_2_METHODS_POINT_H

struct Point {
    double x;
    double y;

    void shift(double x, double y);

    Point(double x = 0, double y = 0);
};

#endif //LES_2_METHODS_POINT_H
