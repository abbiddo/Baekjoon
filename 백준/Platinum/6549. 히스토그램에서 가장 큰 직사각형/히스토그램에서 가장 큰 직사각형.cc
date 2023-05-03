#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

stack<long long> s;
long long arr[100002];

int main() {
    // 입출력 속도를 단축시키기 위함
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        int n;    cin >> n;
        if (n == 0) break;
        for (int i = 1; i <= n; i++) cin >> arr[i];
        arr[n + 1] = 0;

        while (!s.empty()) s.pop();
        s.push(0);

        long long re = 0;
        for (int i = 1; i <= n + 1; i++) {
            while (!s.empty()) {
                long long top = s.top();

                if (arr[top] <= arr[i]) break;

                s.pop();

                re = max(re, arr[top] * (i - s.top() - 1));
            }
            s.push(i);
        }

        cout << re << "\n";
    }
}