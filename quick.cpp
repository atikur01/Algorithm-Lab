#include <bits/stdc++.h>
using namespace std;

int partition(int *A, int p, int r) {
    int x = A[r];
    int i = p - 1;
    for(int j = p; j <= r - 1; ++j)
        if(A[j] < x) {
            ++i;
            swap(A[i], A[j]);
        }
    swap(A[i+1], A[r]);
    return i + 1;
}

void quick_sort(int *A, int p, int r) {
    if(p < r) {
        int q = partition(A, p, r);
        quick_sort(A, p, q-1);
        quick_sort(A, q+1, r);
    }
}

int main() {
    int ara[] = {6, 4, 1, 2, 8, 9, 10};
    int n = sizeof(ara) / sizeof(ara[0]);
    quick_sort(ara, 0, n-1);
    for(int i = 0; i < n; ++i) cout << ara[i] << " ";
    cout << endl;

    return 0;
}