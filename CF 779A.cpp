/* 2/26/2017
 * CF #402(div 2) A
 * Problem: http://codeforces.com/problemset/problem/779/A
 */
 
#include<iostream>
#include<cmath>
using namespace std;

int main () {
	int n;
	cin >> n;
	int a[105] = {0}, b[105] = {0};
	int cnt1[10] = {0}, cnt2[10] = {0};
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt1[a[i]] ++;
		cnt2[a[i]] ++;
	}
	for (int i = 1; i <= n; i ++) {
		cin >> b[i];
		cnt2[b[i]] ++;
	}
	for (int i = 1; i <= 5; i++) {
		if (cnt2[i] % 2) {
			cout << -1;
			return 0;
		}
	}
	int ans = 0;
	for (int i = 1; i <= 5; i++) {
		//cout << cnt2[i] / 2 << ' ' << cnt1[i] << endl;
		ans += abs(cnt2[i] / 2 - cnt1[i]);
	}
	cout << (ans + 1) / 2;
	return 0;
}
