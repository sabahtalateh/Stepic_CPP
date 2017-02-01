#include <algorithm>

#include "String.h"

String::String(const String &other)
    : size(other.size), str(new char [other.size + 1]){
    strcpy(str, other.str);
}

String &String::operator=(const String &other)
{
    if (this != &other) {
        delete [] str;

        size = other.size;
        str = new char [other.size + 1];
        strcpy(str, other.str);
    }

    return *this;
}

String::String(const char *str) {
    size = strlen(str);
    char * ss = new char [size+1];
    strcpy(ss, str);
    this->str = ss;
}

String::String(size_t n, char c) {
    size = n;
    char * ss = new char [size+1];
    int i = 0;
    for (; i < size; i++) {
        *(ss + i) = c;
    }
    *(ss + i) = '\0';
    this->str = ss;
}

String::~String() {
    delete [] str;
}

void String::append(const String &other) {
    unsigned new_size = (unsigned int) (size + other.size);
    char * new_str = new char [new_size + 1];
    unsigned current_symbol_n = 0;

    for (int i = 0; i < this->size; i++) {
        *(new_str + current_symbol_n) = this->str[i];
        current_symbol_n++;
    }

    for (int i = 0; i < other.size; i++) {
        *(new_str + current_symbol_n) = other.str[i];
        current_symbol_n++;
    }

    new_str[current_symbol_n] = '\0';

    delete [] str;

    this->size = new_size;
    this->str = new_str;
}


