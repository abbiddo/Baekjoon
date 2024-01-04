#include <iostream>
using namespace std;

int n;
string dp[101];
string dpa[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	dp[2] = "1";
	dp[3] = "7";
	dp[4] = "4";
	dp[5] = "2";
	dp[6] = "6";
	dp[7] = "8";
	dp[8] = "10";
	dp[9] = "18";
	dp[10] = "22";
	dp[11] = "20";
	dp[12] = "28";
	dp[13] = "68";
	dp[14] = "88";
	dp[15] = "108";
	dp[16] = "188";
	dp[17] = "200";

	for (int i = 18; i < 101; i++)
		dp[i] = dp[i - 7] + "8";

	dpa[2] = "1";
	dpa[3] = "7";
	for (int i = 4; i < 101; i++) 
		dpa[i] = dpa[i - 2] + "1";

	cin >> n;
	while (n--) {
		int a;	cin >> a;
		cout << dp[a] << " " << dpa[a] << "\n";
	}

}