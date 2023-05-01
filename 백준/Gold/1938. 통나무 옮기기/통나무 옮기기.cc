#include <iostream>
#include <queue>
using namespace std;

// 상하좌우 탐색을 위함
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

int board[51][51];
int visit[51][51][2];
int n, bd, ed, bs = -1, be = -1, es = -1, ee = -1;

struct tree {
	int r, c, d;
};

int BFS() {
	queue<tree> q;

	q.push({ bs,be,bd });
	visit[bs][be][bd] = 1;

	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		int d = q.front().d;
		q.pop();

		if (r == es && c == ee && d == ed) return visit[r][c][d] - 1;

		for (int i = 0; i < 4; i++) {
			int rr = r + dr[i];
			int cc = c + dc[i];

			if (rr < 0 || cc < 0 || rr >= n || cc >= n) continue;
			if (visit[rr][cc][d]) continue;
			if (board[rr][cc]) continue;

			if (i == 0 && d == 0) {
				if (rr - 1 < 0) continue;
				if (board[rr - 1][cc]) continue;
			}
			else if (i == 1 && d == 1) {
				if (cc + 1 >= n) continue;
				if (board[rr][cc + 1]) continue;
			}
			else if (i == 2 && d == 0) {
				if (rr + 1 >= n) continue;
				if (board[rr + 1][cc]) continue;
			}
			else if (i == 3 && d == 1) {
				if (cc - 1 < 0) continue;
				if (board[rr][cc - 1]) continue;
			}

			if (i % 2 == 0 && d == 1) {
				if (cc - 1 < 0 || cc + 1 >= n) continue;
				if (board[rr][cc - 1]) continue;
				if (board[rr][cc + 1]) continue;
			}
			else if ((i % 2) && d == 0) {
				if (rr - 1 < 0 || rr + 1 >= n) continue;
				if (board[rr - 1][cc]) continue;
				if (board[rr + 1][cc]) continue;
			}

			q.push({ rr, cc, d });

			visit[rr][cc][d] = visit[r][c][d] + 1;
		}

		if (r - 1 < 0 || c - 1 < 0 || r + 1 >= n || c + 1 >= n) continue;
		if (visit[r][c][d] && visit[r][c][abs(d - 1)]) continue;
		if (board[r - 1][c - 1]) continue;
		if (board[r + 1][c - 1]) continue;
		if (board[r - 1][c + 1]) continue;
		if (board[r + 1][c + 1]) continue;

		if (board[r - 1][c]) continue;
		if (board[r + 1][c]) continue;
		if (board[r][c - 1]) continue;
		if (board[r][c + 1]) continue;
		d = d ? 0 : 1;

		q.push({ r,c,d });

		visit[r][c][d] = visit[r][c][abs(d - 1)] + 1;
	}
	return 0;
}

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;	cin >> s;
		for (int j = 0; j < n; j++) {
			if (bs == -1 && s[j] == 'B') {
				if (j != n - 1 && s[j + 1] == 'B') {
					bs = i; be = j + 1; bd = 1;
				}
				else { bs = i + 1; be = j; }
			}

			if (es == -1 && s[j] == 'E') {
				if (j != n - 1 && s[j + 1] == 'E') {
					es = i; ee = j + 1; ed = 1;
				}
				else { es = i + 1; ee = j; }
			}

			if (s[j] == '1') board[i][j] = 1;
			else board[i][j] = 0;
		}
	}
	cout << BFS();
}