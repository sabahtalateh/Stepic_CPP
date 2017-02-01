//
// Created by ak-4xxi on 01/02/2017.
//

#ifndef LESS7_COPY_CONSTRUCTORS_INTARRAY_H
#define LESS7_COPY_CONSTRUCTORS_INTARRAY_H


#include <cstddef>

struct IntArray {
    IntArray(size_t size);

    IntArray(IntArray const &a);

    IntArray &operator=(IntArray const &a);

    ~IntArray();

    void swap(IntArray &a);

    size_t size () const;

    int get(size_t i) const;

    int &get(size_t i);

    void resize(size_t n_size);

private:
    size_t size_;
    int *data_;
};


#endif //LESS7_COPY_CONSTRUCTORS_INTARRAY_H
