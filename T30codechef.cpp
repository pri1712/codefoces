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
const int max_size = 100005;
vector<bitset<1005>> b(max_size);//matrix of bitsets.
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
    ll n, q;
    ci(n); ci(q);
    for (int i = 1; i <= n; ++i)
    {
        ll k;
        ci(k);
        for (int j = 0; j < k; ++j)
        {
            ll item; ci(item);
            b[i].set(item);//in stock.
        }
    }
    while (q--)
    {
        int curquery;
        ci(curquery);
        // co(curquery); co(nl);
        if (curquery == 1) //have to replace items in a shop
        {
            ll shop; ci(shop);
            ll k;
            ci(k);
            // const int curk = k;
            bitset < 1005> items;
            items.reset();
            for (int i = 0; i < k; ++i)
            {
                int x; ci(x);
                items[x] = 1;
                b[shop] &= items;//the common ones will stay 1.
                //others will become 0.
            }
        }
        else
        {
            ll l, r; ci(l); ci(r);
            ll k; ci(k);
            bitset < 1005> items;
            items.reset();
            for (int i = 0; i < k ; ++i)
            {
                int x; ci(x);
                items[x] = 1;//items he is willing to sell. the shopkeepers
                //will buy only if their intersection with the chef is 0.
                //that is , no common items
            }
            bitset<1005> cur;
            cur.reset();
            ll res = 0;
            for (int i = l; i <= r; ++i)
            {
                cur = b[i];//each shop is b[i].
                cur &= items;
                if (cur.count() == 0)
                {
                    res++;
                }
                cur.reset();
            }
            co(res); co(nl);
        }
    }
    r0;
}