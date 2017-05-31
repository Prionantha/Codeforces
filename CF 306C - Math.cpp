/* 5/30/2017
 * Problem: http://codeforces.com/problemset/problem/550/C
 * Solution: There are two ways of doing it. The first one is using the math fact that the last three digits of all numbers divisble 
             by eight must be divisible by eight. For one and two digits, pre-handle and print the table. The second is using dp but 
             I didn't get it through - - maybe add that solution later
 * Update: @philippica offered a brand new solution: list out all the factors of eight which are less then 1000, and then do matching
 	   between them and the string. The worst case scenario would be (1000 / 8) * 100, which is significantly faster than my 
	   approach.
 */

#include<iostream>
#include<cstring>
using namespace std;

int a[] = {16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96};
 
int main() {
	string s;
	cin >> s;
	int len = s.length();
	int ans = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] == '0') {
			cout << "YES" << endl << 0;
			return 0;
		} else if (s[i] == '8') {
			cout << "YES" << endl << 8;
			return 0;
		}
	}
	if (len < 3) {
		if (len == 1) {
			ans = s[0] - '0';
		} else {
			ans = (s[0] - '0') * 10 + s[1] - '0'; 
		}
		if (ans % 8 == 0) {
			cout << "YES" << endl << ans;
		} else {
			cout << "NO";
		}
		return 0;
	} else {
		for (int i = 0; i < len - 1; i++) {
			for (int j = i + 1; j < len; j++) {
				int num = (s[i] - '0') * 10 + (s[j] - '0');
				for (int k = 0; k < 11; k++) {
					if (num == a[k]) {
						// cout << "wtf";
						cout << "YES" << endl << num;
						return 0;
					}
				}
			}
		}
		for (int i = 0; i < len - 2; i++) {
			for (int j = i + 1; j < len - 1; j++) {
				for (int k = j + 1; k < len; k++) {
					int num = (s[i] - '0') * 100 + (s[j] - '0') * 10 + s[k] - '0';
					if (num % 8 == 0) {
						cout << "YES" << endl << num;
						return 0;
					}
				} 
			}
		}		
	}
	cout << "NO";
	return 0;
}
