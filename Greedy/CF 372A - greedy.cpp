/* 7/12/2017
 * Problem: http://codeforces.com/problemset/problem/372/A
 * Solution: Divide the sorted array in the middle, and then apply greedy to match pairs.
 */

#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[500005] = {0};
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int ans = n;
	int p1 = 1, p2 = n / 2 + 1;
	while (p1 <= n /2 && p2 <= n) {
		if (a[p1] * 2 <= a[p2] ) {
			p1 ++;
		}
		p2 ++;
	}
	cout << n - p1 + 1;
	return 0;
}
