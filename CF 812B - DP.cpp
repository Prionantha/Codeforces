/* 6/1/2017
 * Problem: http://codeforces.com/contest/812/problem/B
 * Solution: 2-D DP. Record the optimised steps for each floor and whether it's from left stair or right. 
 * Note: There're several cases I didn't realize in the first begninning. 
         1. The top floor doesn't need to be reached if there's no light there.
         2. There's one special case when all the lights are turned off.
         3. The case of only one floor has light and is also the bottom floor needs special attention.
 */

#include<iostream>
#include<cmath>
using namespace std;
#define MAX 2000;

int main() {
	int dp[20][100] = {0};
	int n, m;
	cin >> n >> m;
	string s[20];
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		// cout << s[i] << endl;
	}
	int last;
	bool stop = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i][j] == '1') {
//				cout << i << ' ' << j << endl;
				last = i;
				stop = false;
				break;
			}
		}
		if (!stop) {
			break;
		}
	} 
	for (int i = 1; i <= last - 1; i++) {
		for (int j = 0; j <= 1; j++){
			dp[i][j] = MAX;
		}
	}
	for (int i = n; i >= 1; i--) {
			int left1 = 0, left2 = 0, right1 = 0, right2 = 0;
			int leftp = m + 1, rightp = 0;
			bool first = true;
			// cout << s[i] << endl;
			for (int k = 1; k <= m; k++) {
				// cout << s[i][k] << ' ';
				if (s[i][k] == '1') {
					if (first) {
						leftp = k;
						first = false;
					}
					rightp = k;
				} 
			}
			if (i == last) {
				if (i == n) {
					cout << (rightp > (m - leftp + 1)? rightp: m - leftp + 1);
					return 0;
				}
				dp[last][0] = dp[last + 1][0] + rightp;
				dp[last][1] = dp[last + 1][1] + (m - leftp + 1);
				cout << (dp[last][1] < dp[last][0]? dp[last][1]: dp[last][0]);
				return 0;
			}
		 	// cout << dp[i - 1][0] << endl;
//		 	cout << leftp << ' ' << rightp << endl;
			left1 = dp[i + 1][0] + 2 * rightp + 1;
			left2 = dp[i + 1][1] + m + 2;
			right1 = dp[i + 1][1] + 2 * (m - leftp + 1) + 1;
			right2 = dp[i + 1][0] + m + 2;
//			cout << left1 << ' ' << left2 << ' ' << right1 << ' ' << right2 << endl;
			if (i == n) {
				dp[i][0] = left1;
				dp[i][1] = right2;
				continue;
			}
			dp[i][0] = min(left1, left2);
			dp[i][1] = min(right1, right2);
//			cout << dp[i][0] << ' ' << dp[i][1] << endl;
//		cout << endl;
	}
	cout << 0;
	return 0;
}
