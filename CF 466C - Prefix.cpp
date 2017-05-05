/* 5/4/2017
 * Problem: http://codeforces.com/problemset/problem/466/C
 * Solution: Record the number of possible places to put a block from the end of array with cnt[i]. Thus, for arbitrary a[i],
             the number of possible blockings after that would be sum(cnt[i~n]). To ensure it's been divided into three parts, ans should 
             add cnt[i+2] instead of cnt[i].
 * Others: Finally wiping out the second page of cf... It's been in the wait list for a long time. Did this after reading tutorial.
 */


#include<iostream>
using namespace std;
int a[500005], cnt[500005];

int main () {
	//ios::sync_with_stdio(false);
	int n;
	cin >> n;
	long long aa = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		aa += a[i];
	} 
	if (aa % 3 != 0) {
		cout << 0;
		return 0; 
	}
	long long temp = 0;
	for (int i = n; i >= 1; i--) {
		temp += a[i];
		if (temp == aa / 3) {
			cnt[i] = 1;
		}
	}
	for (int i = n-1; i >= 1; i--) {
		cnt[i] += cnt[i+1];
	}
	long long sum = 0;
	long long ans = 0;
	for (int i = 1; i + 2 <= n; i++) {
		sum += a[i];
		if (sum == aa / 3) {
			ans += cnt[i + 2];
		}
	}
	cout << ans;
	return 0;
} 
