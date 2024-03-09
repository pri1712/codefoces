#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
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
int mod = 1e9 + 7;
bool isodd(ll x)
{
    return (x % 2);
}
int gcd(ll a , ll b)
{
    if (b == 0) return a;
    else return gcd(b , a % b);
}
int lcm( ll a , ll b)
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
    ll n;
    ci(n);
    int cursub = 0;
    vi arr(n * n, 0);
    int curseries = 1;
    for (int i = 0; i < n * n; ++i)
    {
        if (isodd(i))
        {
            arr[i] = curseries;
            curseries++;
        }
        else
        {
            arr[i] = n * n - cursub;
            cursub++;
        }
    }
    // for (auto it : arr)
    // {
    //     co(it); co(" ");
    // }
    // co(nl);
    //generated the alternating series
    int res[n][n];
    bool alt = 1; //if 1 go l to r else r to l.
    int cur = 0;
    for (int i = 0; i < n; ++i)
    {
        if (alt)
        {
            int j = 0;
            for (j = 0; j < n ; ++j)
            {
                res[i][j] = arr[cur];
                cur++;
            }
        }
        else
        {
            //go from r to l.
            int j = n - 1;
            for (; j >= 0 ; --j)
            {
                res[i][j] = arr[cur];
                cur++;
            }
        }
        alt = !alt;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n ; ++j)
        {
            co(res[i][j]); co(" ");
        }
        co(nl);
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