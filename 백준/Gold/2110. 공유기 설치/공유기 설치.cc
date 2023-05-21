#include <iostream>
#include <algorithm>
using namespace std;

int arr[200000];
int n, m;

bool gongugi(int mid) {
	int cnt = 1;
	int house = arr[0];

	for (int i = 1; i < n; i++) {
		if (arr[i] - house >= mid) {
			house = arr[i];
			cnt++;
		}
	}

	return cnt >= m;
}

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + n);

	int start = 1, end = arr[n - 1] + 1, mid;
	while (start < end) {
		mid = (start + end) / 2;
		bool check = gongugi(mid);

		if (check) start = mid + 1;
		else end = mid;
	}

	cout << start - 1;
}