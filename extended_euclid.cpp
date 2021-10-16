#include <bits/stdc++.h>
using namespace std;

struct tuple_ {
    int x, y, d;
    
    tuple_(int x, int y, int d) {
        this->x = x;
        this->y = y;
        this->d = d;
    }

    void print() {
        printf("x = %d y = %d d = %d\n", x, y, d);
    }

    tuple_() {}
};

tuple_ extended_euclid(int a, int b) {
    if(b == 0)
        return tuple_(1, 0, a);
    tuple_ initial = extended_euclid(b, a % b);
    return tuple_(initial.y, initial.x - (a / b) * initial.y, initial.d);
}

int main() {
    int a = 99, b = 78;
    (extended_euclid(a, b)).print();

    return 0;
}