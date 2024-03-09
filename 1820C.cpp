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
typedef std::unordered_map<int, int> unmap;
typedef std::unordered_set<int> unset;
typedef std::unordered_set<char> unsetc;
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
    ll n; ci(n);
    vl arr(n);
    unordered_set<ll> st;
    for (int i = 0; i < n; ++i)
    {
        ci(arr[i]);
        st.insert(arr[i]);
    }
    ll inmex = 0;
    while (st.find(inmex) != st.end())
        inmex++;
    // co(inmex); co(nl);
    bool ok = true;
    if (inmex == n)
    {
        co("no"); co(nl);
        return;
    }
    else if (st.find(inmex + 1) == st.end())
    {
        co("yes"); co(nl);
        return;
    }

    else
    {
        int startidx = 0, endidx = n - 1;
        for (int i = 0; i < n; ++i)
        {
            if (arr[i] == inmex + 1)
            {
                startidx = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; --i)
        {
            if (arr[i] == inmex + 1)
            {
                endidx = i;
                break;
            }
        }
        for (int i = startidx; i <= endidx; ++i)
        {
            arr[i] = inmex;
        }
        unordered_set<ll> st2;
        for (int i = 0; i < n; ++i)
        {
            st2.insert(arr[i]);
        }
        ll finmex = 0;
        while (st2.find(finmex) != st2.end())
            finmex++;
        if (finmex - 1 == inmex)
        {
            ok = true;
        }
        else
            ok = false;
        // co(startidx); co(" "); co(endidx);

    }
    if (ok)
        co("yes");
    else
        co("no");
    co(nl);
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