#include <iostream>
#include <algorithm>
using namespace std;

int n, visit;
pair<int, int> arr[1000000];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;	cin >> a >> b;

		arr[i] = { b, a };
	}

	sort(arr, arr + n);

	visit = arr[n - 1].first - arr[n - 1].second;
	for (int i = n - 2; i >= 0; i--) {
		visit = min(visit, arr[i].first);
		visit -= arr[i].second;
	}

	cout << visit;
}