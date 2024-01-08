#include <iostream>
#include <queue>
using namespace std;

int n, m, tmp;
int arr[1000][1000];
int visit[1000][1000];
int idx[1000][1000];

int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };

void bfs(int index, int r, int c) {
	queue<pair<int, int>> q;
	queue<pair<int, int>> pos;

	pos.push({ r, c });
	q.push({ r, c });
	visit[r][c] = -2;

	int cnt = 1;
	while (!q.empty()) {
		int rr = q.front().first;
		int cc = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = rr + dr[i];
			int nc = cc + dc[i];

			if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
			if (visit[nr][nc] != 0) continue;
			if (arr[nr][nc] == -1) continue;

			q.push({ nr, nc });
			pos.push({ nr, nc });
			visit[nr][nc] = -2;

			cnt++;
		}
	}

	while (!pos.empty()) {
		int rr = pos.front().first;
		int cc = pos.front().second;
		pos.pop();

		visit[rr][cc] = cnt;
		idx[rr][cc] = index;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;	cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j] - '0';
			if (arr[i][j] == 1) {
				arr[i][j] = -1;
				visit[i][j] = -1;
			}
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (visit[i][j] == 0) 
				bfs(++tmp, i, j);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) cout << 0;
			else {
				int cnt = 1;
				int temp[4];
				int ind = 0;
				for (int k = 0; k < 4; k++) {
					int nr = i + dr[k];
					int nc = j + dc[k];

					if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
					if (visit[nr][nc] == -1) continue;
					
					temp[ind++] = idx[nr][nc];

					for (int kk = 0; kk < ind - 1; kk++) 
						if (temp[kk] == idx[nr][nc]) {
							cnt -= visit[nr][nc];
							break;
						}

					cnt += visit[nr][nc];
				}

				cout << cnt % 10;
			}
		}
		cout << "\n";
	}
}