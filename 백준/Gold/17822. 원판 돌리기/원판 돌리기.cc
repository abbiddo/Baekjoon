#include <iostream>
#include <vector>
using namespace std;

int n, m, t;
vector<int> one[51];
int arr[50];
bool check[51][51];

void rotate(int x, int d, int k) {
	if (!d) {
		while (k--) {
			int tmp = one[x][m - 1];
			one[x].erase(one[x].end() - 1);
			one[x].insert(one[x].begin(), tmp);
		}
	}
	else {
		while(k--) {
			int tmp = one[x][0];
			one[x].erase(one[x].begin());
			one[x].push_back(tmp);
		}
	}
}

int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };
bool search() {

	for (int i = 1; i <= n; i++)
		for (int j = 0; j < m; j++) check[i][j] = false;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 4; k++) {
				int rr = i + dr[k];
				int cc = j + dc[k];

				if (rr < 1 || rr > n || cc < 0 || cc >= m) continue;
				if (one[i][j] == 0) continue;

				if (one[rr][cc] == one[i][j]) {
					check[rr][cc] = true;
					check[i][j] = true;
				}
			}
		}
		if (one[i][0] == one[i][m - 1] && one[i][0] != 0) {
			check[i][0] = true;
			check[i][m - 1] = true;
		}
	}

	bool c = false;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++)
			if (check[i][j]) {
				c = true;
				one[i][j] = 0;
			}
	}

	return c;
}

void count() {
	int cnt = 0;
	double sum = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < m; j++) {
			if (one[i][j]) cnt++;
			sum += one[i][j];
		}

	sum /= cnt;

	for (int i = 1; i <= n; i++)
		for (int j = 0; j < m; j++) {
			if (one[i][j] == 0) continue;
			if (one[i][j] > sum) one[i][j] --;
			else if (one[i][j] < sum) one[i][j]++;
		}
}

int main() {

	cin >> n >> m >> t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a;	cin >> a;
			one[i + 1].push_back(a);
		}
	}

	while (t--) {
		int x, d, k;
		cin >> x >> d >> k;

		// 회전하기
		int tmp = 1;
		while (x * tmp <= n) {
			rotate(x * tmp, d, k);
			tmp++;
		}

		// 인접하는 수 찾기
		bool c = search();

		// 평균 처리
		if (!c) count();
	}

	int res = 0;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			res += one[i + 1][j];

	cout << res;
}