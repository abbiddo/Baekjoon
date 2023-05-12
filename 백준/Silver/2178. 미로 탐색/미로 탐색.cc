#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visit[101][101];
int v[101][101];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int n, m;

void bfs(int r, int c) {
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	visit[r][c] = 1;

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int r_ = r + dy[i];
			int c_ = c + dx[i];

			if (r_>=0 && c_>=0 && r_<=n && c_<=m)
				if (v[r_][c_] && !visit[r_][c_]) {
					v[r_][c_] = v[r][c] + 1;
					visit[r_][c_] = 1;
					q.push(make_pair(r_, c_));
				}
		}
	}
}

int main() {
	cin >> n >> m;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string s;	cin >> s;
		for (int j = 0; j < m; j++) 
			v[i][j] = s[j] - '0';
	}

	bfs(0, 0);
	cout << v[n - 1][m - 1];
}