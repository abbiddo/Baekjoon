#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int down[100000];
int up[100000];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n / 2; i++) {
		int a, b;	cin >> a >> b;
		down[i] = a;
		up[i] = b;
	}

	sort(up, up + n / 2);
	sort(down, down + n / 2);

	int mi = 200001;
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		int d = lower_bound(down, down + n / 2, i) - down;
		int u = lower_bound(up, up + n / 2, (m - i + 1)) - up;
		d = n / 2 - d;
		u = n / 2 - u;

		if (d + u < mi) {
			mi = d + u;
			cnt = 1;
		}
		else if (d + u == mi) cnt++;
	}
	cout << mi << " " << cnt;
}