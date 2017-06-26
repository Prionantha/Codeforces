/* 6/26/2017
 * Problem: http://codeforces.com/problemset/problem/817/B
 * Solution: First find the three smallest number, then consider three cases:
             1. Three numbers differ: cntA * cntB * cntC;
             2. Only two numbers are the same: cnt(differ) * n * (n - 1) / 2;
             3. Three numbers are the same: n* (n - 1) * (n - 2) / 6;
 */

#include<iostream>
#include<algorithm>
using namespace std;
int s[300005] = {0};
int n = 0;
long long ans;

int count(int k) {
	int cnt = 0;
	int i = 1;
	while (i <= n && s[i] <= k) {
		if (s[i] == k) {
			cnt++;
		}
		i++;
	}
	return cnt;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	sort(s + 1, s + n + 1);
	int a = s[1], b = s[2], c = s[3];
	long long cnta = count(a);
	long long cntb = count(b);
	long long cntc = count(c); 
	if (a == b && b == c) {
		ans = cnta * (cnta - 1) * (cnta - 2) / 6; 
	} else {
		if (a == b) {
			ans = cntc * cnta * (cnta - 1) / 2;
		} else if (b == c) {
			ans = cnta * cntb * (cntb - 1) / 2;
		} else {
			ans = cnta * cntb * cntc;
		}
	} 
	cout << ans;
	return 0;
} 
