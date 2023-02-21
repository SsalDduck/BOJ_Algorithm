#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll T, N;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, less<pair<ll, ll> > > pq;
		ll in;
		vector<pair<ll, ll>> sold(N);
		//vector<pair<int,> sold(N, 0);
		for (ll i = 0; i < N; i++) {
			cin >> in;
			pq.push({ in,i });
			sold[i] = { in,0 };
		}

		ll idx = 0;
		ll ans = 0;
		while (pq.size()) {
			auto p = pq.top(); pq.pop();
			if (sold[p.second].second)
				continue;
			for (ll i = idx; i <= p.second; i++) {
				if (sold[i].second == 0) {
					ans += p.first - sold[i].first;
					sold[i].second = 1;
				}
			}
			idx = p.second + 1;
		}
		cout << ans << "\n";
	}
}