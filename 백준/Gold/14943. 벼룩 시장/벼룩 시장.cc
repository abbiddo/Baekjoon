#include <iostream>
using namespace std;

int n;
int arr[100001];
long long res;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 1; i <= n; i++) {
		res += abs(arr[i - 1] + arr[i]);
		arr[i] = arr[i - 1] + arr[i];
	}

	cout << res;
}