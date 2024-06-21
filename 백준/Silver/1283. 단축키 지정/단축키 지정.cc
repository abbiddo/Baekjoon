#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
bool alpha[26];
string s;

int main() {
	cin >> n;
	cin.ignore();
	while (n--) {
		getline(cin, s);
		string origin = s;
		int size = s.size();
		for (int i = 0; i < size; i++)
			s[i] = tolower(s[i]);

		if (s[0] != ' ' && !alpha[s[0] - 'a']) {
			cout << "[" << origin[0] << "]" << origin.substr(1, size - 1) << "\n";
			alpha[s[0] - 'a'] = 1;
			continue;
		}

		bool check = 0;
		for (int i = 1; i < size; i++) {
			if (s[i] != ' ' && s[i - 1] == ' ' && !alpha[s[i] - 'a']) {
				cout << origin.substr(0, i) << "[" << origin[i] << "]" << origin.substr(i + 1, size - i - 1) << "\n";
				alpha[s[i] - 'a'] = 1;
				check = true;
				break;
			}
		}

		if (check) continue;
		for (int i = 1; i < size; i++) {
			if (s[i] != ' '&& !alpha[s[i] - 'a']) {
				cout << origin.substr(0, i) << "[" << origin[i] << "]" << origin.substr(i + 1, size - i - 1) << "\n";
				alpha[s[i] - 'a'] = 1;
				check = true;
				break;
			}
		}

		if (check) continue;
		cout << origin << "\n";
	}
}