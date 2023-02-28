#include<bits/stdc++.h>
using namespace std;
int N,H;
vector<int> v[2]; //0 이 밑임
vector<int>a(500001,0);
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> H;
	int in;
	for (int i = 0; i < N; i++) {
		cin >> in; 
		v[i % 2].push_back(in);
	}
	sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());
	int ans = INT_MAX,ans2=0;
	for (int h = 1; h <= H; h++) {
		a[h] += v[0].size() - (lower_bound(v[0].begin(), v[0].end(),h)-v[0].begin());
		a[h] += v[1].end() - upper_bound(v[1].begin(), v[1].end(),H-h);
		if (a[h] < ans) {
			ans2 = 1;
			ans = a[h];
		}
		else if (ans == a[h])
			ans2++;
		
	}
	//cout<<*min_element(a.begin()+1, a.begin()+H); //a[1] to a[H]까지
	cout << ans << " " << ans2;
}