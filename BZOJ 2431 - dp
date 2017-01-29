/* 2017/1/28
 * Problem: http://www.lydsy.com/JudgeOnline/problem.php?id=2431
 * Solution: 2-D dynamic programming 
 */

#include<iostream>
using namespace std;
int dp[1005][1005] = {0};
int sum[1005] = {0};

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1;
		sum[0] = dp[i-1][0];
		for (int j = 1; j <= k; j++) {
			sum[j] = sum[j-1] + dp[i-1][j];
		}
		for (int j = 1; j <= k; j++) {
			dp[i][j] = (sum[j] - sum[j-(i-1)-1]) % 10000;
		}
	}
	cout << dp[n][k];
	return 0;
}
