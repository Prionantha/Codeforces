/* 7/12/2017
 * Problem: http://codeforces.com/problemset/problem/165/B
 */
 
#include<iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int l = 0, r = n + 1;
	int sum;
	while (l < r) {
		int mid = l + (r - l) / 2; 
		sum = 0;
		int tmp = 1;
		while (mid / tmp > 0) {
			sum += mid / tmp;
			tmp *= k;
		}  
		if (sum < n) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	cout << l;
	return 0;
} 
