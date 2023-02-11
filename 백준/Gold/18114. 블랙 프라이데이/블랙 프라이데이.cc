#include<bits/stdc++.h>
using namespace std;
int N, C;
int ar[5001];
vector<int> ps;
vector<int> dp[5001];
bool ans;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> ar[i]; if (ar[i] == C) ans = 1;
	}
	sort(ar, ar + N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			dp[i].push_back(ar[i] + ar[j]);
			if (ar[i] + ar[j] == C)
				ans = 1;
		}
		//sort(dp[i].begin(), dp[i].end());
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <i; j++) {
			if(binary_search(dp[j].begin(), dp[j].end(), C - ar[i]))ans=1;
		}
	}
	cout << ans;
}