#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
int dp_table[501][16];
 
int dp(int cur, int state)
{
	//base
	if (cur < 0)	return 0;
	if (cur == 0)	return state == 0;	//텅텅 비어야 1가지 가능.
	int &cache = dp_table[cur][state];
	if (cache != -1)	return cache;
 
	switch (state) {
		case 0:
			cache = dp(cur - 1, 0) + dp(cur - 2, 0) + dp(cur - 1, 3) + dp(cur - 1, 9) + dp(cur - 1, 12);
			break;
		case 3:
			cache = dp(cur - 1, 0) + dp(cur - 1, 12);
			break;
		case 6:
			cache = dp(cur - 1, 9);
			break;
		case 9:
			cache = dp(cur - 1, 0) + dp(cur - 1, 6);
			break;
		case 12:
			cache = dp(cur - 1, 0) + dp(cur - 1, 3);
			break;
	}
	return cache;
}
 
 
int main()
{
	int t;
	scanf("%d", &t);
 
	memset(dp_table, -1, sizeof(dp_table));
	while (t--){
		int n;
		scanf("%d", &n);
		printf("%d\n", dp(n, 0));
	}
 
	return 0;
}