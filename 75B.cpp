#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <sstream>
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

struct strpair
{
    string s; ll x;
};
bool operator<(strpair A, strpair B)
{
    if (A.x < B.x) return true;
    else if (A.x == B.x) return A.s < B.s;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<pair<string, ll>> vp;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string str, name1, name2, name3, action;
    int i, n, j;
    while (cin >> name1 >> n)
    {
        map<string, int>mp;
        map<string, int>::iterator it;
        vector < strpair >vpss;
        for (i = 0; i < n; i++)
        {
            cin >> name2 >> action;
            if (action == "likes") cin >> name3 >> str;
            else cin >> str >> name3 >> str;
            name3 = name3.substr(0, name3.size() - 2);
            if (name1 == name2)
            {
                if (action == "likes") mp[name3] += 5;
                else if (action == "commented") mp[name3] += 10;
                else mp[name3] += 15;
            }
            else if (name1 == name3)
            {
                if (action == "likes") mp[name2] += 5;
                else if (action == "commented") mp[name2] += 10;
                else mp[name2] += 15;
            }
            mp[name2] += 0;
            mp[name3] += 0;
        }
        for (auto it : mp)
        {
            strpair ss;
            ss.s = it.first;
            ss.x = -it.second;
            if (it.first != name1) vpss.push_back(ss);
        }
        sort(all(vpss));
        for (i = 0; i < (int)vpss.size(); i++)
        {
            co(vpss[i].s); co(nl);
        }
    }
    return 0;
}