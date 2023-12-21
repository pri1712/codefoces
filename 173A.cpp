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
int gcd(int a , int b)
{
    if (b == 0) return a;
    else return gcd(b , a % b);
}
int lcm( int a , int b)
{
    return a * b / gcd(a, b);
}
//a is Ni and b is Po.
bool niloss(char a, char b)
{
    if ((a == 'R' && b == 'P' ) || (a == 'P' && b == 'S') || (a == 'S' && b == 'R'))
        return true;
    return false;
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
    string sn;
    string sp;
    ci(sn); ci(sp);
    int m = (int)sn.size(); int k = (int)sp.size();
    int mk = lcm(m, k);
    ll N = 0, P = 0, NL = 0, PL = 0;
    // co(mk);
    for (int i = 0 ; i < mk ; i++)
    {
        if (sn[i % m] == 'R')
        {
            if (sp[i % k] == 'S') P++;
            if (sp[i % k] == 'P') N++;
        }
        if (sn[i % m] == 'S')
        {
            if (sp[i % k] == 'P') P++;
            if (sp[i % k] == 'R') N++;
        }
        if (sn[i % m] == 'P')
        {
            if (sp[i % k] == 'R') P++;
            if (sp[i % k] == 'S') N++;
        }
        if ( i == (n - 1) % mk )
        {
            NL = N;
            PL = P;
        }
    }
    ll nres = N * ((n - 1) / (mk)) + NL; ll pres = P * ((n - 1) / mk) + PL;
    co(nres); co(" "); co(pres);
    r0;

}