#include<bits/stdc++.h>
using namespace std;
int N;
vector<pair<int, int>> v;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int s, d;
		cin >> s >> d;
		v.push_back({ s,d });
	}
	sort(v.begin(), v.end(), [](auto a,auto b) {
		if (a.second > b.second) 
			return 1; // 앞에놈이 크도록 정렬d
		return 0;
		});
	
	int ti = INT_MAX;
	for (int i = 0; i < N; i++) 
		ti = min(ti - v[i].first, v[i].second - v[i].first);
	if (ti < 0)
		cout << -1;
	else
		cout << ti;
}