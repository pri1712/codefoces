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
    ll h, w, xa, xb, ya, yb;
    ci(h); ci(w); ci(xa); ci(ya); ci(xb); ci(yb);
    if (xa >= xb)
    {
        co("draw"); co(nl);
        return;
    }
    ll dist = xb - xa;
    string winner = "";
    bool win = true;
    if (isodd(dist))
    {
        //alice wins or its a draw.
        if (yb > ya) {
            int yya = min(ya + dist / 2 + 1     , w);
            int yyb = min(yb + dist / 2 , w);
            if (yya >= yyb) {
                cout << "Alice" << endl;
                return ;
            }
            else {
                cout << "Draw" << endl;
                return;
            }
        }
        else {
            int yya = max(ya - dist / 2 - 1 , 1ll);
            int yyb = max(yb - dist / 2 , 1ll);
            if (yya <= yyb) {
                cout << "Alice" << endl;
                return ;
            }
            else {
                cout << "Draw" << endl;
                return;
            }
        }
    }
    else
    {
        //bob wins or its a draw
        winner = "bob";
        if (ya > yb) {
            int yya = min(ya + dist / 2 , w);
            int yyb = min(yb + dist / 2 , w);
            if (yya <= yyb) {
                cout << "Bob" << endl;
                return ;
            }
            else {
                cout << "Draw" << endl;
                return;
            }
        }
        else {
            int yya = max(ya - dist / 2, 1ll);
            int yyb = max(yb - dist / 2 , 1ll);
            if (yya >= yyb) {
                cout << "Bob" << endl;
                return ;
            }
            else {
                cout << "Draw" << endl;
                return;
            }
        }
    }
    if (win)
    {
        printstr(winner); co(nl);
    }
    else
    {
        co("draw"); co(nl);
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