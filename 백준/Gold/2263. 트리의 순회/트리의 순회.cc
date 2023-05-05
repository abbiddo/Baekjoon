#include <iostream>
using namespace std;

int in[100001];
int post[100001];

void order(int is, int ie, int ps, int pe) {
	int k;

	if (ps <= pe) {
		cout << post[pe] << " ";;
		for (int i = is; i <= ie; i++)
			if (post[pe] == in[i]) {
				k = i;
				break;
			}

		int p = ps - (is - k) ;
		order(is, k - 1, ps, p - 1);
		order(k + 1, ie, p, pe - 1);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;		cin >> n;
	for (int i = 1; i <= n; i++) cin >> in[i];
	for (int i = 1; i <= n; i++) cin >> post[i];

	order(1, n, 1, n);
}