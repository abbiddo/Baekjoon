#include <iostream>
#include <queue>
using namespace std;

int dr[8] = { -2 ,-1, 1, 2, 2, 1, -1, -2 };
int dc[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int n, m, k, t;
int visit[301][301][2];
int clean[301][301];
queue<pair<int, int>> q1, q2;

void bfs(int size, int time) {
	queue<pair<int, int>>& q = t % 2 ? q1 : q2;
	queue<pair<int, int>>& nq = t % 2 ? q2 : q1;

	for (int i = 0; i < size; i++) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int j = 0; j < 8; j++) {
			int rr = r + dr[j];
			int cc = c + dc[j];

			if (rr < 1 || rr > n || cc < 1 || cc > n) continue;
			if (visit[rr][cc][time % 2]) continue;

			nq.push({ rr,cc });
			visit[rr][cc][time % 2] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k >> t;

	if (n < 3) {
		cout << "NO";
		return 0;
	}

	for (int i = 0; i < m; i++) {
		int x, y;	cin >> x >> y;
		q1.push({ x, y });
		visit[x][y][0] = 1;
	}

	if (n == 3 && m == 1 && visit[2][2][0] == 1) {
		cout << "NO";
		return 0;
	}

	for (int i = 1; i <= t; i++) {
		if (t % 2) bfs(q1.size(), i);
		else bfs(q2.size(), i);
	}

	for (int i = 0; i < k; i++) {
		int x, y;	cin >> x >> y;
		if (visit[x][y][t % 2]) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}