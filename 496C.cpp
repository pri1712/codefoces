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
ll modpow(ll x, ll n, ll m) {
	if (n == 0) return 1 % m;
	long long u = modpow(x, n / 2, m);
	u = (u * u) % m;
	if (n % 2 == 1) u = (u * x) % m;
	return u;
}
// void sieve()
// {
//    for (int i = 2; i * i <= 10000000 ; i++)
//    {
//        if (isprime[i] == 0)
//        {
//            for (int j = 2 * i; j <= (int)isprime.size(); j += i)
//                isprime[j] = 1;
//        }
//    }
// }
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// unordered_map<ll, ll> mp;
	// mp.reserve(1024);
	// mp.max_load_factor(0.25);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	ci(n); ci(m);
	vector<string> arr(n);
	for (int i = 0; i < n; ++i)
	{
		ci(arr[i]);
	}
	if (n == 1)
	{
		co(0); co(nl);
		r0;
	}
	ll res = 0;
	unordered_set<int> st;
	unordered_set<int> ok;
	for (int j = 0; j < m; ++j)//control col
	{
		for (int i = 0; i < n - 1; ++i) //control row
		{
			if (arr[i][j] > arr[i + 1][j] && ok.find(i) == ok.end())//remove the col
			{
				if (st.find(j) == st.end())
					res++;
				st.insert(j);//remove j column and add it to st set.
			}
		}
		if (st.find(j) != st.end())
			continue;
		else
		{
			for (int i = 0; i < n - 1; ++i)
			{
				if (ok.find(i) == ok.end() && arr[i][j] < arr[i + 1][j])
					ok.insert(i);
			}
		}

	}
	co(res); co(nl);
	r0;
}
