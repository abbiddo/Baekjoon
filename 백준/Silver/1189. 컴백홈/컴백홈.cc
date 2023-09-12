#include <iostream>
#include <algorithm>
using namespace std;

int n, m, l, res;
char arr[5][5];
int visit[5][5];

int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };

void dfs(int r, int c, int cnt) {
	if (r == 0 && c == m - 1) {
		if (cnt == l) res++;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int rr = r + dr[i];
		int cc = c + dc[i];

		if (rr < 0 || cc < 0 || rr >= n || cc >= m) continue;
		if (arr[rr][cc] == 'T' || visit[rr][cc]) continue;

		visit[rr][cc] = true;
		dfs(rr, cc, cnt + 1);
		visit[rr][cc] = false;
	}
}

int main() {
	cin >> n >> m >> l;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> arr[i][j];

	visit[n - 1][0] = true;
	dfs(n - 1, 0, 1);

	cout << res;
}