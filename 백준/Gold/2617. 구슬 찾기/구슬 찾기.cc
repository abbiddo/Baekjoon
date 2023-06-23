#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> big[100];
vector<int> small[100];
int node, edge;

int smallBFS(int node) {
	int svisit[100] = { 0 };
	queue<int> q;
	q.push(node);
	svisit[node] = 1;
	int s = 0;

	while (!q.empty()) {
		int n = q.front();
		q.pop();
		
		for (int i = 0; i < small[n].size(); i++) {
			if (svisit[small[n][i]]) continue;
			svisit[small[n][i]] = true;
			s++;
			q.push(small[n][i]);
		}
	}
	return s;
}


int bigBFS(int node) {
	int bvisit[100] = { 0 };
	queue<int> q;
	q.push(node);
	bvisit[node] = 1;
	int b = 0;

	while (!q.empty()) {
		int n = q.front();
		q.pop();

		for (int i = 0; i < big[n].size(); i++) {
			if (bvisit[big[n][i]]) continue;
			bvisit[big[n][i]] = true;
			b++;
			q.push(big[n][i]);
		}
	}
	return b;
}

int main() {
	int res = 0;
	cin >> node >> edge;
	for (int i = 0; i < edge; i++) {
		int a, b;	cin >> a >> b;
		big[b].push_back(a);
		small[a].push_back(b);
	}

	int smallG, bigG;
	for (int i = 1; i <= node; i++) {
		smallG = smallBFS(i);
		bigG = bigBFS(i);
		if (smallG > node / 2 || bigG > node / 2) res++;
	}

	cout << res;
}