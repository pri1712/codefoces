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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n;
    ci(n);
    vl arr(n);
    for (int i = 0; i < n; ++i)
    {
        ci(arr[i]);
    }
    string ch;
    ci(ch);
    int j = -1;
    for (int i = 0; i < n; ++i)
    {
        if (ch[i] == '1')
            j = i;
        else
            continue;
    }
    if (j == -1) //no ones in the string
    {
        co(0);
        r0;
    }
    ll res = 0;
    n = j + 1;
    vi prefsum(n + 1);
    for (int i = 1; i <= n; i++)
    {
        prefsum[i] = prefsum[i - 1] + arr[i - 1];
        res += (ch[i - 1] == '1') * arr[i - 1];
    }
    ll cost = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        ll curcost = 0;
        if (ch[i] == '1')
        {
            curcost += cost;
            curcost += prefsum[i];
            res = max(res, curcost);
        }
        if (ch[i] == '1')
        {
            cost += arr[i];
        }
    }
    co(res); co(nl);
    r0;
}