#include <bits/stdc++.h>
using namespace std;
bitset<10000000> b;

void sieve(int N) {
	b.set();
	b[0] = b[1] = 0;
	for(int i = 2; i <= N; ++i)
		if(b[i])
			for(int j = i * i; j <= N; j += i)
				b[j] = 0;
}

vector<int> generate_primes(int N) {
	sieve(N);
	vector<int> primes;
	for(int i = 2; i <= N; ++i)
		if(b[i]) primes.push_back(i);
	return primes;
}

vector<int> prime_factorize(int N) {
    vector<int> primes = generate_primes(ceil(sqrt(N)));
    vector<int> pfs;
    for(int i = 0 ; i < primes.size(); ++i)
        while(N % primes[i] == 0) {
            N /= primes[i];
            pfs.push_back(primes[i]);
        }

    if(N != 1)
        pfs.push_back(N);
    return pfs;
}

int main() {
    int N;
    cin >> N;
    vector<int> pfs = prime_factorize(N);
    for(int i = 0; i < pfs.size(); ++i)
        cout << pfs[i] << " ";
    cout << endl;
    
	return 0;
}