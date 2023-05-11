#include <iostream>
using namespace std;

int main() {
	int n;	cin >> n;

	int re = 1;
	while (n > 4) {
		n -= 3;
		re *= 3;
		re %= 10007;
	}

	cout << re * n % 10007;
}