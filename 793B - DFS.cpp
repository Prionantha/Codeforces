/* 4/23/2017
 * Problem: http://codeforces.com/problemset/problem/793/B
 * Solution: 3-D DFS. Need an extra dimension to represent if it has been to the point with one turn or two.
 */
 
#include<iostream>
using namespace std;

string s[1005];
int m, n;
int sx, sy;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
bool visited[1005][1005][3];

int getDirection(int dx, int dy) {
	if (dx == -1 && dy == 0) {
		return 1;
	} else if (dx == 0 && dy == -1) {
		return 2;
	} else if (dx == 0 && dy == 1) {
		return 3;
	} else {
		return 4;
	}	
}

bool dfs(int x, int y, int turn, int dir) {
	// cout << x << ' ' << y << ' ' << turn << endl;
	if (turn <= 2 && x >= 0 && x < m && y >= 0 && y < n && s[x][y] != '*' && !visited[x][y][turn]) {
		visited[x][y][turn] = true;
		if (s[x][y] == 'T') {
			return true;
		}
		for (int i = 0; i < 4; i++) {
			if (dir != getDirection(dx[i], dy[i])) {
				if (dfs(x + dx[i], y + dy[i], turn + 1, getDirection(dx[i], 
											dy[i]))) {
					return true;
				}
			}else {
				if (dfs(x + dx[i], y + dy[i], turn, getDirection(dx[i], 
											dy[i]))) {
					return true;
				}				
			}

		}		
	}
	return false;
}

int main () {
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (s[i][j] == 'S') {
				sx = i; 
				sy = j;
			}
		}
	}
	// cout << sx << ' ' << sy << endl;
	if (dfs(sx, sy, -1, 0)) {
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;
	return 0;
}
