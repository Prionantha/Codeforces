/* 2/17/2017
 * Problem: http://poj.org/problem?id=3984
 * Solution: Maze problem. To find the shortest way, use BFS.
 */
 
#include<iostream>
#include<queue>
#include<stack>
#include<cstring>
using namespace std;

int a[6][6] = {0};
int vis[6][6] = {0};
int dx[5] = {0, -1, 0, 1, 0};
int dy[5] = {0, 0, -1, 0, 1};
int prevx[6][6] = {0};
int prevy[6][6] = {0};

struct T {
	int x;
	int y;
	void init(int a, int b) {
		x = a;
		y = b;
	}
};

queue<T> q;
stack<T> ans;

void print(int x, int y) {
	if (x != 0 || y != 0) {
		T temp;
		temp.init(x, y);
		ans.push(temp);
		print(prevx[x][y], prevy[x][y]);
	}
}

void bfs(T temp) {
	int m = temp.x;
	int n = temp.y;
	if (m == 5 && n == 5) {
		print(m, n);
	} else {
		q.pop();
		for (int i = 1; i <= 4; i++) {
			if (m + dx[i] >= 1 && m + dx[i] <= 5 && n + dy[i] >= 1 && n + dy[i] <= 5 && 
						a[m + dx[i]][n + dy[i]] == 0 && vis[m + dx[i]][n + dy[i]] == 0) {
				vis[m + dx[i]][n + dy[i]] = 1;
				T temp;
				temp.init(m + dx[i], n + dy[i]);
				prevx[m + dx[i]][n + dy[i]]	= m;
				prevy[m + dx[i]][n + dy[i]] = n;
				q.push(temp);
			}
		}
		bfs(q.front());
	}
}

int main () {
	for (int i = 1; i <= 5; i ++) {
		for (int j = 1; j <= 5; j ++) {
			cin >> a[i][j];
		}
	}
	T temp;
	temp.init(1, 1);
	prevx[temp.x][temp.y] = 0;
	prevy[temp.x][temp.y] = 0;
	vis[temp.x][temp.y] = 1;
	q.push(temp);
	bfs(temp);
	while(!ans.empty()) {
		cout << '(' << ans.top().x - 1 << ", " << ans.top().y - 1 << ')';
		ans.pop();
		if (!ans.empty()) {
			cout << endl;
		}
	}
	return 0;
}
