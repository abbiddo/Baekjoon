#include <iostream>
#include <stack>
using namespace std;

int n, m;
int arr[500000];

int main() {
	cin >> n >> m;
	string str;	cin >> str;

	stack<char> s;
	int cnt = 0;
	int i;
	s.push(str[0]);
	for (i = 1; i < str.size(); i++) {
		if (cnt == m) break;
		while (!s.empty() && s.top() < str[i] && cnt < m) {
			s.pop();
			cnt++;
		}
		s.push(str[i]);
	}

	string res = "";
	while (!s.empty()) {
		res = s.top() + res;
		s.pop();
	}

	cout << (res + str.substr(i,s.size() - i)).substr(0, str.size() - m);
}