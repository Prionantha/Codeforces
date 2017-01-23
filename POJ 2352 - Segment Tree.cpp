/* 2017/1/23
 * Problem: http://poj.org/problem?id=2352
 * Solution: Obvious segment tree.
 *           Another possible solution: BIT https://github.com/Prionantha/OJ/blob/master/POJ%202352%20-%20BIT.cpp
 */

#include<iostream>
#include<algorithm>
#include<cstdio>
#define MAXN 122005
using namespace std;

long long tree[MAXN] = {0};
long long level[MAXN] = {0};

int n;

struct star {
	int x, y;
};

star s[MAXN];

long long query(int node, int l, int r, int ql, int qr) {
	int sum = 0;
	int mid = (l + r) / 2;
	if (l >= ql && r <= qr) {
		sum = tree[node];
	} else {
		if (ql < mid) {
            sum += query(node * 2, l, mid, ql, qr);
		}
		if (qr > mid) {
            sum += query(node * 2 + 1, mid, r, ql, qr);
		}
	}
	return sum;
}

void add(int node, int l, int r, int x) {
	if (l + 1 == r) {
		tree[node]++;
	} else {
		int mid = (l + r) / 2;
		if (x < mid) {
			add(node * 2, l, mid, x);
		} else {
			add(node * 2 + 1, mid, r, x);
		}
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

int main() {
	scanf("%d", &n);
	int maxn = 0;
	for (int i = 1; i <= n; i ++) {
        scanf("%d%d",&s[i].x, &s[i].y);
		s[i].x++;
        if (s[i].x > maxn) {
            maxn = s[i].x;
        }
	}
	for (int i = 1; i <= n; i ++) {
        int tmp = query(1, 1, maxn + 1, 1, s[i].x + 1);
		level[tmp]++;
		add(1, 1, maxn + 1, s[i].x);
	}
	for(int i = 0; i < n; i ++) {
        printf("%d\n", level[i]);
	}
	return 0;
}
