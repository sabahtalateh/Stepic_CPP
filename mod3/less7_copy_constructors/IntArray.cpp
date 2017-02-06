#include <algorithm>
#include "IntArray.h"

IntArray::IntArray(size_t size)
        : size_(size), data_(new int[size]) {
    for (size_t i = 0; i != size; i++) {
        data_[i] = 0;
    }
}

IntArray::IntArray(IntArray const &a)
        : size_(a.size_), data_(new int[a.size_]) {
    for (size_t i = 0; i != size_; i++) {
        data_[i] = a.data_[i];
    }
}

IntArray &IntArray::operator=(const IntArray &a) {
    if (this != &a) {
//        IntArray *ttt = new IntArray(a);
//        ttt->swap(*this);
//        то же что
        IntArray(a).swap(*this);
    }

    return *this;
}


IntArray::~IntArray() {
    delete[] data_;
}

void IntArray::swap(IntArray &a) {
    std::swap(size_, a.size_);
    std::swap(data_, a.data_);
}

size_t IntArray::size() const {
    return size_;
}

int IntArray::get(size_t i) const {
    return data_[i];
}

int &IntArray::get(size_t i) {
    return data_[i];
}

void IntArray::resize(size_t nsize) {
    IntArray t(nsize);
    size_t n = nsize > size_ ? nsize : size_;
    for (size_t i = 0; i != n; ++i) {
        t.data_[i] = data_[i];
    }
    swap(t);
}
