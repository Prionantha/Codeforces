/* 2/15/2017
 * Problem: http://poj.org/problem?id=1852
 * Solution: Here's one trick: when two ants meet with each other, since they walk at the same speed, it doesn't really matter if they 
             turn around or not. They're just switching each other, which won't affect the ultimate result. So just compare the max and min.
 */
 
#include<iostream>
#include<cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int l, k;
		cin >> l >> k;
		int temp;
		cin >> temp;
		int minn = min(temp, l - temp), maxn = max(temp, l - temp);
		for (int i = 1; i < k; i++) {
			cin >> temp;
			minn = max(min(temp, l - temp), minn);
			maxn = max(max(temp, l - temp), maxn);
		}
		cout << minn << ' ' << maxn << endl;
	}
	return 0;
} 
