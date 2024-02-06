#include <iostream>
using namespace std;

string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> s;

	int cnt = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ':') cnt++;
	}

	string tmp = ":";
	for (int i = 0; i < 8 - cnt; i++) {
		tmp += "0000:";
	}
	if (s.find("::") != string::npos) s.replace(s.find("::"), 2, tmp);

	if (s[0] == ':') s = "0000" + s;
	if (s[s.size() - 1] == ':') s = s + "0000";

	tmp = "";
	for (int i = 0; i < s.size(); i++) {
		tmp += s[i];
		if (s[i] == ':') {
			while (tmp.size() < 5) tmp = "0" + tmp;
			cout << tmp;
			tmp = "";
		}
	}

	while (tmp.size() < 4) tmp = "0" + tmp;
	cout << tmp;
}