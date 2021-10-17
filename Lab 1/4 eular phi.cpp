#include <bits/stdc++.h>
using namespace std;

int phi(int n) {
    int r = n;
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0){
                n = n / i;
            }
            r = r - (r / i);
        }
    }
    if (n > 1)
        r = r - (r / n);
    return r;
}


int main(){
    int n;
    cin>>n;

    cout<<phi(n)<<endl;



}
