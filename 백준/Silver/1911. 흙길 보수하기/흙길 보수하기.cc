#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

pair<int, int> arr[10002] = { {-1, -1} };
int n, l, res = 0;

int main() {
	cin >> n >> l;

	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		arr[i] = { start, end };
	}

	sort(arr, arr + n);

	int index = arr[0].first;
	for (int i = 0; i < n; i++) {
		if (index < arr[i].first) index = arr[i].first;
		while (index < arr[i].second) {
			index += l;
			res++;
		}
	}

	cout << res;
}