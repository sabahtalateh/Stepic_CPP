//
// Created by ak-4xxi on 01/02/2017.
//

#include "IntArray.h"

IntArray::IntArray(size_t size)
        : size_(size), data_(new int[size]) {
    for (size_t i = 0; i != size; i++) {
        data_[i] = 0;
    }
}

IntArray::IntArray(IntArray const &a)
    : size_ (a.size_), data_ (new int [a.size_]){

}


