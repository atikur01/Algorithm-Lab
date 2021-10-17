#include<iostream>
using namespace std;

bool isPrime(int n){
 for(int i = 2;i*i<=n;++i){
        if(n%2==0){
            return false;
        }
    }
    return true;
}

int main(){

    int n;
    cin>>n;

    int sum = 0;

    for(int i = 2;i<=n;i++){
        if(isPrime(i)){
            sum+=i;
        }
    }

    cout<<sum;

}
