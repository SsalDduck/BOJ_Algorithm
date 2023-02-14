#include<bits/stdc++.h>
using namespace std;
double W, L, D;
double dp[21][3001];
double b, s, g, p, d;
int main() {
    cin >> W >> L >> D;
    dp[0][2000] = 1;
    for (int i = 0; i < 20; i++) {
        for (int j = 1000; j <= 3000; j += 50) {
            if (dp[i][j]) {
                dp[i + 1][j + 50] += dp[i][j] * W;
                dp[i + 1][j - 50] += dp[i][j] * L;
                dp[i + 1][j] += dp[i][j] * D;
            }
        }
    }

    for (int i = 1000; i < 1500; i += 50)
        b += dp[20][i];
    for (int i = 1500; i < 2000; i += 50)
        s += dp[20][i];
    for (int i = 2000; i < 2500; i += 50)
        g += dp[20][i];
    for (int i = 2500; i < 3000; i += 50)
        p += dp[20][i];
    d += dp[20][3000];

    printf("%.8lf\n", b);
    printf("%.8lf\n", s);
    printf("%.8lf\n", g);
    printf("%.8lf\n", p);
    printf("%.8lf\n", d);
}