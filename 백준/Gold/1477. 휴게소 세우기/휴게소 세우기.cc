#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int n, m, k;
int arr[52];

int main() {

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	arr[n + 1] = k;

	sort(arr, arr + n + 2);

	int l = 1;
	int r = k;

	while (l <= r) {
		int mid = (l + r) / 2;

		int res = 0;
		for (int i = 1; i <= n + 1; i++) {
			res += (arr[i] - arr[i - 1] - 1) / mid;
		}

		if (res <= m) r = mid - 1;
		else l = mid + 1;
	}

	cout << l;

}