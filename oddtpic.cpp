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
ll modinv(ll a, ll mod)
{
    return a <= 1 ? a : mod - (long long)(mod / a) * modinv(mod % a, mod) % mod;
}
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
const int maxbit = 100005;
bitset<maxbit> cur;
vector<bitset<maxbit>> m(4003);
vector<bitset<maxbit>> s(4003);
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
    ll n, o, q;
    ci(n); ci(o); ci(q);
    for (int i = 0; i < n; ++i)
    {
        ll x;
        ci(x);
        // co(x); co(" ");
        //xth topic on i+1 day.
        m[i + 1].set(x);
    }
    // co(nl);
    for (int i = 0; i < o; ++i)
    {
        ll x;
        ci(x);
        // co(x); co(" ");
        //xth topic on i+1 day.
        s[i + 1].set(x);
    }
    while (q--)
    {
        ll l1, r1, l2, r2;
        ci(l1); ci(r1); ci(l2); ci(r2);
        cur = m[l1];
        for (int i = l1 + 1; i <= r1 ; ++i)
        {
            cur ^= m[i];
        }
        for (int i = l2; i <= r2 ; ++i)
        {
            cur ^= s[i];
        }
        ll res = cur.count();
        co(res); co(nl);
        cur.reset();
    }
    m.clear(); s.clear();
    r0;
}