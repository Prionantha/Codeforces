/* 7/4/2017
 * Problem: http://codeforces.com/problemset/problem/567/C
 * Solution: This is a rather exquisite solution. Two map, l, r are applied to record the number of numbers on the left/right 
             side of the current one pointed. 
 */ 

#include<iostream>
#include<map>
using namespace std;
long long a[200005] = {0};
map<long long, long long> l, r;

int main() {
	int n, k;
	long long ans = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		r[a[i]]++;
	}
	for (int i = 1; i <= n; i++) {
		long long ll = 0, rr = 0;
		if (a[i] % k == 0) {
			ll = l[a[i] / k];
		}
		r[a[i]]--; 
		rr = r[a[i] * k];
		ans += ll * rr;
		l[a[i]]++;
	}
	cout << ans;
	return 0;
}
