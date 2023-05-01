#include <iostream>
using namespace std;

int n, re = 1000000;
string Q, A;

void solve(int zero) {
	string input = Q;
	int cnt = 0;

	if (zero) {
		input[0] = input[0] == '1' ? '0' : '1';
		input[1] = input[1] == '1' ? '0' : '1';
		cnt++;
	}

	for (int i = 1; i < n; i++) {
		if (input[i - 1] != A[i - 1]) {
			for (int j = i-1; j <= i + 1 && j < n; j++)
				input[j] = input[j] == '1' ? '0' : '1';
			cnt++;
		}
	}
	
	if (input == A) re = min(re, cnt);
}

int main() {
	cin >> n >> Q >> A;
	solve(0);
	solve(1);
	if (re == 1000000) cout << -1;
	else cout << re;
}