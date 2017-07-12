/* 7/12/2017
 * Problem: http://codeforces.com/problemset/problem/785/C
 */

#include<iostream>
using namespace std;

int main() {
	__int64 n, m;
	cin >> n >> m;
	__int64 l = 1, r = 2e9;
	if (m >= n) {
		cout << n;
		return 0;
	} 
	while (l <= r) {
		__int64 mid = l + (r - l) / 2;
		if (n - mid * (mid + 1) / 2 >  m)  {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << l + m;
	return 0;
} 
