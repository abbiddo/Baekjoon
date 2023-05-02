#include <iostream>
using namespace std;

int arr[100][100];
int visit[100][100];

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, l, re = 0;	cin >> n >> l;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> arr[i][j];

	for (int i = 0; i < n; i++) {
		int g = 1, cnt = 0;
		for (int j = 0; j < n - 1; j++) {
			int gap = arr[i][j] - arr[i][j + 1];
			if (gap > 1 || gap < -1) break;
			if (gap == 0) g++;
			else if (gap == 1) {
				g = 0;
				if (n - 1 - j < l) break;
				int k = j;
				j++;
				for (j; j < k + l; j++) 
					if (arr[i][j] != arr[i][j + 1]) break;
				j--;
				if (j + 1 != k + l) break;
				cnt += (l - 1);
			}
			else if (gap == -1) {
				int k = g;
				g = 1;
				if (j + 1 < l) break;
				if (k < l) break;
			}

			cnt++;
		}
		if (cnt == n - 1) re++;
	}

	for (int i = 0; i < n; i++) {
		int g = 1, cnt = 0;
		for (int j = 0; j < n - 1; j++) {
			int gap = arr[j][i] - arr[j + 1][i];
			if (gap > 1 || gap < -1) break;
			if (gap == 0) g++;
			else if (gap == 1) {
				g = 0;
				if (n - 1 - j < l) break;
				int k = j;
				j++;
				for (j; j < k + l; j++)
					if (arr[j][i] != arr[j + 1][i]) break;
				j--;
				if (j + 1 != k + l) break;
				cnt += (l - 1);
			}
			else if (gap == -1) {
				int k = g;
				g = 1;
				if (j + 1 < l) break;
				if (k < l) break;
			}

			cnt++;
		}
		if (cnt == n - 1) re++;
	}

	cout << re;
}