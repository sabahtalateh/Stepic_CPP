#include <iostream>
#include "foo.h"

using namespace std;

struct Rational {
    Rational(int numerator = 0, int denominator = 1) : numerator_(numerator), denominator_(denominator) {};

    void add(Rational rational) {
        numerator_ = numerator_ * rational.denominator_ + rational.numerator_ * denominator_;
        denominator_ *= rational.denominator_;
    }

    void sub(Rational rational) {
        numerator_ = numerator_ * rational.denominator_ - rational.numerator_ * denominator_;
        denominator_ *= rational.denominator_;
    }

    void mul(Rational rational) {
        numerator_ *= rational.numerator_;
        denominator_ *= rational.denominator_;
    }

    void div(Rational rational) {
        numerator_ *= rational.denominator_;
        denominator_ *= rational.numerator_;
    }

    void neg() {
        numerator_ = -numerator_;
    }

    void inv() {}

    double to_double() const {
        return numerator_ / (double) denominator_;
    }

    Rational &operator-() {
        numerator_ = -numerator_;
        return *this;
    }

    Rational &operator+=(const Rational &rational) {
        this->add(rational);
        return *this;
    }

    Rational &operator+=(int d) {
        this->add(Rational(d));
        return *this;
    }

    Rational &operator-=(const Rational &rational) {
        this->sub(rational);
        return *this;
    }

    Rational &operator-=(int d) {
        this->sub(Rational(d));
        return *this;
    }

    Rational &operator*=(const Rational &rational) {
        this->mul(rational);
        return *this;
    }

    Rational &operator*=(int d) {
        this->mul(Rational(d));
        return *this;
    }

    Rational &operator/=(const Rational &rational) {
        this->div(rational);
        return *this;
    }

    Rational &operator/=(int d) {
        this->div(Rational(d));
        return *this;
    }

    Rational operator-() const {
        Rational r(this->numerator_, this->denominator_);
        r.neg();
        return r;
    }

    Rational operator+() const {
        Rational r(this->numerator_, this->denominator_);
        return r;
    }

    int get_d() const {
        return denominator_;
    }

    int get_n() const {
        return numerator_;
    }

private:
    int numerator_;
    int denominator_;
};

bool operator==(Rational const &r1, Rational const &r2) {
    return (
            r1.get_n() == r2.get_n() &&
            r1.get_d() == r2.get_d()
    );
}

bool operator!=(Rational const &r1, Rational const &r2) {
    return r1 != r2;
}

bool operator<(Rational const &r1, Rational const &r2) {
    return (r1.get_n()/r1.get_d()) < (r2.get_n()/r2.get_d());
}

bool operator>(Rational const &r1, Rational const &r2) {
    return r2 < r1;
}

bool operator<=(Rational const &r1, Rational const &r2) {
    return !(r2 < r1);
}

bool operator>=(Rational const &r1, Rational const &r2) {
    return !(r1 < r2);
}



int main() {

    Rational r1(1, 2);
    Rational r2(1, 2);
//    r1 = +r1;
//    r1 = r1 / Rational(2, 2);
    cout << (r1 == r2) << endl;

    unsigned n1 = 8;
//    n1 = ~n1;
    n1 = n1 >> 1;

    bitset<5> b1 = (0000 ^ 1111);

    cout << bitset<8>(n1) << ' '; // direct output
    cout << b1 << ' '; // direct output

    return 0;
}