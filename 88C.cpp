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
ll gcd(ll a , ll b)
{
    if (b == 0) return a;
    else return gcd(b , a % b);
}
ll lcm( ll a , ll b)
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
    ll a, b;
    ci(a); ci(b);
    // ll curgcd = gcd(a, b);
    // a /= curgcd;
    // b /= curgcd;
    // if (abs(a - b) == 1)
    // {
    //     co("Equal");
    // }
    // else
    // {
    //     if (a < b)
    //     {
    //         co("Dasha");
    //     }
    //     else
    //     {
    //         co("Masha");
    //     }
    // }
    //above is method 1.
    //method 2:
    ll curlcm = lcm(a, b);
    ll masha = curlcm / b;
    ll dasha = curlcm / a;
    if (abs(masha - dasha) == 1)
    {
        co("Equal");
    }
    else
    {
        if (masha > dasha)
            co("Masha");
        else
            co("Dasha");
    }
    r0;
}