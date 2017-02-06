#include <iostream>
#include <string>

using namespace std;

struct Person {
    Person(string const &name, int age)
            : name_(name), age_(age) {};

    virtual ~Person() {};

    virtual string name() const {
        return name_;
    }

    virtual string occupation() const = 0;

private:
    string name_;
    int age_;
};

struct Teacher : Person {
    Teacher(const string &nm, int age, string const &course)
            : Person(nm, age), course_(course) {
        cout << name() << endl;
    }

    virtual string occupation() const {
        return "teacher";
    }

    virtual string course() {
        return course_;
    }

private:
    string course_;
};

struct Professor : Teacher {
    Professor(const string &nm, int age, const string &course, const string &thesis)
            : Teacher(nm, age, course), thesis_(thesis) {}

    virtual string name() const {
        return "Prof. " + Person::name();
    }

    virtual string occupation() const {
        return "professor";
    }

    virtual string thesis() const {
        return thesis_;
    }

private:
    string thesis_;
};


int main() {

    Professor *stroustrup = new Professor("Stroustrup", 63, "C++", "The C++ Language");

    return 0;
}