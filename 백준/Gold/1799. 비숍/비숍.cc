#include<bits/stdc++.h>
using namespace std;
int N;
bool m[11][11];
vector<pair<int, int>> vi;
vector<pair<int, int>> ab[2];
int ans[2];
void go(int id, int cnt, int L) {
	if (id == ab[L].size()) {
		ans[L] = max(ans[L], cnt); return;
	}
	bool flag = 1;
	for (auto p : vi) {
		if (abs(ab[L][id].first - p.first) == abs(ab[L][id].second - p.second)) {
			flag = 0; break;
		}
	}
	go(id + 1, cnt,L);//안두는경우
	if(flag){
		vi.push_back(ab[L][id]);
		go(id + 1, cnt + 1,L); //진짜로 두는경우
		vi.pop_back();
	}

}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> m[i][j];
			if (m[i][j]) {
				if (i % 2 == j % 2)
					ab[0].emplace_back(i, j);
				else
					ab[1].emplace_back(i, j);
			}
		}
	}
	go(0, 0, 0);
	vector<pair<int, int>>emp;
	vi.swap(emp);
	go(0, 0, 1);
	cout << ans[0] + ans[1];
}