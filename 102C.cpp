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
    string s;
    ll k;
    ci(s);
    ci(k);
    unordered_map <char, int> mp;
    for (auto c : s)
        mp[c]++;
    vector<pair<int, char>> arr;
    for (auto it : mp)
        arr.push_back({it.second, it.first});
    sort(all(arr));
    for (int i = 0; i < (int)arr.size(); ++i)
    {
        if (k == 0)
            break;
        ll curfreq = arr[i].first;
        ll curmini = min(k, curfreq);
        arr[i].first -= curmini;
        k -= curmini;
    }
    for (auto it : arr)
    {
        mp[it.second] = it.first;
    }
    ll res = 0;
    // for (auto it : mp)
    // {
    //     co(it.first); co(":"); co(it.second);
    //}
    for (auto it : mp)
    {
        if (it.second)
            res++;
    }
    co(res);
    co(nl);
    // for (auto it : mp)
    // {
    //     while (it.second)
    //     {
    //         co(it.first);
    //         it.second--;
    //     }
    // }
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (mp[s[i]])
        {
            co(s[i]);
            mp[s[i]]--;
        }
    }
    r0;
}