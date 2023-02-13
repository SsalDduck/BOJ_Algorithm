#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
ull N, P, Q;
map<ull,ull> s;
ull go(ull n) {
	if (n == 0)
		return 1;
	if (n == 1)
		return 2;
	if (!s[n])
		s[n] = go(n / P) + go(n / Q);
	return s[n];
}
int main() {
	cin >> N >> P >> Q;
	s.insert({ 0,1 });
	s.insert({ 1,2 });
	cout<< go(N);
}