#include <iostream>
#include <stack>
using namespace std;

int cnt, idx;
string str;
stack<int> s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> str;

	while (idx < str.size()) {
		int semi = 0;
		if (str[idx] == '(') s.push(-1);
		else if (str[idx] == ')') {
			while (s.size() && s.top() != -1) {
				semi += s.top();
				s.pop();
			}
			s.pop();
			int t = s.top();
			s.pop();
			if (str[idx - 1] != '(') s.push(semi * t);
		}
		else {
			if (str[idx + 1] == '(') s.push(str[idx] - '0');
			else s.push(1);
		}
		idx++;
	}

	while (!s.empty()) {
		cnt += s.top();
		s.pop();
	}

	cout << cnt;
}