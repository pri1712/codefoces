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
void solve()
{
    ll n;
    ci(n);
    vp a(n);
    for (int i = 0; i < n; ++i)
    {
        ci(a[i].first);
        a[i].second = i + 1;
    }
    vp b(n);
    vp c(n);
    for (int i = 0; i < n; ++i)
    {
        ci(b[i].first);
        b[i].second = i + 1;
    }
    for (int i = 0; i < n; ++i)
    {
        ci(c[i].first);
        c[i].second = i + 1;
    }
    sort(rall(a));
    sort(rall(b));
    sort(rall(c));
    ll res = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (a[i].second != b[j].second && a[i].second != c[k].second && b[j].second != c[k].second) {
                    res = max(res, (ll)a[i].first + b[j].first + c[k].first);
                }
            }
        }
    }
    co(res);
    co(nl);
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