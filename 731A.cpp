/* 2/14/2017
 * Problem: http://codeforces.com/problemset/problem/731/A
 * Solution: count the distance clockwise and counter-clockwise and choose the smaller one
 */

#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int ans=0;
	ans+=min(abs(s[0]-'a'),abs('a'+26-s[0]));
	//cout<<min(abs(s[0]-'a'),abs('a'+26-s[0]))<<endl;
	for(int i=1;i<s.length();i++)
	{
		//cout<<abs(s[i]-s[i-1])<<' '<<abs(26-abs(s[i]-s[i-1]))<<endl;
		ans+=min(abs(s[i]-s[i-1]),abs(26-abs(s[i]-s[i-1])));
	}
	cout<<ans;
	return 0;
}
