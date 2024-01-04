#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int T, N;

int X[1000], Y[1000], Z[1000];

int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			vector<int> pos;
			string s; cin >> s;
			int slen = s.length();
			for (int i = 0; i < slen; i++) {
				if (s[i] == ',') pos.emplace_back(i);
			}
			int& pos1 = pos[0], & pos2 = pos[1];

			X[i] = stoi(s.substr(0, pos1));
			Y[i] = stoi(s.substr(pos1 + 1, pos2 - pos1 - 1));
			Z[i] = stoi(s.substr(pos2 + 1, slen - pos2 - 1));
		}

		set<pair<pair<int, int>,int>> st;
		st.insert(make_pair(make_pair(X[0], Y[0]), Z[0]));

		bool chk = 1;
		for (int i = 1; i < N; i++) {
			bool connected = 0;
			for (int k = 0; k < 6; k++) {
				if (st.count(make_pair(make_pair(X[i] + dx[k], Y[i] + dy[k]), Z[i] + dz[k]))) connected = 1;
			}

			auto p = make_pair(make_pair(X[i], Y[i]), Z[i]);

			if (!connected || st.count(p)) {
				cout << "NO " << i + 1 << '\n';
				chk = 0;
				break;
			}
			
			st.insert(p);
		}

		if (chk) {
			int ans = 0;
			for (auto& p : st) {
				int x = p.first.first, y = p.first.second, z = p.second;
				for (int k = 0; k < 6; k++) {
					if (!st.count(make_pair(make_pair(x + dx[k], y + dy[k]), z + dz[k]))) ans++;
				}
			}

			cout << ans << '\n';
		}
	}
}