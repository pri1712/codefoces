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
    string s = "#";
    ll n; ci(n);
    ll p; ci(p);
    for (int i = 1; i <= n; ++i)
    {
        char c;
        ci(c);
        s += c;
    }
    //1 indexed
    if (p > n / 2)
    {
        p = n - p + 1;
    }
    vl diff(n + 1);
    diff[0] = -1;
    ll res = 0;
    for (int i = 1; i <= n / 2 ; ++i)
    {
        diff[i] = min(abs(s[i] - s[n - i + 1]), 26 - abs(s[i] - s[n - i + 1]));
        res += diff[i];
    }
    ll l = 1, r = n / 2;
    while (l <= n / 2 && diff[l] == 0)
    {
        l++;//finding first different
    }
    while (r >= 1 && diff[r] == 0)
    {
        r--;//finding last different
    }
    if (l <= r)
    {
        if (p <= l)
        {
            res += r - p; //has to go till r at least.
        }
        else if (p >= r)
        {
            res += p - l;
        }
        else
        {
            res += min(r - p, p - l) + (r - l);
        }
    }
    co(res); co(nl);
    r0;


}