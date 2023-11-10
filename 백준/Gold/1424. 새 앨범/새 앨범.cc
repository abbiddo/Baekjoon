#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n, l, c;

int main() {

	cin >> n >> l >> c;

	c++;
	int inCD = c / (l + 1);

	int res = INT_MAX;

	if (n < inCD) {
		if (n % 13 == 0) cout << 2;
		else cout << 1;
		return 0;
	}

	for (int i = inCD; i >= 0; i--) {
		if (i % 13 == 0) {
			continue;
		}

		int mod = n % i;
		int div = n / i;

		if (mod > 0) {
			if (mod % 13 == 0 && mod + 1 == i) div += 2;
			else div += 1;
		}

		res = min(res, div);
	}

	cout << res;
}