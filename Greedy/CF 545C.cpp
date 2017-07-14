/* 7/14/2017
 * Problem: http://codeforces.com/contest/545/problem/C
 * Solution: For trees from left to right, if it can be cut to left then cut left, or cut right if possible. Otherwise, just leave 
             it there. The reasoning is simple. If one tree is cut left, then it has no affect on following trees at all, so we 
             would try to cut left as long as it's possible. The worst consequence of cutting a tree right would be that the next 
             tree wouldn't be cut, which does not change the overall result at all. 
 * Note: Pay special attention to the overflow for x[i] - p.
 */
#include<iostream>
using namespace std;
int x[100005] = {0};
int h[100005] = {0}; 

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> h[i];
	}
	int p = INT_MIN;
	int cnt = 0;
	x[n + 1] = INT_MAX;
	for (int i = 1; i <= n; i++) {
		if (h[i] < (long long)x[i] - p) {
			p = x[i];
			cnt ++;
			// cout << i << "L" << endl; 
		} else if (h[i] < x[i + 1] - x[i]) {
			p = x[i] + h[i];
			cnt ++; 
			// cout << i << "R" << endl;
		}
		p = max(p, x[i]); 
	}
	cout << cnt;
	return 0; 
}
