#include <iostream>

/* Этот код просто напоминание как выглядит класс Foo и функция foo_says.
 Не нужно его расскоментировать и/или менять. */
///*
#include <iostream>

struct Foo {
    void say() const { std::cout << "Foo says: " << msg << "\n"; }

protected:
    Foo(const char *msg) : msg(msg) {}

private:
    const char *msg;
};

void foo_says(const Foo &foo) { foo.say(); }



struct Bar : Foo {
    Bar(const char *msg) : Foo(msg) {

    }
};

Foo get_foo(const char *msg) {
    Bar bar(msg);
    Foo & foo = bar;
    return foo;
}

void foo(char) { std::cout << "char" << std::endl; }
void foo(signed char) { std::cout << "signed char" << std::endl; }
void foo(unsigned char) { std::cout << "unsigned char" << std::endl; }

//float  square(float value) { return value * value; }
//double square(float value) const { return (double)value * value; }

void promotion(char &) { std::cout << "char" << std::endl; }
void promotion(int  &) { std::cout << "int"  << std::endl; }
void promotion(long &) { std::cout << "long" << std::endl; }

struct Person {

    explicit Person(int age) {
        this->age = age;
    }

    virtual int get_age(){ return age; };
private:
    int age;
};

struct Student : Person {
    explicit Student(int age, int course) : Person(age) {
        this->course = course;
    }

    int get_age() { return Person::get_age() - 5; };
private:
    int course;
};

int main() {

    Student s(10,20);
    s.get_age();

    Person *p = &s;
    p->get_age();

//    short sh = 10;

//    Bar * bar = new Bar("123");
//    bar->say();

//    foo('a');

//    foo_says(get_foo("Hello!!"));

    return 0;
}