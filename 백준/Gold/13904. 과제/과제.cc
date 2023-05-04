#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> arr[1000];
bool dead[1001];

int cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second > b.second) return true;
	return false;
}

int main() {
	int n;		cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;	cin >> a >> b;
		arr[i] = { a,b };
	}

	sort(arr, arr + n, cmp);

	int re = 0;
	for (int i = 0; i < n; i++)
		for (int j = arr[i].first; j > 0; j--)
			if (!dead[j]) {
				dead[j] = 1;
				re += arr[i].second;
				break;
			}

	cout << re;
}