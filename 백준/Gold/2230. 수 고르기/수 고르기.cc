#include<bits/stdc++.h>
using namespace std;
int N, tar;
vector<int> v;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> tar;
    v.resize(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int e = 0, b = 0;
    int ans = INT_MAX;
    while (e < N && b<N) {
        if (v[e] - v[b] < tar)
            e++;
        else if (v[e] - v[b] >= tar) {
            ans = min(ans, v[e] - v[b]);
            b++;
        }
    }
    cout << ans;
}