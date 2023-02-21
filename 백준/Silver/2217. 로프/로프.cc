#include<bits/stdc++.h>
using namespace std;
int N;

int main() {
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	stable_sort(v.begin(), v.end(), greater<int>());
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans = max(ans,v[i] * (i + 1));
	}
	cout << ans;
}
	