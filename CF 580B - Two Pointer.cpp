/* 5/20/2017
 * Problem: http://codeforces.com/problemset/problem/580/B
 * Solution: Sort all friends according to their money, then use prefix sum and two pointers to get the maximum sum within the range. 
 */

#include<iostream>
#include<algorithm>
using namespace std;

struct T{
	int m;
	int s;
};

bool cmp(T a, T b) {
	return a.m < b.m;
} 

int main () {
	int n, d;
	cin >> n >> d;
	T a[100005]; 
	for (int i = 1; i <= n; i ++) {
		cin >> a[i].m >> a[i].s;
	} 
	long long ans = 0;
	sort(a + 1, a + n + 1, cmp);
	long long sum[100005] = {0};
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i].s;
		//cout << sum[i] << ' ';
	} 
	int l = 1, r = 1;
	long long ma = 0;
	while (l <= n) {
		while (a[r].m - a[l].m < d && r <= n) {
			r ++; 
		} 
		r--; 
		ma = max(sum[r] - sum[l - 1], ma);
		//cout << l << ' ' << r << endl; 
		//cout << sum[r - 1] << ' ' << sum[l - 1] << endl; 
		l++; 
	}
	cout << ma;
	return 0; 
}
