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
    ll n;
    ci(n);
    vl l(n);
    vl r(n);
    vl wt(n);
    for (int i = 0; i < n; i++) ci(l[i]);
    for (int i = 0; i < n; i++) ci(r[i]);
    for (int i = 0; i < n; i++) ci(wt[i]);
    vl arr;
    vp v;
    for (int i = 0; i < n; i++) {
        v.push_back({l[i], 0});
        v.push_back({r[i], 1});
    }
    vi sorting;
    sort(wt.begin(), wt.end(), greater<int>());
    sort(v.begin(), v.end());
    for (auto it : v) {
        if (it.second == 0) sorting.push_back(it.first);
        else {
            arr.push_back((it.first - sorting.back()));
            sorting.pop_back();
        }
    }
    sort(arr.begin(), arr.end());
    ll res = 0;
    for (int i = 0; i < n; i++)
        res += (arr[i] * wt[i]);
    co(res);
    co(nl;)
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