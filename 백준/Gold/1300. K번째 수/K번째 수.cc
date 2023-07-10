#include <iostream>
using namespace std;

long long n, m, res;

long long k(long long num) {
	long long count = 0;
	for (int i = 1; i <= n; i++) {
		if (i > num) break;
		else if (i * n <= num) count += n;
		else count += (num / i);
	}
	return count;
}

int main() {
	cin >> n >> m;
	long long start = 1, end = n * n;
	while (start <= end) {
		long long mid = (start + end) / 2;
		long long count = k(mid);

		if (count < m) start = mid + 1;
		else {
			res = mid;
			end = mid - 1;
		}
	}

	cout << res;
}