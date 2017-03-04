/* 2/26/2017
 * CF #402(div 2) B
 * Problem: http://codeforces.com/problemset/problem/779/B
 */

#include<iostream>
using namespace std;

int main () {
	int n, k;
	cin >> n >> k;
	int k2 = k;
	int ans = 0;
	while (n != 0  && k > 0) {
		int temp = n % 10;
		//cout << temp << ' ' << k << endl;
		if (temp) {
			ans ++;
		} else {
			k --;
		}
		n /= 10;
	} 
	if (k != 0) {
		ans += k2 - k;
		while(n) {
			n /= 10;
			ans ++;
		}
		ans --;
		if (ans < 0) {
			cout << 0;
		} else {
			cout << ans;
		}
		return 0;
	}
	cout << ans;
	return 0;
}
