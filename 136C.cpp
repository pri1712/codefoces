#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#define ci(n) cin>>n
#define co(n) cout<<n
#define nl '\n'
#define r0 return 0
#define LLMAX LLONG_MAX
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define printstr(s) for(int i=0;i<(int)s.size();i++) { cout<<s[i];}
typedef std::pair<int, int> pp;
typedef long long ll;
typedef std::vector<ll> vl;
typedef std::vector<std::pair<int, int>> vp;
typedef std::vector<int> vi;
typedef std::unordered_map<int, int> unmap;
typedef std::unordered_set<int> unset;
typedef std::unordered_set<char> unsetc;
using namespace std;
int mod = 1e9 + 7;
bool isodd(ll x)
{
	return (x % 2);
}
int gcd(int a , int b)
{
	if (b == 0) return a;
	else return gcd(b , a % b);
}
int lcm( int a , int b)
{
	return a * b / gcd(a, b);
}
ll findmax(vector<ll>& arr)
{
	ll res = -1;
	for (auto it : arr)
	{
		res = max(res, it);
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
	ll n;
	ci(n);
	vl arr(n);
	for (int i = 0; i < n; ++i)
	{
		ci(arr[i]);
	}
	ll maxi = findmax(arr);
	if (maxi > 1)
	{
		for (int i = 0; i < n; ++i)
		{
			if (arr[i] == maxi)
			{
				arr[i] = 1;
				break;
			}
		}
	}
	else
	{
		arr[0] = 2;
	}
	sort(all(arr));
	for (auto it : arr)
	{
		co(it); co(" ");
	}
	r0;
}
