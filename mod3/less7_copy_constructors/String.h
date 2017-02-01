//
// Created by ak-4xxi on 01/02/2017.
//

#ifndef LESS7_COPY_CONSTRUCTORS_STRING_H
#define LESS7_COPY_CONSTRUCTORS_STRING_H

#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {
    String(const char *str = "");
    String(size_t n, char c);
    ~String();

    String(const String &other);

    String &operator=(const String &other);

    void append(const String &other);

    size_t size;
    char *str;
};


#endif //LESS7_COPY_CONSTRUCTORS_STRING_H
