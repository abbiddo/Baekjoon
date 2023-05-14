#include <iostream>
#include <queue>
using namespace std;

string BFS(int n) {
	int visit[20001] = { 0 };
	queue<pair<int, string>> q;
	q.push({ 1, "1" });

	while (!q.empty()) {
		int mod = q.front().first;
		string s = q.front().second;

		q.pop();


		int semi = (mod * 10) % n;
		if (!visit[semi]) {
			if (semi == 0) return s + "0\n";
			q.push({ semi, s + "0" });
			visit[semi] = 1;
		}

		semi = (mod * 10 + 1) % n;
		if (!visit[semi]) {
			if (semi == 0) return s + "1\n";
			q.push({ semi, s + "1" });
			visit[semi] = 1;
		}
	}
	return "BRAK\n";
}

int main() {
	int n;	cin >> n;
	while (n--) {
		int a; cin >> a;
		cout << BFS(a);
	}
}