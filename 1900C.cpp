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
void dfs(int node, vector<vector<pair<int, int>>>& adj, vi& dp, string& s )
{
    pp l = adj[node][0];
    pp r = adj[node][1];
    dp[l.first] = dp[node] + l.second;
    dp[r.first] = dp[node] + r.second;
    if (l.first != 0)
    {
        dfs(l.first, adj, dp, s);
    }
    if (r.first != 0)
    {
        dfs(r.first, adj, dp, s);
    }
}
void solve()
{
    ll n;
    ci(n);
    string s;
    ci(s);
    vector<vector<pair<int, int>>> adj(n + 1); //edge,wt
    vi dp(n + 1);
    vector<int> leaf;
    ll ops = LLMAX;
    for (int i = 0; i < n; ++i)
    {
        int l, r;
        ci(l); ci(r);
        if (r == 0 && l == 0)
        {
            leaf.push_back(i + 1);
            adj[i + 1].push_back({l, 1});
            adj[i + 1].push_back({r, 1});
        }
        else
        {
            if (s[i] == 'L')
            {
                adj[i + 1].push_back({l, 0});
            }
            else
            {
                adj[i + 1].push_back({l, 1});
            }
            if (s[i] == 'R')
            {
                adj[i + 1].push_back({r, 0});
            }
            else
            {
                adj[i + 1].push_back({r, 1});
            }
        }
        // co("hi");
    }//weighted tree.
    ll root = 1;
    dfs(root, adj, dp, s);
    // for (auto it : leaf)
    // {
    //     co(it); co(" ");
    // }
    // co(nl);
    for (int i = 0; i < (int)leaf.size(); i++)
    {
        ops = min(ops, (ll)dp[leaf[i]]);
    }
    co(ops);
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