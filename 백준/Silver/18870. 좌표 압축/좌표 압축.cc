#include<bits/stdc++.h>
using namespace std;
int N;
vector<int> v;
set<int> s;
int ar[1000001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> ar[i];
		if (s.find(ar[i]) == s.end()) {
			v.push_back(ar[i]);
			s.insert(ar[i]);
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		int l = 0, h = v.size() - 1, tar = ar[i];
		int m = (l + h) / 2;
		while (1) {
			m = (l + h) / 2;
			if (v[m] > tar) 
				h=m-1;
			else if (v[m]< tar) 
				l=m+1;
			else { //
				cout << m << " ";
				break;
			}
		}
	}
}