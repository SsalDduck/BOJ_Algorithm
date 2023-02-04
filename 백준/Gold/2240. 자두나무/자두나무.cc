#include<bits/stdc++.h>
using namespace std;
int T, W;
int dp[1004][32][3]; //
int v[1004];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T >> W;
	int pos = 1;
	
	for (int i = 1; i <= T; i++)
		cin >> v[i];

	for (int i = 1; i <= T; i++) {
		dp[i][0][1] = dp[i - 1][0][1] + (v[i] == 1 ? 1 : 0); // 아예 이동 없음
		for (int j = 1; j <= W; j++) { // 이동함d
			if (i < j) // 지금 3번째 사과가 떨어지는데 10번 이동한거는 말이 안됨.
				break;
			if (v[i] == 1) {
				dp[i][j][1] = max(dp[i - 1][j - 1][2], dp[i - 1][j][1])+1;
				dp[i][j][2] = max(dp[i - 1][j - 1][1], dp[i - 1][j][2]);
			}
			else {
				dp[i][j][1] = max(dp[i - 1][j - 1][2], dp[i - 1][j][1]);
				dp[i][j][2] = max(dp[i - 1][j - 1][1], dp[i - 1][j][2])+1;
			}

		}
	}
	int ans = 0;
	for (int j = 0; j <= W; j++)
		ans = max({ ans, dp[T][j][1], dp[T][j][2] });
	cout << ans;

}