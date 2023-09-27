#include <iostream>
using namespace std;

int n;

int main() {
	cin >> n;
	while (n--) {
		string s;	cin >> s;

		int left = 0;
		int right = s.size() - 1;
		int res = 0;

		int sl = -1, sr = -1;
		while (left < right) {
			if (s[left] == s[right]) {
				left++;
				right--;
			}
			else {
				if (!res) {
					res = 1;
					if (s[left + 1] == s[right] && s[right - 1] == s[left]) {
						sl = left;
						sr = right - 1;
					}
					if (s[left + 1] == s[right]) left++;
					else if (s[right - 1] == s[left]) right--;
					else {
						res = 2;
						break;
					}
				}
				else {
					res = 2;
					break;
				}
			}
		}
		if (sl != -1 && res == 2) {
			res = 1;
			while (sl < sr) {
				if (s[sl] == s[sr]) {
					sl++;
					sr--;
				}
				else {
					res = 2;
					break;
				}
			}
		}
		::cout << res << "\n";
	}
}