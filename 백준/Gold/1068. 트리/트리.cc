#include <iostream>
#include <vector>
using namespace std;

vector <int> v[51];
bool visit[51];
int n, d, root;
int cnt;

void dfs(int index) {
	if (visit[index]) return;
	visit[index] = 1;

	if (v[index].size() == 0 || (v[index].size() == 1 && v[index][0] == d)) cnt++;

	for (int i = 0; i < v[index].size(); i++)
		if (v[index][i] != d) dfs(v[index][i]);
}

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;	cin >> a;
		if (a == -1) root = i;
		else v[a].push_back(i);
	}

	cin >> d;
	if (root == d) {
		cout << 0;
		return 0;
	}

	dfs(root);
	cout << cnt;
}