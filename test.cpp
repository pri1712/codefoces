#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#define ci(n) cin>>n;
#define nl '\n';
#define co(n) cout<<n;
#define LLMAX LLONG_MAX;
typedef std::pair<int, int> pp;
typedef long long ll;
typedef std::vector<ll> vl;
typedef std::vector<int> vi;
typedef std::unordered_map<int, int> unmap;
typedef std::unordered_set<int> unset;
typedef std::unordered_set<char> unsetc;
using namespace std;
int nb, ns, nc;
int pb, ps, pc;
long long r;
int cb, cs, cc;
long long ans;
char str[105];
int mod = 1e9 + 7;
int gcd(int a , int b)
{
    if (b == 0) return a;
    else return gcd(b , a % b);
}
bool isprime(ll n)
{
    if (n <= 1)
        return false;
    else
    {
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
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
    if (999983 < 1e6)
    {
        co("ye");
    }
}