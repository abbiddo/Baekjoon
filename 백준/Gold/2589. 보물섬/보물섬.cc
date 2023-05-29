#include <iostream>
#include <queue>
using namespace std;

int n, m, dist;
char arr[50][50];

int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

struct treasure {
	int r, c, cnt;
};

void BFS(int i, int j) {
	queue<treasure> q;
	bool visit[50][50] = { 0 };

	q.push({ i, j, 0 });
	visit[i][j] = true;

	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		int cnt = q.front().cnt;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int rr = r + dr[i];
			int cc = c + dc[i];

			if (rr < 0 || cc < 0 || rr >= n || cc >= m) continue;
			if (visit[rr][cc]) continue;
			if (arr[rr][cc] == 'W') continue;

			dist = max(dist, cnt + 1);
			visit[rr][cc] = true;
			q.push({ rr, cc, cnt + 1 });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> arr[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (arr[i][j] == 'L') {
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int rr = i + dr[k];
					int cc = j + dc[k];

					if (rr < 0 || cc < 0 || rr >= n || cc >= m) continue;
					if (arr[rr][cc] == 'W') continue;

					cnt++;
				}
				if (cnt == 1 || cnt == 2) BFS(i, j);
			}

	cout << dist;
}