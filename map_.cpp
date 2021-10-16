#include <bits/stdc++.h>
using namespace std;

int main() {
	map<string, int> kv_pair;
	string names[] = {"john", "jane", "oxford"};
	int ages[] = {24, 21, 500};

	for(int i = 0; i < 3; ++i)
		kv_pair[names[i]] = ages[i];

	//map<string, int> :: iterator n = kv_pair.end();
	string k = "janes";

	if(kv_pair.find(k) != kv_pair.end()) {
		cout << "erased" << endl;
		kv_pair.erase(k);
	}
	else cout << "key not found" << endl;

	if(kv_pair.find(k) == kv_pair.end())
		cout << "key not in the map" << endl;
	else cout << kv_pair[k] << endl;

	return 0;
}