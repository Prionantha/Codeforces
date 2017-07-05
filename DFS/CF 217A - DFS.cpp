/* 7/5/2017
 * Problem: http://codeforces.com/problemset/problem/217/A
 * Solution: A point (x, y) is equal to "From row x, one is able to get to Column y, and vice versa.". So, we're using the idea 
             of searching, counting the number of points that is seperated from others.
 */
 
#include<iostream>
using namespace std;
int x[1005] = {0};
int y[1005] = {0};
bool v[105];
int n;

void dfs(int j) {
	v[j] = true;
	for (int i = 1; i <= n; i++) {
		if (!v[i] && (x[i] == x[j] || y[i] == y[j])) {
			dfs(i);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i]; 
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!v[i]) {
			ans++;
			dfs(i);
		}
	}
	cout << ans - 1;
	return 0;
}
