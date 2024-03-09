#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#define ci(n) cin>>n
#define co(n) cout<<n
#define nl '\n'
#define LLMAX LLONG_MAX
#define IMAX INT_MAX
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
vector<int> adj[200010];
vi vis(200010, 0);
int v_entry; //marcels entry into the cycle.
bool entrydfs(int x, int p)
{
    vis[x] = true;
    for (auto it : adj[x])
    {
        if (vis[it] && it != p)
        {
            v_entry = it;
            return true;
        }
        else if (!vis[it] && it != p)
        {
            if (entrydfs(it, x))
                return true;
        }
    }
    return false;
}
int shortestdist(int x)
{
    vis[x] = true;
    int len = 200001;
    for (auto it : adj[x])
    {
        if (it == v_entry)
        {
            return 1;
        }
        if (!vis[it])
        {
            int curdist = shortestdist(it) + 1;
            len = min(len, curdist);
        }
    }
    return len;
}
void solve()
{
    ll n, m, v;
    ci(n); ci(m); ci(v);
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        ci(a); ci(b);
        adj[a].push_back(b);
        adj[b].push_back(a);//making the adj list
    }
    v_entry = -1;//reassignning
    int mdist = 0, vdist = 0;
    //find the entry node
    entrydfs(v, -1);//finding the entry of m.
    vis.assign(n + 1, 0);
    //marcels case
    if (v_entry == m)
    {
        mdist = 0;
    }
    else
    {
        mdist = shortestdist(m);
    }
    vis.assign(n + 1, false);
    if (v_entry == v)
    {
        vdist = 0;
    }
    else
    {
        vdist = shortestdist(v);
    }
    if (vdist < mdist)
    {
        co("yes"); co(nl);
    }
    else
    {
        co("no"); co(nl);
    }
    for (int i = 0; i <= n ; ++i)
    {
        adj[i].clear();
        vis[i] = false;
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