#include <iostream>
using namespace std;

int n, i, j, cnt = 0;
string s[10000];

int main() {
	cin >> n;

	for (i = 0; i < n; i++) cin >> s[i];

	for (i = 0; i < n; i++) {
		cnt = 0;
		for (j = 0; j < s[i].size(); j++) {
			if (s[i][j] == '(') cnt += 1;
			else cnt -= 1;

			if (cnt < 0) break;
		}
        if (cnt) cout << "NO\n";
        else cout<<"YES\n";
	}
}