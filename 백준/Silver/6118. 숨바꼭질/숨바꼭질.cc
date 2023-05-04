#include<bits/stdc++.h>
using namespace std;
vector<int> adj[20001];
int vi[20001];
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };

int ans[3];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vi[1] = 1;
    queue<int> q;
    q.push(1);
    while (q.size()) {
        int here = q.front(); q.pop();
        for (int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i];
            if (vi[there])
                continue;
            vi[there] = vi[here] + 1;
            q.push(there);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (vi[i] - 1 > ans[1]) {
            ans[1] = vi[i] - 1;
            ans[2] = 1;
            ans[0] = i;
        }
        else if (vi[i]-1 == ans[1]) {
            ans[2]++;
        }
    }

    for (int a : ans)
        cout << a << " ";

}