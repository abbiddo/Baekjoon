#include <iostream>
#include <queue>
using namespace std;

int n, m;
int sr = -1, sc = -1, fr = -1, fc = -1;

char arr[1500][1500];
int visit[1500][1500];
int vis[1500][1500];

int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };

queue<pair<int, int>> q;

void ice() {
	queue<pair<int, int>> temp;
	do {
		while (!temp.empty()) temp.pop();
		while (!q.empty()) {
			int r = q.front().first;
			int c = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];

				if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
				if (visit[nr][nc]) continue;
				if (arr[nr][nc] == 'X') {
					visit[nr][nc] = visit[r][c] + 1;
					temp.push({ nr, nc });
				}

			}
		}
		q = temp;
	} while (temp.size());
}

void bfs() {
	queue<pair<int, int>> qq;
	qq.push({ sr, sc });
	vis[sr][sc] = 0;

	while (!qq.empty()) {
		int r = qq.front().first;
		int c = qq.front().second;
		qq.pop();

		int tmp; 

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;

			tmp = max(visit[nr][nc], vis[r][c]);
			if (vis[nr][nc] != 750 && vis[nr][nc] <= tmp) continue;

			vis[nr][nc] = tmp;
			qq.push({ nr, nc });
		}
	}

	cout << vis[fr][fc];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			vis[i][j] = 750;
			cin >> arr[i][j];
			if (arr[i][j] == 'L') {
				if (sr == -1) {
					sr = i;
					sc = j;
				}
				else {
					fr = i;
					fc = j;
				}
			}
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != 'X') {
				for (int k = 0; k < 4; k++) {
					int r = i + dr[k];
					int c = j + dc[k];

					if (r < 0 || c < 0 || r >= n || c >= m) continue;
					if (arr[r][c] == 'X') {
						q.push({ i, j });
						break;
					}

				}
			}
		}
	ice();

	bfs();

}