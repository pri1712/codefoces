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
void solve()
{
    ll n, p;
    ci(n); ci(p);
    ll count = 0;
    set<pair<int, int>> st;
    for (int i = 1; i <= n ; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i == j || st.find({i, j}) != st.end() || st.find({j, i}) != st.end())
                continue;
            if (count >= 2 * n)
                break;
            st.insert({i, j});
            count++;
        }
    }
    for (int i = 1; i <= n ; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i == j || st.find({i, j}) != st.end() || st.find({j, i}) != st.end())
                continue;
            if (count >= 2 * n + p)
                break;
            st.insert({i, j});
            count++;
        }
    }
    for (auto it : st)
    {
        co(it.first); co(" "); co(it.second);
        co(nl);
    }
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