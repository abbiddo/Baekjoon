#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int n;
int arr[50];

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	if (n < 2) {
		cout << "A";
		return 0;
	}

	if (n == 2 && arr[0] == arr[1]) {
		cout << arr[0];
		return 0;
	}

	if (n == 2) {
		cout << "A";
		return 0;
	}

	int a = 0;
	if (arr[1] != arr[0]) a = (arr[2] - arr[1]) / (arr[1] - arr[0]);

	int b = arr[1] - arr[0] * a;

	for (int i = 2; i < n; i++) {
		if (arr[i] != arr[i - 1] * a + b) {
			cout << "B";
			return 0;
		}
	}

	cout << arr[n - 1] * a + b;

}