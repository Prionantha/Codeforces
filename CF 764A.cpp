/* 2/19/2017
 * Problem: http://codeforces.com/problemset/problem/764/A
 * Solution: Find the lowest common multiple. Since z < 10^4, just run over every date.
 */
 
#include<iostream>
using namespace std;

int main() {
	int n, m, z;
	cin >> n >> m >> z;
	int count = 0;
	for (int i = 1; i <= z; i ++) {
		if (i % n == 0 && i % m == 0) {
			count ++;
		}
	}
	cout << count;
	return 0;
}
