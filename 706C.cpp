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
    ll n;
    ci(n);
    vector<string> orig(n), rev(n);
    vl energy(n);
    for (int i = 0; i < n; ++i)
    {
        ci(energy[i]);
    }
    ll dp[n][2]; //2 states , rev or not rev.
    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //         co(dp[i][j]); co(" ");
    //     }
    //     co(nl);
    // }
    for (int i = 0; i < n; ++i)
    {
        ci(orig[i]);
        rev[i] = orig[i];
        reverse(all(rev[i]));
        dp[i][0] = 1e15; dp[i][1] = 1e15;
    }
    dp[0][0] = 0;
    dp[0][1] = energy[0];
    ll res = 1e15;
    for (int i = 1; i < n; ++i)
    {
        //cond for not rev.
        if (orig[i - 1] <= orig[i])
            dp[i][0] = dp[i - 1][0];

        if (orig[i] >= rev[i - 1])
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);

        //reverse COND
        if (rev[i] >= orig[i - 1])
            dp[i][1] = dp[i - 1][0] + energy[i];

        if (rev[i] >= rev[i - 1])
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + energy[i]);
    }
    res = min(dp[n - 1][0], dp[n - 1][1]);
    if (res == 1e15)
    {
        co(-1);
    }
    else
        co(res);
    co(nl);
    r0;
}