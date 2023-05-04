#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

ll arr[5000];

int main() {
	int n;		cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + n);

	int re[3] = { 0 };
	ll mi = 3000000001;

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			ll sum = -(arr[i] + arr[j]);
			int zero = lower_bound(arr + j + 1, arr + n, sum) - arr;

			if (zero == n) zero--;
			if (arr[zero] == sum) {
				re[0] = arr[i];	re[1] = arr[zero];	re[2] = arr[j];
				sort(re, re + 3);
				cout << re[0] << " " << re[1] << " " << re[2];
				return 0;
			}

			if (mi > abs(-sum + arr[zero])) {
				mi = abs(-sum + arr[zero]);
				re[0] = arr[i];	re[1] = arr[zero];	re[2] = arr[j];
			}

			if (mi > abs(-sum + arr[zero - 1])) {
				if (zero - 1 == j) continue;
				mi = abs(-sum + arr[zero - 1]);
				re[0] = arr[i];	re[1] = arr[zero - 1];	re[2] = arr[j];
			}
		}
	}
	sort(re, re + 3);
	cout << re[0] << " " << re[1] << " " << re[2];
}