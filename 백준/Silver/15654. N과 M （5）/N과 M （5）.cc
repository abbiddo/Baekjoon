#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int input[9];
int arr[9];
bool visit[9];

void DFS(int num, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			arr[cnt] = input[i];
			visit[i] = true;
			DFS(i, cnt + 1);
			visit[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> input[i];
	sort(input, input + n);

	DFS(1, 0);
}