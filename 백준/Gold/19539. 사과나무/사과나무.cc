#include <iostream>
#include <algorithm>
using namespace std;

int n, sum, two;
int arr[100000];

int main() {
	// 입출력 속도 향상을 위함
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
		two += arr[i] / 2;
	}
	
	if (sum % 3 || sum / 3 > two) {
		cout << "NO";
		return 0;
	} 

	cout << "YES";
}