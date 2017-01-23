/* 2017/1/15
 * Problem: http://poj.org/problem?id=2352
 * Solution: Tree array. 
 * Note: 1.Originally I wrote tree[i] = getSum(s[i].x); level[tree[i]] ++; which changed the array value and resulted in an life-long debug.
 *       How silly..
 *	 2. Pay special attention to the x=0 case.
 */

#include<iostream>
#include<algorithm>
#include<cstdio>
#define MAXN 32005
using namespace std;

long long tree[MAXN] = {0};
long long level[MAXN] = {0};

int n;

struct star {
	int x, y;
};

star s[MAXN];

long long lowbit(int x) {
	return x & (-x);
}

long long getSum(int x) {
	long long sum = 0;
	while (x) {
		sum += tree[x];
		x -= lowbit(x);
	}
	return sum;
}

void add(int x) {
	while (x <= MAXN) {
		tree[x] ++;
		x += lowbit(x);
	}
}

int main() {

	//ios::sync_with_stdio(false);

	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
        scanf("%d%d",&s[i].x, &s[i].y);
		//cin >> s[i].x >> s[i].y;
		s[i].x++;
		s[i].y++;
		level[getSum(s[i].x)] ++;
		add(s[i].x);
	}
	for (int i = 0; i <= n-1; i ++) {
        printf("%d\n", level[i]);
		//cout << level[i] << endl;
	}
	return 0;
}
