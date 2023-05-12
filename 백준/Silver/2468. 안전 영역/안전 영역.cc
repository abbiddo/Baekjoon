#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int arr[100][100];
int visit[100][100];

// 상하좌우 탐색을 위함
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

int n, ma, k, re;

void BFS(int r, int c) {
	queue<pair<int, int>> q;
	visit[r][c] = 1;
	q.push({ r,c });

	while (!q.empty()) {
		int rr = q.front().first;
		int cc = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int rrr = rr + dr[i];
			int ccc = cc + dc[i];

			if (rrr < 0 || ccc < 0 || rrr >= n || ccc >= n) continue;
			if (visit[rrr][ccc]) continue;
			if (arr[rrr][ccc] <= k) continue;

			q.push({ rrr,ccc });
			visit[rrr][ccc] = 1;
		}
	}
}

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] > ma) ma = arr[i][j];
		}

	for (k = 0; k <= ma; k++) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) visit[i][j] = 0;

		int cnt = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (visit[i][j] == 0 && arr[i][j] > k) {
					BFS(i, j);
					cnt++;
				}
		re = max(re, cnt);
	}

	cout << re;
}