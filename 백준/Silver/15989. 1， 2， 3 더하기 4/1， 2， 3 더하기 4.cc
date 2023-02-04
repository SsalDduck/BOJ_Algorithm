#include<bits/stdc++.h>
using namespace std;
int dp[10001];
int main() {
	dp[0] = 1;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j < 10001; j++) {
			if (j >= i)
				dp[j] += dp[j - i];
		}
	}
	int T, in;
	cin >> T;
	while (T--)
		cin >> in, cout << dp[in] << "\n";
}