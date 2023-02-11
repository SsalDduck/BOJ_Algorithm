#include<bits/stdc++.h>
using namespace std;
int N, C;
vector<int> v;
bool ans;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> C;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i]; if (v[i] == C) ans = 1;
	}
	stable_sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (binary_search(v.begin() + i + 1, v.end(), C - v[i] - v[j])) 
				ans = 1;
			if (v[i] + v[j] == C)
				ans = 1;
		}
	}
	cout << ans;
}