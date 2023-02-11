#include<bits/stdc++.h>
using namespace std;
int N, S,cnt;
vector<int> v;
bool used[20]; // 0 idx to 19idx
void go(int lev,int s,int las) {
	if (s == S && lev!=0) {
		cnt++;
	}
	for (int i = las+1; i < N; i++) {
		
		if (!used[i]) {
			s += v[i]; used[i] = 1;
			go(lev+1,s,i);
			s -= v[i]; used[i] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >>S;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	go(0,0,-1);
	cout << cnt;
}