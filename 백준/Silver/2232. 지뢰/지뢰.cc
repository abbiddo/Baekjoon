#include <iostream>
using namespace std;

int arr[50002];

int main() {
	int n;	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 1; i <= n; i++) 
		if (arr[i - 1] <= arr[i] && arr[i + 1] <= arr[i]) 
			cout << i << "\n";
}