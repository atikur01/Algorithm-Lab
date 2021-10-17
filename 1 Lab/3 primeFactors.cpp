#include <bits/stdc++.h>
using namespace std;

bitset<10000000> bs;

void sieve(int n){
    bs.set();
    bs[0]=bs[1]=0;

    for(int i = 2;i<=n;++i){
        if(bs[i]){
            for(int j = i*i;j<=n;j=j+i){
                bs[j]=0;
            }
        }
    }
}

vector<int> primesArr(int n){
    sieve(n);
    vector<int> arr;
    for(int i=2;i<=n;i++){
        if(bs[i]==1){
            arr.push_back(i);
        }
    }
    return arr;
}

vector<int> primeFactors(int n){
    vector<int> primesarr = primesArr(ceil(sqrt(n)));
    vector<int> pf;

    for(int i = 0;i<primesarr.size();i++){
        int p = primesarr[i];

        while(n%p==0){
            n=n/p;
            pf.push_back(p);
        }
    }

    if(n!=1){
        pf.push_back(n);
    }
    return pf;
}

int main(){

    int n;
    cin>>n;

    vector<int> arr = primeFactors(n);

    cout<<"Prime factors:"<<endl;

    for(int i = 0;i<arr.size();i++){

        cout<<arr[i]<<endl;
    }

}
