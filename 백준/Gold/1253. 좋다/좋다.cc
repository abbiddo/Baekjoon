#include <iostream>
#include <algorithm>
using namespace std;

int arr[2000];

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;		cin >> n;
	int res = 0;
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + n);

	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (i != 0 && arr[i] == arr[i - 1] && flag) {
			res++;
			continue;
		}

		int l = 0, r = n - 1;
		flag = false;

		while (true) {
			if (l == i) l++;
			else if (r == i) r--;

			if (l >= r) break;

			int sum = arr[l] + arr[r];
			if (sum == arr[i]) {
				res++;
				flag = true;
				break;
			}
			else if (sum < arr[i]) l++;
			else r--;
		}
	}
	cout << res;
}