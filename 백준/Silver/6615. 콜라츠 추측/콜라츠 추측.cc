#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
map < ll, ll > vi;

ll cal(ll a) {
	if (a % 2)
		return 3 * a + 1;
	return a / 2;
}
int main() {

	long long a, b;
	int num1, num2;

	while (1) {
		scanf("%lld %lld", &a, &b);

		if (a == 0 && b == 0) 
			break;

		num1 = a; num2 = b;

		bool flag = 1;
		int a_cnt = 0, b_cnt = 0;

		while (a != 1) {
			vi[a] = ++a_cnt;
			a = cal(a);
		}
		vi.insert(make_pair(1, ++a_cnt));

		while (b != 1) {
			++b_cnt;
			if (vi[b] != 0) {
				
				flag = false;
				break;
			}
			b = cal(b);
		}
		if (flag) 
			printf("%d needs %d steps, %d needs %d steps, they meet at %d\n", num1, vi[1] - 1, num2, b_cnt, 1);
		else
			printf("%d needs %d steps, %d needs %d steps, they meet at %lld\n", num1, vi[b] - 1, num2, b_cnt - 1, b);
		vi.clear();
	}

}


