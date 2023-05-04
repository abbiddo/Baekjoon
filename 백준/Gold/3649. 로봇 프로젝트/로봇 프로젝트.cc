#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[1000000];

int main() {
	while (cin >> n) {
		n *= 10000000;

		cin >> m;
		for (int i = 0; i < m; i++) cin >> arr[i];

		if (m < 2) {
			cout << "danger\n";
			continue;
		}
		sort(arr, arr + m);

		bool flag = false;
		int l = 0, r = m - 1;
		while (l < r) {
			if (arr[l] + arr[r] == n) {
				flag = true;
				break;
			}
			else if (arr[l] + arr[r] > n) r--;
			else l++;
		}
		if (flag) cout << "yes " << arr[l] << " " << arr[r] << "\n";
		else cout << "danger\n";
	}
}