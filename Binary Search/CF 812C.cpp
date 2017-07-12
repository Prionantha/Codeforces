/* 6/28/2017
 * Problem: http://codeforces.com/problemset/problem/812/C
 * Solution: Binary Search. At first I misunderstood the statement, the "xj" thing. For each mid, a sort must be applied.
 */

#include<iostream>
#include<algorithm>
using namespace std;
long long temp [100005] = {0};

int main() {
	int n, s;
	cin >> n >> s;
	int a[100005] = {0};
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int l = 0, r = n + 1;
	long long sum = 0;
	while (l + 1 < r) {
		sum = 0;
		long long mid = (l + r) / 2;
		for (int i = 1; i <= n; i++) {
			temp[i] = a[i] + mid * i;
		}
		sort(temp + 1, temp + n + 1);
		sum = 0;
		for (int i = 1; i <= mid; i++) {
			sum += temp[i];
		}
		if (sum <= s) {
			l = mid;
		} else {
			r = mid;
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		temp[i] = a[i] + l * i;
	}
	sort(temp + 1, temp + n + 1);
	for (int i = 1; i <= l; i++) {
		ans += temp[i];
	}
	cout << l << ' ' << ans;
	return 0;
}
