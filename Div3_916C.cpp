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
const int MAXI = 100000001;
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
    ll n, k;
    ci(n); ci(k);
    vl initial(n, 0);
    vl addexp(n, 0);
    for (int i = 0; i < n; ++i)
    {
        ci(initial[i]);

    }
    for (int i = 0; i < n; ++i)
    {
        ci(addexp[i]);
    }
    ll res = 0;
    ll addedexpmax = 0;
    ll tot = 0;
    ll j = 0;
    while (j < n && j < k)
    {
        res += initial[j];
        addedexpmax = max(addedexpmax, addexp[j]);
        tot = max(res + (k - j - 1) * addedexpmax, tot);
        j++;
    }
    co(tot); co(nl);
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
        // memset(dp, 0, sizeof(dp));
        solve();
    }
    r0;
}