#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll N;
ll dp[91];
int main() {
	cin >> N;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;
	for (int i = 4; i <= N; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	cout << dp[N];
}