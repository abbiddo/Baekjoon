#include <iostream>
using namespace std;

int n, cnt;
int arr[100001][2];

int LPR() {
	int i = 1;
	while (arr[i][1]) {
		i = arr[i][1];
		cnt++;
	}
	return i;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c;		cin >> a >> b >> c;
		if (b != -1) arr[a][0] = b;
		if (c != -1) arr[a][1] = c;
	}

	int idx = LPR();

	if (arr[1][1] == 0) cout << (n - 1) * 2;
	else cout << (n - 1) * 2 - cnt;
}