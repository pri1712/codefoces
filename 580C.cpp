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
bool isleafnode(ll node, vector<vector<int>>& adj)
{
    // co(node); co(nl);
    return (adj[node].size() == 1);
}
int dfs(ll node, ll parent, vector<vector<int>>& adj, vi& cat, ll k, ll& m)
{
    if (cat[node] == 1)
    {
        k++;
        if (k > m)
            return 0;
    }
    else
        k = 0;
    if (isleafnode(node, adj) && parent != -1)
    {
        return 1;
    }
    ll res = 0;
    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        else
            res += dfs(it, node, adj, cat, k,  m);
    }
    return res;
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
    ll n, m;
    ci(n); ci(m);
    vi cat(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        ci(cat[i]);
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i)
    {
        ll x, y;
        ci(x); ci(y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    ll root = 1;
    ll k = 0;
    co(dfs(root, -1, adj, cat, k, m));
}