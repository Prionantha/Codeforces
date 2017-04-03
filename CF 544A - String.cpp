/* 4/3/2017
 * Problem: http://codeforces.com/problemset/problem/544/A
 * Solution: It's the same as "counting how many different letters are there".
 */
 
#include<iostream>
#include<cstring>
using namespace std;

int main () {
	bool a[27];
	for (int i = 0; i <= 26; i ++) {
		a[i] = false;
	}
	int n;
	string s;
	int count = 0;
	cin >> n >> s;
	for (int i = 0; i < s.length(); i++) {
		if (!a[s[i] - 'a' + 1]) {
			a[s[i] - 'a' + 1] = true;
			count ++;
		}
	}
	if (count < n) {
		cout << "NO";
		return 0;
	}
	cout << "YES";
	bool b[27];
	for (int i = 0; i <= 26; i ++) {
		b[i] = false;
	}
	for (int i = 0; i < s.length(); i++) {
		if (!b[s[i] - 'a' + 1]) {
			b[s[i] - 'a' + 1] = true;
			if (n) {
				n --;
				cout << endl;
			}
		}
		cout << s[i];
	}
	return 0;
} 
