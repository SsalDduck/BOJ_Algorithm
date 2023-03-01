#include<bits/stdc++.h>
using namespace std;
vector<int> a(1000001, 1);
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int M = 1000001;
	for (int i = 2; i*i< 1000001; i++) {
		if (a[i]) 
			for (int j = i * i; j < 1000001; j = j + i)
				a[j] = 0;
	}

	int in;
	while (1) {
		cin >> in;
		if (in == 0)
			return 0;
		bool flag = 1;
		for (int i = 3; i < in; i += 2) {
			if (a[i] && a[in - i]) {
				cout << in << " = " << i << " + " << in - i << "\n";
				flag = 0;
				break;
			}
		}
		if (flag)
			cout << "Goldbach's conjecture is wrong.\n";
	}
}