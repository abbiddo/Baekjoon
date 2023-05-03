#include <iostream>
using namespace std;

string s;
int dp[2501];
bool p[2501][2501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;
    int n = s.length();
    s = " " + s;

    for (int i = 1; i <= n; i++) p[i][i] = true;
    for (int i = 1; i < n; i++) 
        if (s[i] == s[i + 1]) p[i][i + 1] = true;
    for (int i = 3; i <= n; i++)
        for (int j = 1; j + i - 1 <= n; j++) {
            int end = j + i - 1;
            if (s[j] == s[end] && p[j + 1][end - 1]) p[j][end] = true;
        }

    for (int i = 1; i <= n; i++) {
        dp[i] = 2500;
        for (int j = 1; j <= i; j++)
            if (p[j][i]) dp[i] = min(dp[i], dp[j - 1] + 1);
    }

    cout << dp[n];
}