#include <iostream>
using namespace std;

int main() {
	string s;	cin >> s;
	string ma = "";
	string mi = "";
	s += " ";

	string sample = "";
	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] == 'M') sample += '0';
		else {
			ma += '5' + sample;
			sample = "";
		}
	}
	for (int i = s.size() - 2; i >= 0; i--) {
		if (s[i] == 'K') break;
		ma += '1';
	}

	sample = "";
	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] == 'K') mi += '5';
		if (s[i] == 'M') {
			if (s[i + 1] == 'K' || s[i + 1] == ' ') {
				mi += '1' + sample;
				sample = "";
			}
			else sample += '0';
		}
	}

	cout << ma << "\n" << mi;
}