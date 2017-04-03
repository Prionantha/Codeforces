/* 4/3/2017
 * Problem: http://codeforces.com/problemset/problem/785/A
 */

#include<iostream>
#include<map>
using namespace std;

map<char, int> Map;

int main () {
	Map['T'] = 4;
	Map['C'] = 6;
	Map['O'] = 8;
	Map['D'] = 12;
	Map['I'] = 20;
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		ans += Map[s[0]];
	}
	cout << ans;
	return 0;
}
