#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,less<int>>pq;
string s;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	for (char c : s) 
		pq.push(c - '0');
	while (pq.size()) {
		cout << pq.top();
		pq.pop();
	}
}