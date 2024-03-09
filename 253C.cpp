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
typedef long long ll;
typedef std::pair<ll, ll> pp;
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
ll rows = 0;
int dx[4] {1, -1, 0, 0};
int dy[4] {0, 0, 1, -1};
bool ok(ll x, ll y , ll n , ll m) {
    return x >= 0 && y >= 0 && x <= n && y <= m;
}
ll bfs(pp start, pp end, vl arr, ll cols)
{
    queue<pp> q;
    vector<vector<bool>> vis(rows + 1, vector<bool>(cols + 1, false));
    q.push(start);
    ll res = 0;
    while (q.size())
    {
        ll sz = q.size();
        while (sz--)
        {
            ll curx, cury;
            curx = q.front().first; //curx=current row
            cury = q.front().second; //cury=current column
            if (curx == end.first && cury == end.second)
                return res;
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                ll inx, iny;
                inx = curx + dx[i];
                iny = cury + dy[i];
                if (i == 0 || i == 1)
                {
                    iny = min(iny, arr[inx]); //it cant be beyond m at max.
                }
                if (ok(inx, iny, rows, cols) && !vis[inx][iny])
                {
                    vis[inx][iny] = true;
                    q.push({inx, iny});
                }
            }
        }
        res++;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // unordered_map<ll, ll> mp;
    // mp.reserve(1024);
    // mp.max_load_factor(0.25);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ci(rows);
    vl arr(rows);
    ll cols = 0;
    for (int i = 0; i < rows; ++i)
    {
        ci(arr[i]);
        arr[i]++;
        cols = max(cols, arr[i]);
    }
    pp start, end;
    ci(start.first); ci(start.second); ci(end.first); ci(end.second);
    ll res = 0;
    res = bfs(start, end, arr, cols);
    co(res); co(nl);
    r0;

}