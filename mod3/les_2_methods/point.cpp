#include "point.h"

void Point::shift(double x, double y) {
    this->x += x;
    this->y += y;
}

// Список инициализации
Point::Point(double x, double y) : x(x), y(y)
{}
