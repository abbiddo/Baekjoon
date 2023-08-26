#include <iostream>
using namespace std;

int n, res = 40000;
int arr[21][21];
bool visit[21];

void DFS(int number, int cnt) {
	if (cnt == n / 2) {
		int link = 0;
		int start = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (visit[i] == true && visit[j] == true) start += arr[i][j];
				if (visit[i] == false && visit[j] == false) link += arr[i][j];
			}
		}
		res = min(res, abs(link-start));
		return;
	}

	for (int i = number; i <= n; i++) {
		visit[i] = true;
		DFS(i + 1, cnt + 1);
		visit[i] = false;
	}
}

int main() {
	// 입출력 속도 향상을 위함
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];

	DFS(1, 0);

	cout << res;
}