#include <iostream>
#include <stack>
using namespace std;

int n, res;

string s;

int main() {
	cin >> n >>s;
	stack<int> st;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			st.push(0);
		}
		else {
			if (st.size() && st.top() == 0) {
				st.pop();
				st.push(2);
			}
			else if (st.size() && st.top() > 0) {
				int tmp = 0;
				while (!st.empty() && st.top() > 0) {
					tmp += st.top();
					st.pop();
				}
				if (st.size() && st.top() == 0) {
					st.pop();
					st.push(tmp + 2);
				}
				else {
					st.push(tmp);
					st.push(-1);
				}
			}
			else st.push(-1);
		}
	}

	while (!st.empty()) {
		int tmp = 0;
		while (st.size() && st.top() > 0) {
			tmp += st.top();
			st.pop();
		}
		if (st.size()) st.pop();
		res = max(res, tmp);
	}

	cout << res;

}