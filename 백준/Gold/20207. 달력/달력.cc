#include <iostream>
using namespace std;

int n, res;
int arr[366];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, e;	cin >> s >> e;
		for (int j = s; j <= e; j++) arr[j]++;
	}

	for (int i = 1; i < 366; i++) {
		int ma = 0, k;
		if (arr[i] != 0) {
			k = i;
			while (arr[i]) {
				ma = max(ma, arr[i]);
				i++;
			}
			res += (i - k) * ma;
		}
	}
	cout << res;
}