#include <iostream>
using namespace std;

int arr[101];
long long dp[101][21];

int main(){
	int n;	cin>>n;
	
	for(int i =0; i<n;i++) cin>>arr[i];
	
	dp[0][arr[0]] = 1;
	
	for (int i = 0; i < n-2; i++){
		for (int j = 0; j < 21; j++) {
            if(dp[i][j] != 0){
                int p = j+arr[i+1];
                int m = j-arr[i+1];

                if(m>=0)
                    dp[i+1][m] += dp[i][j];
                if(p<21)
                    dp[i+1][p] += dp[i][j];
            }
        }
	}
	
	cout<<dp[n-2][arr[n-1]];
}