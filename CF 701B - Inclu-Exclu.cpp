/* 5/21/2017
 * Problem: http://codeforces.com/problemset/problem/701/B
 */
 
#include<iostream>
using namespace std;

struct T{
	long long x, y;
};

int main () {
	long long ans;
	long long d, n;
	cin >> d >> n;
	T a[100005] = {0};
	bool x[100005];
	bool y[100005];
	long long cntx = 0, cnty = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y;
		if (x[a[i].x] == false) {
			cntx ++;
			x[a[i].x] = true; 
		}
		if (y[a[i].y] == false) {
			cnty ++;
			y[a[i].y] = true;
		}
		// cout << cntx << ' ' << cnty << endl; 
		ans = (cntx + cnty) * d - cntx * cnty;
		ans = d * d - ans;
		cout << ans << ' ';		
	} 
	return 0;
} 
