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
// void sieve()
// {
//     for (int i = 2; i * i <= 10000000 ; i++)
//     {
//         if (isprime[i] == 0)
//         {
//             for (int j = 2 * i; j <= (int)isprime.size(); j += i)
//                 isprime[j] = 1;
//         }
//     }
// }
void solve()
{
    // unordered_map<ll, ll> mp;
    // mp.reserve(1024);
    // mp.max_load_factor(0.25);
    //YOU ARE USING 1 BASED INDEXING FOR THIS ONE be fucking careful nvm not anymore.
    ll n; ll m; ll res = 0;
    ci(n);
    vl arr(n);
    for (int i = 0; i < n; ++i)
    {
        ci(arr[i]);
    }
    vector<char> closer(n);
    closer[0] = 'R';//0 can only move L
    closer[n - 1] = 'L';//n-1 can only move R
    for (int i = 1; i <= n - 2; ++i)
    {
        // closer[i].first = i;
        ll curleft = arr[i] - arr[i - 1];
        ll currigt = arr[i + 1] - arr[i];
        if (curleft > currigt)
        {
            closer[i] = 'R';
        }
        else
            closer[i] = 'L';
    }
    vl leftcost(n, 0), rightcost(n, 0);
    leftcost[0] = 0;
    rightcost[n - 1] = 0;
    for (int i = 1; i < n ; ++i)
    {
        if (closer[i] == 'L')
        {
            leftcost[i] = 1 + leftcost[i - 1];
        }
        else
        {
            leftcost[i] = leftcost[i - 1] + (arr[i] - arr[i - 1]);
        }
    }
    for (int i = n - 2; i >= 0; --i)
    {
        if (closer[i] == 'R')
        {
            rightcost[i] = 1 + rightcost[i + 1];
        }
        else
        {
            rightcost[i] = rightcost[i + 1] + (arr[i + 1] - arr[i]);
        }
    }
    ci(m);
    while (m--)
    {
        ll start, end;
        ci(start); ci(end);
        // co(start); co(end); co(nl);
        start--; end--;
        if (start - end > 0) //x>y
        {
            //need to move left to go from start to end
            res = abs(leftcost[start] - leftcost[end]);
        }
        else if (end - start > 0)
        {
            res = abs(rightcost[start] - rightcost[end]);
        }
        else
            res = 0;
        co(res); co(nl);
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