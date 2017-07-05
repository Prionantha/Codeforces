.* 7/5/2017
 * Problem: http://codeforces.com/problemset/problem/771/A
 */

#include<iostream>
#include<vector>
#define ll long long
using namespace std;
int n, m;
vector<int> mp[150005];
bool v[150005];

void dfs(int i, int & p, int & e) {
	v[i] = true;
	p ++;
	e += mp[i].size();
	vector<int>::iterator it;
	for (it = mp[i].begin(); it != mp[i].end(); ++it) {
		if (!v[*it]) {
			dfs(*it, p, e);
		}
	}
}

int main () {
	cin >> n >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		mp[x].push_back(y);
		mp[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		if (!v[i]) {
			int p = 0, e = 0;
			dfs(i, p, e);
			if ((ll)p * (ll)(p - 1) != (ll)e) {
				cout << "NO";
				return 0;
			}
		}	
	}
	cout << "YES";
	return 0;
}
