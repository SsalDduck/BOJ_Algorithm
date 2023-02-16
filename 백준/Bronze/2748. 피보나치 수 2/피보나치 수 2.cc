#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
ull fib[92];
int main() {
	ull N;
	cin >> N;
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i <= N; i++) 
		fib[i] = fib[i - 1] + fib[i - 2];
	cout << fib[N];
}