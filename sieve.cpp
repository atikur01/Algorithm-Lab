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

int main() {
	int N = 30;
	vector<int> primes = generate_primes(N);

	for(int i = 0; i < primes.size(); ++i)
		cout << primes[i] << endl;

	return 0;
}