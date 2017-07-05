/* 5/21/2017
 * Problem: http://codeforces.com/problemset/problem/279/B
 * Solution: prefix sum, two pointer
 * Note: Pay attention to the case that r < l after l++
 */

#include<iostream>
using namespace std;

int main() {
	int n, t;
	cin >> n >> t;
	int a[100005] = {0};
	long long sum[100005] = {0};
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	int l = 1, r = 1;
	int m = 0;
	while (r <= n && l <= r) {
		while (sum[r] - sum[l - 1] <= t && r <= n) {
			r ++;
		}
		r--;
		// cout << l << ' ' << r << endl; 
		m = max(m, r - l + 1);
		l ++;
		if (r < l) {
			r = l;
		}		
	}
	cout << m;
	return 0;
}
