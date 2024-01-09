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
int gcd(int a , int b)
{
    if (b == 0) return a;
    else return gcd(b , a % b);
}
int lcm( int a , int b)
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
    ll n;
    ci(n);
    vl r(n), l(n), c(n);
    for (int i = 0; i < n; ++i)
    {
        ci(l[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        ci(r[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        ci(c[i]);
    }
    sort(rall(c));
    vector<pair<ll, char>> arr;
    for (int i = 0; i < n; ++i)
    {
        arr.push_back({l[i], 'L'});
        arr.push_back({r[i], 'R'});
    }
    sort(all(arr));
    deque<ll> sorting;
    vl v;
    for (auto it : arr)
    {
        if (it.second == 'L')
            sorting.push_back(it.first);
        else
        {
            v.push_back(it.first - sorting.back());
            // co(it.first); co(" "); co(sorting.back()); co(nl);
            sorting.pop_back();
        }
    }
    sort(all(v));
    ll res = 0;
    for (int i = 0; i < n; ++i)
    {
        res += c[i] * v[i];
    }
    co(res); co(nl);
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