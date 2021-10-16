#include <bits/stdc++.h>
using namespace std;

int main() {
	char chs[] = {'a', 'a', 'c', 'e', 'b', 'c', 'b'};
	map<char, int> freq;
	int n = sizeof(chs) / sizeof(chs[0]);

	for(int i = 0; i < n; ++i)
		if(freq.find(chs[i]) == freq.end())
			freq[chs[i]] = 1;
		else freq[chs[i]] += 1;

	map<char, int> :: iterator it, m = freq.end();
	for(it = freq.begin(); it != m; ++it) {
		int f = it->second;
		printf("%c => ", it->first);
		for(int i = 1; i <= f; ++i)
			printf(" *");
		cout << endl;
	}

	return 0;
}