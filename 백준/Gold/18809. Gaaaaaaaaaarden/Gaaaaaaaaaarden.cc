#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m, r, g, res;
int arr[50][50];

vector<pair<int, int>> v;
pair<int, int> R[5], G[5];

int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { -1, 0, 1, 0 };

void bfs() {
	queue<pair<int, int>> qr;
	queue<pair<int, int>> qg;
	pair<int, int> visit[50][50] = { { {0, 0} } };
	int cnt = 0;

	for (int i = 0; i < r; i++) {
		qr.push(R[i]);
		visit[R[i].first][R[i].second] = { 1, 1 };
	}
	for (int i = 0; i < g; i++) {
		qg.push(G[i]);
		visit[G[i].first][G[i].second] = { 1, 2 };
	}

	int count = 2;
	while (!qr.empty() || !qg.empty()) {
		int rsize = qr.size(), gsize = qg.size();
		for (int i = 0; i < rsize; i++) {
			int r = qr.front().first;
			int c = qr.front().second;
			qr.pop();

			if (visit[r][c].first == 10000) continue;

			for (int j = 0; j < 4; j++) {
				int rr = r + dr[j];
				int cc = c + dc[j];

				if (rr < 0 || rr >= n || cc < 0 || cc >= m) continue;
				if (arr[rr][cc] == 0) continue;
				if (visit[rr][cc].first) continue;
				if (visit[rr][cc].second == 1) continue;

				visit[rr][cc] = { count, 1 };
				qr.push({ rr, cc });
			}
		}

		for (int i = 0; i < gsize; i++) {
			int r = qg.front().first;
			int c = qg.front().second;
			qg.pop();

			for (int j = 0; j < 4; j++) {
				int rr = r + dr[j];
				int cc = c + dc[j];

				if (rr < 0 || rr >= n || cc < 0 || cc >= m) continue;
				if (arr[rr][cc] == 0) continue;
				if (visit[rr][cc].second == 2) continue;
				if (visit[rr][cc].first && visit[rr][cc].first != count) continue;

				if (visit[rr][cc].first == count) {
					cnt++;
					visit[rr][cc] = { 10000, 0 };
				}
				else {
					qg.push({ rr, cc });
					visit[rr][cc] = { count, 2 };
				}
			}
		}
		count++;
	}
	res = max(res, cnt);
}

void green(int cnt, int index) {
	if (cnt == g) {
		bfs();
		return;
	}

	for (int i = index; i < v.size(); i++) {
		if (arr[v[i].first][v[i].second] == 2) {
			G[cnt] = v[i];
			arr[v[i].first][v[i].second] = 4;
			green(cnt + 1, i + 1);
			arr[v[i].first][v[i].second] = 2;
		}
	}
}

void red(int cnt, int index) {
	if (cnt == r) {
		green(0, 0);
		return;
	}

	for (int i = index; i < v.size(); i++) {
		R[cnt] = v[i];
		arr[v[i].first][v[i].second] = 3;
		red(cnt + 1, i + 1);
		arr[v[i].first][v[i].second] = 2;
	}
}

int main() {
	cin >> n >> m >> g >> r;
	for (int i = 0; i <n ;i++)
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) v.push_back({ i, j });
		}
	red(0, 0);
	cout << res;
}