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
void solve()
{
    ll n;
    ci(n);
    vl arr(n);
    for (int i = 0; i < n; ++i)
    {
        ci(arr[i]);
    }
    if (n == 1)
    {
        co(0);
        co(nl);
        return;
    }
    sort(all(arr));
    ll mini = arr[0];
    ll maxi = arr[(int)arr.size() - 1];
    vl res;
    while (mini != maxi)//if mini==maxi , all other elements are equal already.
    {
        if (isodd(mini))
        {
            res.push_back(1);
            mini = floor((mini + 1) / 2);
            maxi = floor((maxi + 1) / 2);
        }
        else
        {
            res.push_back(0);
            mini = floor(mini / 2);
            maxi = floor(maxi / 2);
        }
    }
    co((int)res.size()); co(nl);
    if ((int)res.size() <= n)
    {
        for (auto it : res)
        {
            co(it); co(" ");
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