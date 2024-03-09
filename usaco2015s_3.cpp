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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // unordered_map<ll, ll> mp;
    // mp.reserve(1024);
    // mp.max_load_factor(0.25);
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    ll n, q;
    ci(n); ci(q);
    vl id1(n + 1), id2(n + 1), id3(n + 1);
    ll c1 = 0, c2 = 0, c3 = 0;
    vl arr(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        ci(arr[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (arr[i] == 1)
        {
            c1++;
        }
        else if (arr[i] == 2)
            c2++;
        else
            c3++;
        id1[i] = c1, id2[i] = c2, id3[i] = c3;
    }

    while (q--)
    {
        ll a, b;
        ci(a); ci(b);
        // a--, b--;
        co(id1[b] - id1[a - 1]); co(" ");
        co(id2[b] - id2[a - 1]); co(" ");
        co(id3[b] - id3[a - 1]); co(" ");
        co(nl);
    }
}