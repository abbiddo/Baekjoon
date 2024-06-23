#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<pair<string, string>> v;

int main() {
	cin >> n >> m;
	while (n--) {
		string s; cin >> s;
		int a; cin >> a;
		while (a--) {
			string tmp;
			cin >> tmp;
			v.push_back({ tmp, s });
		}
	}

	sort(v.begin(), v.end());

	while (m--) {
		string s; int a;
		cin >> s >> a;
		if (a) {
			for (int i = 0; i < v.size(); i++) {
				if (v[i].first == s) {
					cout << v[i].second << "\n";
					break;
				}
			}
		}
		else {
			for (int i = 0; i < v.size(); i++) {
				if (v[i].second == s) {
					cout << v[i].first << "\n";
				}
			}
		}
	}
}