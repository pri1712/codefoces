#include <bits/stdc++.h>
#include <algorithm>
//#include <map>
using namespace std;
typedef long long ll;
int cnt[27];
bool valid()
{
	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] > 1)
		{
			return false;

		}
	}
	return true;
}
void fillrem(string& s)
{
	for (std::string::size_type i = 0; i < s.size(); i++)
	{
		if (s[i] == '?')
			s[i] = 'A';
	}
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
	string s;
	cin >> s;
	//slide a window over 26 letters at a time.
	if (s.size() <= 25) {
		cout << -1 << endl;
		return 0;
	}

	for (int i = 0; i < 26; i++) cnt[s[i] - 'A']++;
	if (valid())
	{
		int cur = 0;
		while (cnt[cur] > 0)
			cur++;
		for (int i = 0; i < 26; i++)
		{
			if (s[i] == '?')
			{
				s[i] = cur + 'A';
				cur++;
				while (cnt[cur] > 0)
					cur++;
			}
		}
		fillrem(s);
		cout << s << endl;
		return 0;
	}
	//int i = 0;
	for (std::string::size_type i = 26;  i < s.size(); i++)
	{
		cnt[s[i] - 'A']++;
		cnt[s[i - 26] - 'A']--; //removing the previous ones. somewhat like a sliding window.
		if (valid())
		{
			int cur = 0;
			while (cnt[cur] > 0)
				cur++;
			for (std::string::size_type j = i - 25; j <= i; j++)
			{
				if (s[j] == '?')
				{
					s[j] = cur + 'A';
					cur++;
					while (cnt[cur] > 0)
						cur++;
				}
			}
			fillrem(s);
			cout << s << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}