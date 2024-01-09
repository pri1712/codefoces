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
    set<ll> st;
    vl arr(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        st.insert(i);
    }
    while (m--)
    {
        ll l, r, x;
        ci(l); ci(r); ci(x);
        auto il = st.lower_bound(l); //the element that is just greater than or equal to a.
        if (il == st.end())
            continue;
        auto ir = st.upper_bound(r);
        vl erasing;
        for (auto it = il; it != ir; it++)
        {
            if (*it == x)
                continue;
            else
            {
                erasing.push_back(*it);
                arr[*it] = x;
            }
        }
        for (auto it : erasing)
        {
            st.erase(it);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        co(arr[i]); co(" ");
    }
}