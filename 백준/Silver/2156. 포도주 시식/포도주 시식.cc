#include<bits/stdc++.h>
using namespace std;
int N;
int ar[10001], dp[10001][3];

int main(void) {
    ios::sync_with_stdio(0);  cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) 
        cin >> ar[i];
    dp[1][1] = ar[1];

    for (int i = 2; i <= N; i++) {
        dp[i][0] = max({ dp[i - 1][0], dp[i - 1][1], dp[i - 1][2] });
        dp[i][1] = dp[i - 1][0] + ar[i];
        dp[i][2] = dp[i - 1][1] + ar[i];
    }
    cout << max({ dp[N][0], dp[N][1], dp[N][2] });
}