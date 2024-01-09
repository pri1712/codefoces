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
    vector<long long> prime(20000002, 1);
    for (int i = 2; i <= 20000000; ++i)
    {
        if (prime[i])
        {
            //number is a prime.
            for (int j = 2 * i; j <= 20000000; j += i)
            {
                prime[j] = 0;
            }
        }
    }
    map<long long, pair<int, int>> mp;
    ll cnt = 1;
    for (int i = 3; i <= 20000000 - 2; i++)
    {
        if (prime[i] == 1 && prime[i + 2] == 1)
        {
            mp[cnt] = make_pair(i, i + 2);
            cnt++;
        }
    }
    long long s;
    while (cin >> s)
    {
        cout << mp[s].first << " " << mp[s].second << '\n';
    }
    return 0;
}