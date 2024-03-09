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
    return (a / gcd(a, b)) * b;
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
    ll n;
    ci(n);
    vl arr(n + 10);
    for (int i = 0; i < n; ++i)
    {
        ci(arr[i]);
    }
    // vl lcmofall;
    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < n ; ++j)
    //     {
    //         if (i == j)
    //             continue;
    //         lcmofall.push_back(lcm(arr[i], arr[j]));
    //     }
    // }
    // if (n == 2)
    // {
    //     co(lcmofall[0]); co(nl);
    //     r0;
    // }
    // ll curgcd = gcd(lcmofall[0], lcmofall[1]);
    // for (int i = 2; i < (int)lcmofall.size(); ++i)
    // {
    //     curgcd = gcd(curgcd, lcmofall[i]);
    // }
    // co(curgcd); co(nl);
    // r0;
    vl rev(n + 10);
    rev[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0 ; --i)
    {
        rev[i] = gcd(arr[i], rev[i + 1]);
    }
    vl res(n + 10);
    for (int i = 0; i < n - 1; ++i)
    {
        res[i] = (arr[i] * rev[i + 1]) / gcd(arr[i], rev[i + 1]);
    }
    ll curgcd = gcd(res[0], res[1]);
    for (int i = 2; i < n - 1; ++i)
    {
        curgcd = gcd(curgcd, res[i]);
    }
    co(curgcd); r0;
}