/* 5/21/2017
 * Problem: http://codeforces.com/problemset/problem/723/B
 * Note: Character '_' lies between Lowercase letter and Uppercase letter
 */

#include<iostream>
using namespace std;

bool inRange(char ch) {
	return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt = 0;
	int size = s.length();
	int temp = 0;
	int m = 0; 
	int i = 0; 
	while (i < size) {
		// cout << i << endl;
		if (s[i] == '(') {
			while (s[i] != ')') {
				if (inRange(s[i]) && !inRange(s[i - 1])) {
					cnt ++;
				}
				i++;
			}
			temp = 0;
		} else {
			if (inRange(s[i])) {
				temp ++;
			}  else {
				temp = 0;
			}
			m = max(m, temp);			
		}
		i++;
	}
	cout << m << ' ' << cnt;
	return 0;
}
