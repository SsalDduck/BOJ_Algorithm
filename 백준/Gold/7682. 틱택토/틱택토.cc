#include<bits/stdc++.h>
using namespace std;
string m;
bool iswin(char c) { //c가 ㅇ겼냐d
	for (int i = 0; i < 7; i = i + 3) {
		if (m[i] == c && m[i + 1] == c && c == m[i + 2])
			return 1;
	}
	for (int i = 0; i < 3; i++) {
		if (m[i] == c && m[i + 3] == c && m[i + 6] == c)
			return 1;
	}
	if (m[0] == c && m[4] == c && m[8] == c)
		return 1;
	if (m[2] == c && m[4] == c && m[6] == c)
		return 1;
	return 0;
}

int main() {
	while (1) {
		cin >> m;
		if (m == "end")
			break;
		int xcnt = 0;
		int ocnt = 0;
		for (int i = 0; i < 9; i++) {
			if (m[i] == 'X')
				xcnt++;
			else if (m[i] == 'O')
				ocnt++;
		}

		if (xcnt == ocnt + 1) {//x승d
			bool is_owin = iswin('O');
			bool is_xwin = iswin('X');
			if (is_owin)
				cout << "invalid\n";
			else if (is_xwin)
				cout << "valid\n";
			else if (xcnt == 5 && ocnt == 4) { //무승부인경우임d
				cout << "valid\n";
			}
			else
				cout << "invalid\n";
		}
		else if (ocnt == xcnt) {//o승
			bool is_owin = iswin('O');
			bool is_xwin = iswin('X');
			if (is_xwin)
				cout << "invalid\n";
			else if (is_owin)
				cout << "valid\n";
			else
				cout << "invalid\n";
		}
		else
			cout << "invalid\n";
	}
}