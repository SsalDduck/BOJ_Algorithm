#include<bits/stdc++.h>
using namespace std;
int N,ps;
int ar[100001];
int rt = INT_MIN;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> ar[i];
		ps += ar[i];
		rt = max(rt, ps);
		if (ps < 0)
			ps = 0;
	}
	cout << rt;
}