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

struct Expression {
    virtual double evaluate() const = 0;

    virtual ~Expression() {};
};

struct Number : Expression {
    Number(double value)
            : value(value) {}

    ~Number() {
        delete &value;
    }

    double evaluate() const {
        return value;
    }

private:
    double value;
};

struct BinaryOperation : Expression {
    /*
      Здесь op это один из 4 символов: '+', '-', '*' или '/', соответствующих операциям,
      которые вам нужно реализовать.
     */
    BinaryOperation(Expression const *left, char op, Expression const *right)
            : left(left), op(op), right(right) {}

    ~BinaryOperation() {
        delete &left;
        delete &right;
        delete &op;
    }

    double evaluate() const {

        double result = 0;

        switch (op) {
            case '+':
                result = left->evaluate() + right->evaluate();
                break;
            case '-':
                result = left->evaluate() - right->evaluate();
                break;
            case '*':
                result = left->evaluate() * right->evaluate();
                break;
            default:
                result = left->evaluate() / right->evaluate();
                break;
        }

        return result;
    }

private:
    Expression const *left;
    Expression const *right;
    char op;
};

bool check_equals(Expression const *left, Expression const *right)
{
    return ((void(*(*(&)[2]))(const Expression&))left)[0][0] == ((void(*(*(&)[2]))(const Expression&))right)[0][0];

    char op_left = *(char*)(left+3);
    char op_right = *(char*)(right+3);

    cout << op_left << endl;
    cout << op_right << endl;
    cout << endl << endl;

    if (
            (op_left == '*' || op_left == '/' || op_left == '+' || op_left == '-') &&
            (op_right == '*' || op_right == '/' || op_right == '+' || op_right == '-')
    ) {
        return true;
    }

    if (op_left == op_right) {
        return true;
    }

    return false;
}

int main() {
    Number *n = new Number(2);

    Expression *sube = new BinaryOperation(new Number(138183712837198732.99898), '*', new Number(5));
    Expression *sube1 = new BinaryOperation(new Number(4.5), '-', new Number(5));

    Expression * expr = new BinaryOperation(sube, '+', new Number(3));

    cout << check_equals(expr, n) << endl;
//
//    cout << sube->evaluate();

//    String greet("Hello");
//    char ch1 = greet.at(0);
//
//    String const const_greet("Hello, Const!");
//    char const &ch2 = const_greet.at(0);
//
//
//    cout << sizeof(String) << endl;
//
//    String str1("Hello");
//    cout << str1.size << endl;
//    cout << str1.str << endl;
//
//    String str2(1, '_');
//    cout << str2.size << endl;
//    cout << str2.str << endl;
//
//    String str3(" World");
//
//
//    cout << "++++" << endl;
//    str1.append(str3);
//    cout << str1.size << endl;
//    cout << str1.str << endl;
//    cout << "++++" << endl;
//
//    Segment s1 = {{0.4, 1.8}, {2.2, 18.6}};
//    cout << s1.length() << endl;
//
//    Point p1 = {1,1};
//    p1.shift(2,2);
//    cout << p1.x << " " << p1.y << endl;
//
//    Point p2(2);
//    cout << p2.x << " " << p2.y << endl;

//    return 0;
}