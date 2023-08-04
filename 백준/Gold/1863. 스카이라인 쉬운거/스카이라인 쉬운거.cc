#include <iostream>
using namespace std;

int n, res, ma;
bool arr[500001];

int main() {
	// 입출력 속도 향상을 위함
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	int tmp = 0;
	for (int i = 0; i < n; i++) {
		int a, b;	cin >> a >> b;
		ma = max(ma, b);

		if (b > tmp) {
			res++;
			arr[b] = true;
		}
		else {
			if (!arr[b] && b != 0) res++;
			for (int j = b; j <= ma; j++) arr[j] = false;
			arr[b] = true;
			ma = b;
		}
		tmp = b;
	}
	cout << res;
}