/* 2017/1/30
 * Problem: http://codeforces.com/problemset/problem/758/A
 */

#include<iostream>
using namespace std;

int main () {
	int n;
	int a[105] = {0};
	cin >> n;
	int maxn = 0;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
		if (a[i] > maxn) {
			maxn = a[i];
		} 
	}
	cout << maxn * n - sum << endl;
	return 0;
}
