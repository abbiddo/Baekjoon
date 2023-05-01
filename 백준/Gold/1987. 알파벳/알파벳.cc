#include <iostream>
#include <stack>
using namespace std;

// 상하좌우 탐색을 위함
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

char arr[20][20];
int visit[26];
int n, m, re;

// DFS
void DFS(int r, int c, int cnt) {
	visit[arr[r][c]] = 1;
	re = max(re, cnt);

	// 상하좌우 탐색
	for (int i = 0; i < 4; i++) {
		int rr = r + dr[i];
		int cc = c + dc[i];

		// 범위를 넘어서면 continue
		if (rr < 0 || cc < 0 || rr >= n || cc >= m) continue;
		// 지나온 경로 중 해당 알파벳을 밟은 적이 있다면 continue
		if (visit[arr[rr][cc]]) continue;

		// 재귀
		DFS(rr, cc, cnt + 1);
		visit[arr[rr][cc]] = 0;
	}
}

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			arr[i][j] -= 'A';
		}

	DFS(0, 0, 1);

	cout << re;
}