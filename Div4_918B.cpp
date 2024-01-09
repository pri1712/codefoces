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
void solve()
{
    // unordered_map<ll, ll> mp;
    // mp.reserve(1024);
    // mp.max_load_factor(0.25);
    char arr[3][3];
    int qi = 0, qj = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3 ; ++j)
        {
            ci(arr[i][j]);
            if (arr[i][j] == '?')
            {
                qi = i;
                qj = j;
            }
        }
    }
    ll a = 0, b = 0, c = 0;
    for (int k = 0; k < 3; ++k)
    {
        if (arr[qi][k] == 'A')
            a++;
        else if (arr[qi][k] == 'B')
            b++;
        else if (arr[qi][k] == 'C')
            c++;
    }
    if (a == 0)
    {
        co("A");
        co(nl);
    }
    else if (b == 0)
    {
        co("B");
        co(nl);
    }
    else
    {
        co("C");
        co(nl);
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