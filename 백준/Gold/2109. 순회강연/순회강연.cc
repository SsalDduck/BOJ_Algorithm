#include<bits/stdc++.h>
using namespace std;
int N; //0 ≤ n ≤ 10,000)
vector< pair<int, int>> v;
int main() {
	cin >> N;
	int p, d;
	int Md = -987654321;
	for (int i = 0; i < N; i++) {
		cin >> p >> d;
		v.push_back({ p,d }); // f 가 돈이고 se 가 날짜임d
		Md = max(Md, d);
	}
	sort(v.begin(), v.end(), [](auto a, auto b) { // 반례를 찾는 순간 우디르급 태세전환
		if (a.second == b.second)
			return a.first > b.first;
		return a.second < b.second;
		}
	);
	priority_queue<int, vector<int>, greater<int> > pq; //p 를 넣을 pq;
	int j=0;
	for (int i = 1; i <= Md; i++) { // i일차면 i 일차 까지의 넣은 것중 위에서 i개만 살려놓음d
		while (j < N && v[j].second == i) {
			pq.push(v[j++].first);
		}
		while ( pq.size() > i) { //pq 안에는 i일차 만큼의 강의가 있어야함
			pq.pop();
		}
	}
	long long rt = 0;
	while (pq.size()) {
		rt += pq.top();
		pq.pop();
	}
	cout << rt;
}