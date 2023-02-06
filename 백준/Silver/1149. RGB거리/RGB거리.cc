#include<bits/stdc++.h>
using namespace std;
int N;
int dp[1001][3];
int main() {
	//memset(dp, INT_MAX, sizeof(dp));
	cin >> N;
	cin >> dp[0][0] >> dp[0][1] >> dp[0][2];
	for (int i = 1; i < N; i++) {
		cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
		for (int j = 0; j < 3; j++) {
			int tmp=INT_MAX;
			for (int k = 0; k < 3; k++) {
				if (k == j)
					continue;
				tmp = min(tmp, dp[i - 1][k]);
			}
			dp[i][j] += tmp;
		}
	}
	cout << min({ dp[N - 1][0], dp[N - 1][1], dp[N - 1][2] });
}