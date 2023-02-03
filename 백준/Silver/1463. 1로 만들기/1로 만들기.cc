#include<bits/stdc++.h>
using namespace std;
int N;
int vi[1000001];
int pre[1000001];
int rt;
void BFS(int h) {
	vi[h] = 1;
	queue<int> q; q.push(h); int next = 0;
	while (q.size() && h != 1) {
		
		h=q.front(); q.pop();
		if (h % 3 == 0 &&vi[h/3]==0) {
			next = h / 3; vi[next] = 1;
			q.push(next);
			pre[next] = h;
		}
		if (h % 2 == 0 && vi[h / 2] == 0) {
			next = h / 2; vi[next] = 1;
			q.push(next);
			pre[next] = h;
		}
		if (vi[h - 1] == 0) {
			next = h - 1; vi[next] = 1;
			q.push(next);
			pre[next] = h;
		}
	}
		while (pre[h] != 0) {
			rt++;
			h = pre[h];
		}
	cout << rt;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	BFS(N);

}