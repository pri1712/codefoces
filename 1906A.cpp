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
ll gcd(ll a , ll b)
{
    if (b == 0) return a;
    else return gcd(b , a % b);
}
int lcm( ll a , ll b)
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
// void sieve()
// {
//    for (int i = 2; i * i <= 10000000 ; i++)
//    {
//        if (isprime[i] == 0)
//        {
//            for (int j = 2 * i; j <= (int)isprime.size(); j += i)
//                isprime[j] = 1;
//        }
//    }
// }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // unordered_map<ll, ll> mp;
    // mp.reserve(1024);
    // mp.max_load_factor(0.25);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<vector<char>> arr(3, vector<char>(3));
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            ci(arr[i][j]);
        }
    }
    string res = "CCC";
    for (int r1 = 0; r1 < 3; ++r1)
    {
        for (int r2 = 0; r2 < 3; ++r2)
        {
            for (int r3 = 0; r3 < 3; ++r3)
            {
                for (int c1 = 0; c1 < 3; ++c1)
                {
                    for (int c2 = 0; c2 < 3; ++c2)
                    {
                        for (int c3 = 0; c3 < 3; ++c3)
                        {
                            if ((r1 != r2 || c1 != c2) && (r1 != r3 || c1 != c3) && (r2 != r3 || c2 != c3))
                            {
                                if (abs(r1 - r2) <= 1 && abs(r2 - r3) <= 1 && abs(c1 - c2) <= 1 && abs(c2 - c3) <= 1)
                                {
                                    string cur = "";
                                    cur += arr[r1][c1]; cur += arr[r2][c2]; cur += arr[r3][c3];
                                    if (cur < res)
                                    {
                                        res = cur;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printstr(res); co(nl);
    r0;
}