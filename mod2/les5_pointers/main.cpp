#include <iostream>
#include <algorithm>

using namespace std;

unsigned gcd(unsigned a, unsigned b) {
    if (b == 0)
        return a;

    unsigned rest = a % b;

    return gcd(b, rest);
}

int foo(int n) {
    std::cout << "Call" << std::endl;
    if (n <= 0)
        return 1;
    return foo((n * 2) / 3) + foo(n - 2);
}

//                 foo (3)
//                    |
//       foo(2)       +       foo(1)
//         |                    |
//   foo(1)  + foo(0)    foo(0) + foo(-1)
//       |                  1   +   1
// foo(0) + foo(-1)
//   1    +    1

void fff(int n) {
    cin >> n;

    if (n == 0)
        return;

    fff(n);
    cout << n << " ";

}

void swap(int *a, int *b) {
    int t = *a;
    cout << t;
    *a = *b;
    *b = t;
}

int max_elem(int *m, int size) {
    int max = *m;

    for (int i = 0; i < size; i++) {
        if (m[i] > max) {
            max = m[i];
        }
    }

    return max;
}

void rotate(int a[], unsigned size, int shift)
{
    if (size > 1 && shift != 0) {
        int realShift = shift % size;
        int *maxShift = a + size - 1;

        for (int i = 0; i < size; ++i) {
            int *newShift;
            newShift = a + i + realShift;

            if (newShift > maxShift) {
                newShift -= *maxShift;
            }

            int t = *(a + i);
            *(a + i) = *newShift;
            *newShift = t;
        }
    }
}

unsigned strlen1(const char *str)
{
    unsigned count = 0;

    for (; *str != 0; ++str){
        count++;
    }

    return count;
}

void strcat1(char *to, const char *from)
{
    int toLen = (int) strlen(to);

    int count = 0;

    for (; *from != 0; ++from) {
        *(to + toLen + count) = *from;
        count++;
    }
    *(to + toLen + count) = (char) '\0';
}

bool startsWith(const char *text, const char *start) {

    if (strlen(text) < strlen(start)) {
        return false;
    }

    bool answer = true;

    for (int i = 0; i < strlen(start); i++) {
        if (text[i] != start[i]) {
            answer = false;
            break;
        }
    }

    return answer;
}

int strstr1(const char *text, const char *pattern)
{
    if (strlen(pattern) == 0) {
        return 0;
    }

    bool contains = false;
    int position = 0;

    for (; *text != 0; text++) {

        if (startsWith(text, pattern)) {
            return position;
        }

        position++;
    }

    return -1;
}

int * foo() {
    int a = 500;
    return &a;
}

int & bar() {
    int b = 20;
    return b;
}

int main() {

    int a = 10, b = 20;
    int m[10] = {1,2,3,4,5,6,7,8,9,10};

    int & l1 = a;
    int * p = &a;

    int & l2 = *(m + a / 2);


    cout << a << endl << &l1 << " " << l1 << endl << p << " " << *p << endl;
    cout << &l2 << endl;

    int * f = foo();
    int & l = bar();
    cout << *f << " " << &l;

    return 0;
}




