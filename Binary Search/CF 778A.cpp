/* 7/12/2017
 * Problem: http://codeforces.com/problemset/problem/778/A
 * Solution: Binary search on time. 
 */
 
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int a[200005] = {0};
bool b[200005];

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	int len = s1.length();
	for (int i = 1; i <= len; i++) {
		cin >> a[i];
	}
	int l = 0, r = len + 1;
	while (l + 1 < r) {
		int mid = (l + r) / 2;
		memset(b, false, sizeof(b));
//		for (int i = 1; i <= 7; i++) {
//			b[i] = false;
//		}
		for (int i = 1; i <= mid; i++) {
			b[a[i]] = true;
		}
		string s = "";
		for (int i = 1; i <= len; i++) {
			if (!b[i]) {
				s += s1[i - 1];
			}
		}
		// cout << l << ' ' << r << ' ' << s << endl;
		int p = s.length() - 1;
		int p2 = s2.length() - 1;
		while (p >= 0 && p2 >= 0) {
			if (s[p] == s2[p2]) {
				p2 --;
			}
			p--;
		}
		if (p2 >= 0) {
			r = mid;
		} else {
			l = mid;
		}
	}
	cout << l;
	return 0;
}
