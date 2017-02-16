/* 2/16/2017
 * Problem: http://poj.org/problem?id=2386
 * Solution: Count the number of connected block
 */
 
#include<iostream>
#include<cstring>
using namespace std;

string a[105];
bool b[105][105];
int n, m;

void dfs(int x, int y) {
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (x + i >= 0  && x + i < n && y + j >= 0 && y + j < m 
						&& a[x + i][y + j] == 'W' && !b[x + i][y + j]) {
				b[x + i][y + j] = true;
				dfs(x + i, y + j);
			}
		}
	}
}

int main() {
	memset(b, false, sizeof(b));
	int count = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'W' && !b[i][j]) {
				dfs(i, j);
				count ++;
			}
		}
	}
	cout << count;
	return 0;
}
