#include<bits/stdc++.h>
using namespace std;
const int dy[] = { 1,0,-1,0 };
const int dx[] = { 0,1,0,-1 };
char _map[1501][1501];
bool vi_s[1501][1501];
bool vi_w[1501][1501];
int C, R,swanX,swanY,day; string s; 
queue<pair<int, int>> wq, wq_t, sq, sq_t;
bool isfound = false;

void movesw() {
    int x, y;
    while (sq.empty() == false) {
        tie(y, x) = sq.front(); sq.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= C || nx >= R||vi_s[ny][nx]==1)
                continue;
            if (_map[ny][nx] == 'X'){ vi_s[ny][nx] = 1; sq_t.push({ ny,nx }); }
                
            else if (_map[ny][nx] == 'L') { vi_s[ny][nx] = 1; isfound = 1; return; }
                
            else if (_map[ny][nx] == '.') { vi_s[ny][nx] = 1; sq.push({ ny,nx }); }
        }
    }
}
void crack() {
    int x, y;
    while (wq.empty() == false) {
        tie(y, x) = wq.front(); wq.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= C || nx >= R || vi_w[ny][nx] == 1)
                continue;
            if (_map[ny][nx] == 'X') {
                _map[ny][nx] = '.';
                wq_t.push({ ny,nx });
                vi_w[ny][nx] = 1;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> C >> R;
    for (int i = 0; i < C; i++) {
        cin >> s;
        for (int j = 0; j < R; j++) {
            _map[i][j] = s[j];
            if (_map[i][j] == 'L') { swanY = i; swanX = j; }
            if (_map[i][j] == '.' || _map[i][j] == 'L') { vi_w[i][j] = 1; wq.push({ i, j }); }
        }
    }
    sq.push({ swanY,swanX }); vi_s[swanY][swanX] = 1;
    while (1) {
        movesw();
        if (isfound == true) break;
        crack();
        wq = wq_t; while (wq_t.empty() == false) wq_t.pop();
        sq = sq_t; while (sq_t.empty() == false) sq_t.pop();
        day++;
    }
    cout << day;
}