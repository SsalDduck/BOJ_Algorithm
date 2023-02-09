#include<bits/stdc++.h>
using namespace std;
int N;
vector<int> v;
int S;
void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
	return;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	cin >> S;
	for (int i = 0; i < N; i++) {// i는 이번 차례에 바꿔져야할 자리
		
		int tar = v[i];
		int tar_id = i;
		for (int j = i+1; j < N; j++) {
			if (v[j] > tar && j - i  <= S) {
				tar = v[j];
				tar_id = j;
			}
		}
		for (int k = tar_id; k > i; k--) {
			swap(v[k], v[k - 1]);
			S--;
		}
		if (S <= 0)
			break;
		
	}

	for (int a : v)
		cout << a << " ";
}

//int idx = max_element(v.begin() + i, v.end()) - v.begin();
//if (idx - i > S)
//continue;
////S -= idx - i;
//for (int j = idx; j >= i; j--) {
//	swap(v[j], v[j - 1]);
//	S--;
//}