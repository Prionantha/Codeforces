/* 7/7/2017
 * Problem: http://poj.org/problem?id=1002
 * Solution: Map.
 * Note: It's actually a rather easy one, but I overlooked the possibility of "000-0000". Also, the difference between 
         head <cstring> and <string> resulted in CE in C++.  
         It's the first time iterating over a map, and the usage of "->first" "->second".
 */


#include<iostream>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
map<string, int> mp;

char trans(char ch) {
	if (ch < 58) {
		return ch;
	} else {
		if (ch <= 'P') {
			return (char)((ch - 'A') / 3 + 2 + '0');
		} else {
			return (char)((ch - 'A' - 1) / 3 + 2 + '0');
		}		
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		// cout << "1" << endl;
		string s;
		cin >> s;
		// cout << s;
		string num;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] != '-') {
				num += trans(s[j]);
			}
		}
		if (mp.find(num) != mp.end()) {
			mp[num] ++;
		} else {
			mp.insert(pair<string, int>(num, 1));
		}
	}
	map<string, int>::iterator it;
	bool b = false;
	for (it = mp.begin(); it != mp.end(); it++) {
		string tmp1 = it->first;
		int tmp2 = it->second;
		if (tmp2 > 1) {
			b = true;
			for (int i = 0; i <= 2; i++) {
				cout << tmp1[i];
			}
			cout << '-';
			for (int i = 3; i <= 6; i++) {
				cout << tmp1[i];
			}
			cout << ' ' << tmp2 << endl;
		}
	}
	if (!b) {
		cout << "No duplicates.";
	}
	return 0;
}
