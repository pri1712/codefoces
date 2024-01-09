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
    ll n;
    ci(n);
    vl semi1v(n, 0);
    vl semi2v(n, 0);
    string semi1(n, '0');
    string semi2(n, '0');
    for (int i = 0; i < n; ++i)
    {
        ll a, b;
        ci(a); ci(b);
        semi1v[i] = a;
        semi2v[i] = b;
    }
    for (int i = 0; i < n / 2; ++i)
    {
        semi1[i] = '1';
        semi2[i] = '1';
    }
    //k=n/2.
    vector<pair<int, pair<int, char>>> tot(2 * n, {0, {0, 0}});
    for (int i = 0; i < n; ++i)
    {
        tot[i] = {semi1v[i], {i, '1'}};
    }
    for (int i = 0; i < n; ++i)
    {
        tot[i + n] = {semi2v[i], {i, '2'}};
    }
    sort(all(tot));
    //k=0.
    for (int i = 0; i < n; i++)
    {
        if (tot[i].second.second == '1')
        {
            semi1[tot[i].second.first] = '1';
        }
        else
        {
            semi2[tot[i].second.first] = '1';
        }
    }
    for (auto it : semi1)
        co(it);
    co(nl);
    for (auto it : semi2)
        co(it);
}