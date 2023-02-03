#include<bits/stdc++.h>
using namespace std;
int L, C;	vector<char> v;
void go(int h, vector<char> c) {
	if (c.size() == L) {
		int a = 0, b = 0;
		for (char ch : c) {
			if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
				a++;
			else
				b++;
		}
		if (a == 0 || b < 2)
			return;
		for (char ch : c)
			cout << ch;
		cout << "\n";
		return;
	}
	for (int i = h; i < C; i++) {
		c.push_back(v[i]);
		go(i+1, c);
		c.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> L >> C;
	v.resize(C);
	for (int i = 0; i < C; i++) 
		cin >> v[i];
	vector<char> c;
	sort(v.begin(), v.end());
	go(0, c);
}