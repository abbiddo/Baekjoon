#include <iostream>
#include <algorithm>
using namespace std;

int n, m, negative, res;
int arr[50];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] < 0) negative++;
	}
	sort(arr, arr + n);

	int index = n - 1;
	while (index >= negative) {
		res += 2 * arr[index];
		index -= m;
	}

	index = 0;
	while (index < negative) {
		res -= 2 * arr[index];
		index += m;
	}

	res -= max(abs(arr[0]), arr[n - 1]);

	cout << res;
}