#include<bits/stdc++.h>
using namespace std;
int N, M;
int dp[100001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	int in;
	dp[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> in;
		dp[i] = dp[i - 1] + in;
	}
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cout << dp[b] - dp[a-1] << "\n";
	}
}