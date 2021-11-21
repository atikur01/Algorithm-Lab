#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > set_cover(int *S, int k, int n) {
    int i = 0;
    vector<pair<int, int> > B;
    while(i < n) {
        pair<int, int> p;
        p.first = S[i];
        p.second = p.first + k;
        B.push_back(p);
        ++i;
        while(i < n && S[i] <= p.second) ++i;
    }
    return B;
}

int main() {
    int S[] = {5, 9, 12, 15, 16, 21, 26};
    int k = 6;
    int n = sizeof(S) / sizeof(S[0]);
    vector<pair<int, int> > B = set_cover(S, k, n);
    for(int i = 0; i < B.size(); ++i)
        printf("[%d, %d]\n", B[i].first, B[i].second);

    return 0;
}
