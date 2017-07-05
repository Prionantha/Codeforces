/* 7/5/2017
 * Problem: http://codeforces.com/problemset/problem/277/A
 * Solution: a[i][j] represents Employee j is able to speak the i-th language. For each employee, find the languages s/he can speak,
             then for the language all its speaker. 
 */


#include<iostream>
using namespace std;

bool a[105][105];
bool v[105];
int n, m;

void dfs(int i) {
	v[i] = true;
	for (int j = 1; j <= m; j++) {
		if (a[j][i]) {
			for (int k = 1; k <= n; k++) {
				if (!v[k] && a[j][k]) {
					dfs(k);
				}
			}
		}
	} 
}

int main() {
	bool b = false;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		if (k) {
			b = true;
		}
		for (int j = 1; j <= k; j++) {
			int lan;
			cin >> lan;
			a[lan][i] = true;
		} 
	}
	if (!b) {
		cout << n;
		return 0; 
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!v[i]) {
			ans ++;
			dfs(i);	
		}
	}
	cout << ans - 1;
	return 0;
}
