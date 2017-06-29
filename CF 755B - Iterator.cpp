/* 6/29/2017
 * Problem: http://codeforces.com/problemset/problem/755/B
 * Solution: It's actually quite easy. If the equal string appears even times, then simply compare n and m. Otherwise, 
             n += 1 and compare n & m.
 * Note: The usage of iterator.
 *       Under C++ 98, there's no 'for' iterator. The only choice is literally create an iterator.
         To fetch the object of the iterator, simply put "*".
         The return value of find function is an iterator, but not a boolean value! If it can be found then it's the 
         iterator, otherwise it's set.end().
 */

#include<iostream>
#include<set>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	set<string> a, b;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		a.insert(s);
	}
	for (int i = 1; i <= m; i++) {
		string s;
		cin >> s;
		b.insert(s);
	}
	int cnt = 0;
	set<string>::iterator it;
	for (it = b.begin(); it != b.end(); ++it) {
		if (a.find(*it) != a.end()) {
			cnt ++;
		}		
	}
	if (cnt % 2 == 0) {
		cout << (n > m ? "YES" : "NO");
		return 0;
	}
	n += cnt / 2 + 1;
	m += cnt / 2;
	cout << (n > m ? "YES" : "NO");
	return 0;
}
