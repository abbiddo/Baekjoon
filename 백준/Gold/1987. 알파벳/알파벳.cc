#include <iostream>
#include <stack>
using namespace std;

struct alpha {
	string s;
	int r, c;
};

// 상하좌우 탐색을 위함
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

char arr[20][20];
int visit[26];
int n, m, re;

void DFS(int r, int c, int cnt) {

	visit[arr[r][c]] = 1;
	re = max(re, cnt);

	for (int i = 0; i < 4; i++) {
		int rr = r + dr[i];
		int cc = c + dc[i];

		if (rr < 0 || cc < 0 || rr >= n || cc >= m) continue;
		if (visit[arr[rr][cc]]) continue;

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