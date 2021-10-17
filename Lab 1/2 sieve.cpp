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

int main(){

    int n;
    cin>>n;
    int sum = 0;
    vector<int> arr = primesArr(n);

    for(int i = 0;i<arr.size();i++){
        sum+=arr[i];
    }

    cout<<"Sum: "<<sum;


}
