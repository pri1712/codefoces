
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
ll gcd(ll a , ll b)
{
	if (b == 0) return a;
	else return gcd(b , a % b);
}
int lcm( ll a , ll b)
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
// vi isprime(10000000001, 0);
// void sieve()
// {
// 	isprime[0] = 1;
// 	isprime[1] = 1;
// 	for (int i = 2; i * i <= 10000000000 ; i++)
// 	{
// 		if (isprime[i] == 0)
// 		{
// 			for (int j = 2 * i; j <= (int)isprime.size(); j += i)
// 				isprime[j] = 1;
// 		}
// 	}
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
	ll n;
	ci(n);//no of friends
	// get first n primes
	if (n == 2)
	{
		co(-1);
		r0;
	}
	vl arr = {6, 10, 15};
	ll curnum = 20;
	for (int i = 0; i < n - 3; ++i)
	{
		arr.push_back(curnum);
		curnum += 10;
	}
	for (auto it : arr)
	{
		co(it); co(nl);
	}
	// vl firstnprimes;
	// ll count = 0;
	// sieve();
	// for (int i = 2; i < (int)isprime.size() && count < n; i++)
	// {
	// 	if (isprime[i] == 0)
	// 	{
	// 		firstnprimes.push_back(i);
	// 		count++;
	// 	}
	// }
	// ll prod = 1;
	// for (auto it : firstnprimes)
	// {
	// 	// co(it); co(" ");
	// 	prod *= it;
	// }
	// for (int i = 0; i < (int)firstnprimes.size(); ++i)
	// {
	// 	ll cur = firstnprimes[i];
	// 	co(prod / cur); co(nl);
	// }
	r0;
}