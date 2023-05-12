#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

ll arr[300000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;	cin >> n >> m;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	sum *= m;
	sort(arr, arr + n);

	int index = 0;
	for (int i = 0; i < m; i++) 
		sum -= arr[index++] * (m - i);

	cout << sum;
}