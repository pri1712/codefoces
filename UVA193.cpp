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
vector<vector<int>> adj;
std::bitset <110> coloredprev;
vi colorofnode(110, 0);
ll res;
ll n, tot;
vl arr;
void trav(ll node)
{
    if (node > n)
    {
        ll b = 0, w = 0;
        for (int i = 0; i <= n; ++i)
        {
            if (colorofnode[i])
                b++;
            else
                w++;
        }
        if (b > res)
        {
            res = b;
            arr.clear();
            for (int i = 1; i <= n ; ++i)
            {
                if (colorofnode[i])
                    arr.push_back(i);
            }
        }
        return;
    }
    bool blk = true;
    for (int i = 0; i < (int) adj[node].size(); i++) {
        int v = adj[node][i];
        if (coloredprev[v] && colorofnode[v]) {
            blk = false;
            break;
        }
    }
    coloredprev.set(node);
    if (blk)
    {
        colorofnode[node] = 1;
        trav(node + 1);
    }

    colorofnode[node] = 0;
    trav(node + 1);
    coloredprev.reset(node);
}
void solve()
{
    ci(n);
    ci(tot);
    adj.assign(n + 1, vector<int>());
    coloredprev.reset();
    res = -1;
    for (int i = 0; i < tot; ++i)
    {
        ll u, v;
        ci(u); ci(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    trav(1);
    co(res);
    co(nl);
    for (int i = 0; i < (int)arr.size() - 1 ; ++i)
    {
        co(arr[i]); co(" ");
    }
    co(arr[(int)arr.size() - 1]);
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
    // co(t);
    while (t--)
    {
        solve();
    }
    r0;
}