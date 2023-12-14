#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#define ci(n) cin>>n;
#define co(n) cout<<n;
#define nl '\n';
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
void solve()
{
    int a, b;
    int xk, yk;
    int xq, yq;
    ci(a); ci(b);
    ci(xk); ci(yk);
    ci(xq); ci(yq);
    set<pair<int, int>> st ;
    st.insert({a, b});
    st.insert({a, -b});
    st.insert({ -a, b});
    st.insert({ -a, -b});
    std::swap(a, b);
    st.insert({a, b});
    st.insert({a, -b});
    st.insert({ -a, b});
    st.insert({ -a, -b});
    map <pair<int, int>, int> mpk, mpq;
    for (auto it : st)
    {
        mpk[ {it.first + xk, it.second + yk}]++;
        mpq[ {it.first + xq, it.second + yq}]++;
    }
    ll count = 0;
    for (auto [it, x] : mpk)
    {
        if (mpq.count(it))
        {
            count++;
        }
    }
    co(count);
    co(nl;)
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
}