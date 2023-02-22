#include<bits/stdc++.h>
using namespace std;
string in;
int z;
int main() {
	cin >> in;
	char b = in[0];
	string s; s.push_back(b);
	for (int i = 1; i < in.size(); i++) {
		if (in[i] != b) {
			s.push_back(in[i]);
			b = in[i];
		}
	}
	for (char c : s) {
		if (c == '0')
			z++;
	}
	cout << min(z, (int)s.length() - z);
}