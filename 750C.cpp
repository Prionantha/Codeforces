/* 1/3/2017
 * Goodbye 2016
 * Problem: http://codeforces.com/contest/750/problem/C
 * Solution: Recode max and min possible rating and update with every new contest.
 * Note: The initial value for max and min is 2000000000 and -2000000000 to avoid overflow. But it's still 
 * 	gonna happen (with a high probability). But the data tested is not strong enough so it still passes..
 */

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int c,d;
	bool b1 = false, b2 = false;
	int minn = -2000000000, maxx = 2000000000;
	for(int i=1;i<=n;i++)
	{
		cin>>c>>d;
		if (d == 1) {
			b1 = true;
			minn = max(minn, 1900);
		} else {
			//cout<<minn<<' '<<maxx<<endl;
			b2 = true;
			maxx = min(maxx, 1899);
		}
		maxx += c;
		minn += c;
		//cout<<minn<<' '<<maxx<<endl;
		if (minn > maxx) {
			cout<<"Impossible";
			return 0;
		}		
	}
	if (!b2) {
		cout<<"Infinity";
		return 0;
	}
	cout<<maxx;
	return 0;
} 
