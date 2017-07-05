/* 2017/1/6
 * Problem: http://codeforces.com/problemset/problem/580/C
 * Solution: Use adjacency list to record all paths, then dfs to count cats along the way.
 * Note: 
 * 	1. mix up arrays starting from 0 and 1
 * 	2. get confused on the logic: it should be "Nodes that all related paths are parent is a root node."
 */

#include<iostream>
#include<vector>
using namespace std;

int n,m;
int c[100005] = {0};
int ans = 0;
vector<int> a[100005];

void dfs(int p, int father, int cat) {
	if (cat > m) {
		return;
	} else {
		int b = 0;
		for (int i = 0; i <= a[p].size()-1; i++) {
			if (a[p][i] != father) {
				b = 1;
				if (c[a[p][i]] == 1) {
					dfs(a[p][i], p, cat + 1);
				} else {
					dfs(a[p][i], p, 0);
				}
			}
		}
		if (b == 0) {
			ans ++;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	} 
	for (int i = 1; i <= n-1; i++) {
		int l, r;
		cin >> l >> r;
		a[l].push_back(r);
		a[r].push_back(l);
	}
	dfs(1, 0, c[1]);
	cout << ans;
	return 0;
} 
