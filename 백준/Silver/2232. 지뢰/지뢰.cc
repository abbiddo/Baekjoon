#include <iostream>
using namespace std;

int arr[50000];

int main() {
	int n;	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	if (n == 1) {
		cout << 1;
		return 0;
	}

	if (arr[0] >= arr[1]) cout << 1 << "\n";
	for (int i = 1; i < n - 1; i++) 
		if (arr[i - 1] <= arr[i] && arr[i + 1] <= arr[i]) cout << i + 1 << "\n";
	if (arr[n - 1] >= arr[n - 2]) cout << n;
}