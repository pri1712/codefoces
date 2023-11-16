
#include <bits/stdc++.h>
#include <algorithm>
//#include <map>
using namespace std;
typedef long long ll;
bool checkautomaton(string& s, string& t)
{
	if (t.size() > s.size())
		return false;
	for (std::string::size_type i = 0, j = 0; i < s.size(); i++)
	{
		if (s[i] == t[j])
		{
			j++;
		}
		if (j == t.size())
		{
			return true;
		}
	}
	return false;
}
bool strarray(string& s, string& t)
{
	//can use array if count of all chars are the same.
	unordered_map<char, int> smap;
	for (std::string::size_type i = 0; i < s.size(); i++)
		smap[s[i]]++;
	for (std::string::size_type i = 0; i < t.size(); i++)
		smap[t[i]]--;
	bool res = true;
	for (auto it : smap)
	{
		res &= (it.second == 0);
	}
	return res;
}
bool both(string& s, string& t)
{
	unordered_map<char, int> smap;
	for (std::string::size_type i = 0; i < s.size(); i++)
		smap[s[i]]++;
	for (std::string::size_type i = 0; i < t.size(); i++)
		smap[t[i]]--;
	bool res = true;
	for (auto it : smap)
	{
		res &= (it.second >= 0); //deleting and swapping can only be done if count of all chars in s>t.
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s, t;
	cin >> s;
	cin >> t;
	if (checkautomaton(s, t))
	{
		cout << "automaton" << endl;
		return 0;
	}
	else if (strarray(s, t))
	{
		cout << "array" << endl;
		return 0;
	}
	else if (both(s, t))
	{
		cout << "both" << endl;
		return 0;
	}
	else
		cout << "need tree" << endl;
	return 0;
}