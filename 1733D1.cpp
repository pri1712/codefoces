#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#define ci(n) cin>>n
#define co(n) cout<<n
#define nl '\n'
#define LLMAX LLONG_MAX
#define r0 return 0
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define printstr(s) for(int i=0;i<(int)s.size();i++) { cout<<s[i];}
typedef std::pair<int, int> pp;
typedef long long ll;
typedef std::vector<ll> vl;
typedef std::vector<std::pair<int, int>> vp;
typedef std::vector<int> vi;
using namespace std;
ll extendedeuclidalgo(ll a, ll b, ll& x, ll& y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = extendedeuclidalgo(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
bool isodd(ll x)
{
    return (x % 2);
}
ll gcd(ll a , ll b)
{
    if (b == 0) return a;
    else return gcd(b , a % b);
}
ll lcm( ll a , ll b)
{
    return a * b / gcd(a, b);
}
ll modpow(ll x, ll n, ll m)
{
    if (n == 0) return 1 % m;
    long long u = modpow(x, n / 2, m);
    u = (u * u) % m;
    if (n % 2 == 1) u = (u * x) % m;
    return u;
}
ll modinv(ll a, ll mod)
{
    return a <= 1 ? a : mod - (long long)(mod / a) * modinv(mod % a, mod) % mod;
}
// void sieve()
// {
//     for (int i = 2; i * i <= 10000000 ; i++)
//     {
//         if (isprime[i] == 0)
//         {
//             for (int j = 2 * i; j <= (int)isprime.size(); j += i)
//                 isprime[j] = 1;
//         }
//     }
// }
void solve()
{
    // unordered_map<ll, ll> mp;
    // mp.reserve(1024);
    // mp.max_load_factor(0.25);
    ll n, x, y;
    ci(n); ci(x); ci(y);
    string a, b;
    ci(a); ci(b);
    if (a == b)
    {
        co(0); co(nl);
        return;
    }
    string xorres = ""; ll count = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == b[i])
            xorres.push_back('0');
        else
        {
            xorres.push_back('1');
            count++;
        }
    }
    // printstr(xorres); co(nl);
    if (isodd(count))
    {
        co(-1); co(nl);
        return;
    }
    if (count > 2)
    {
        ll res = (count) * y / 2;
        co(res); co(nl);
        return;
    }
    else
    {
        int pos1 = -1, pos2 = -1;
        for (int i = 0; i < n ; ++i)
        {
            if (xorres[i] == '1')
            {
                pos2 = i;
                if (pos1 == -1)
                    pos1 = i;
            }
        }
        // co(pos1); co(" "); co(pos2);
        if (pos2 == pos1 + 1)
        {
            ll res = min(x, 2 * y);
            co(res); co(nl);
            return;
        }
        else
        {
            co(y); co(nl);
        }
    }
    return;
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
    int t;
    ci(t);
    while (t--)
    {
        solve();
    }
    r0;
}