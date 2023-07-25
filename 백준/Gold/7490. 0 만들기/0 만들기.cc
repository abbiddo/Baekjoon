#include <iostream>
#include <string>
#include <queue>
using namespace std;

int test, n;

void zero(int k, string s, int res) {
	if (k == n) {
		if (res == 0) {
			cout << s << "\n";
		}
		return;
	}

	int i, tmp = 0, ten = 1;
	char op = ' ';
	for (i = (k - 1) * 2 - 1; i > 0; i -= 2) {
		tmp += ten * (s[i + 1] - '0');
		ten *= 10;

		if (s[i] == '+' || s[i] == '-') {
			op = s[i];
			break;
		}
	}

	int temp;
	if (op == '+') temp = res - tmp + tmp * 10 + k + 1;
	else if (op == '-') temp = res + tmp - tmp * 10 - k - 1;
	else temp = res * 10 + (k + 1);

	zero(k + 1, s + " " + to_string(k + 1), temp);
	zero(k + 1, s + "+" + to_string(k + 1), res + (k + 1));
	zero(k + 1, s + "-" + to_string(k + 1), res - (k + 1));
}

int main() {
	cin >> test;
	while (test--) {
		cin >> n;
		zero(1, "1", 1);
		cout << "\n";
	}
}