#include<bits/stdc++.h>
using namespace std;
using ll= long long;
vector<string> v;
int main() {
	for (int i = 0; i <10; i++) 
		v.push_back(to_string(i));

	bool isdone = 0; //9876543210
	ll s_idx = 0;
	for (int len = 2; len <= 10; len++) {
		bool flag = 1;
		ll tmp;
		for (int f = 1; f <= 9; f++) { //맨 앞 자리수d
			for (ll i = s_idx; v[i][0] - '0' < f; i++) {
				string s = to_string(f).append(v[i]);
				v.push_back(s);
				if (flag) {
					tmp = v.size() - 1;
					flag = 0;
				}
			}
		}
		s_idx = tmp;
	}
	int N;
	cin >> N;
	if (N > v.size() - 1)
		cout << -1;
	else
	cout << v[N];
	
	
	
}