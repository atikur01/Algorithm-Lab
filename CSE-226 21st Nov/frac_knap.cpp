#include <bits/stdc++.h>
using namespace std;

struct commercial {
    float time, value;
    float ratio, taken;

    commercial(float time, float value) {
        this->time = time;
        this->value = value;
        ratio = value / time;
        taken = 0;
    }
};

bool comp(commercial a, commercial b) {
    return a.ratio > b.ratio;
}

float compute_opt_val(commercial *commercials, int n, float T) {
    sort(commercials, commercials + n, comp);
    float v = 0;
    for(int i = 0; i < n; ++i) {
        if(T == 0)
            return v;
        float a = min(commercials[i].time, T);
        v += a * commercials[i].ratio;
        commercials[i].taken = a;
        T -= a;
    }
    return v;
}

int main() {
    int n = 3;
    commercial commercials[] = {commercial(4, 20), commercial(3, 18), commercial(2, 14)};
    int T = 7;
    float opt = compute_opt_val(commercials, n, T);
    cout << opt << endl;
    cout << "optimal solution" << endl;
    for(int i = 0; i < n; ++i)
        cout << "v: " << commercials[i].value << " t: " << commercials[i].time << " taken: " << commercials[i].taken << endl;

    return 0;
}
