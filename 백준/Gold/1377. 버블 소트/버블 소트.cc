#include <iostream>
#include <algorithm>
using namespace std;

int n, re;
pair<int, int> arr[500000];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;	cin >> a;
		arr[i] = { a, i };
	}

	sort(arr, arr + n);

	for (int i = 0; i < n; i++) 
		re = max(re, arr[i].second - i);

	cout << re + 1;
}