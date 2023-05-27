#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int visit[100001];
vector<pair<int, pair<int, int>>> v;

int getParent(int x) {
	if (visit[x] == x) return x;
	return visit[x] = getParent(visit[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a < b) visit[b] = a;
	else visit[a] = b;
}

bool findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a == b) return 1;
	return 0;
}

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;	cin >> n >> m;
	int connect = 0;

	for (int i = 1; i <= n; i++) 
		visit[i] = i;

	for (int i = 0; i < m; i++) {
		int a, b, c;	cin >> a >> b >> c;
		v.push_back({ c, {a, b} });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < m; i++) {
		if (!findParent(v[i].second.first, v[i].second.second)) {
			connect += v[i].first;
			unionParent(v[i].second.first, v[i].second.second);
		}
		else v[i] = { 0, {0, 0} };
	}

	sort(v.begin(), v.end());

	cout << connect - v[v.size() - 1].first;
}