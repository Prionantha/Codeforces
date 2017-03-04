/* 2/26/2017
 * CF #402(div2) C
 * Problem: http://codeforces.com/problemset/problem/779/C
 */

#include<iostream>
#include<algorithm>
using namespace std;

struct T {
	int a;
	int b;
};

int a[200005] = {0}, b[200005] = {0};
T diff[200005] = {0};

int cmp(T x, T y) {
	return x.a < y.a;
}

int main () {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		diff[i].a = a[i] - b[i];
		diff[i].b = i;
	}
	sort(diff + 1, diff + n + 1, cmp);
	int i = 1;
	int ans = 0;
	while (k > 0) {
		ans += a[diff[i].b];
		i ++;
		k --;
		//cout << ans << ' ' << k << endl;
	}
	while (i <= n) {
		if (diff[i].a > 0) {
			ans += b[diff[i].b];
		} else {
			ans += a[diff[i].b];
		}
		i ++;
		//cout << ans << ' ' << k << ' ' << diff[i-1].a << endl;
	}
	cout << ans;
	return 0;
}
