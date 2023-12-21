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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll m;
    ci(m);
    vl numbers(30, 0);
    while (m--)
    {
        ll op, v;
        ci(op); ci(v);
        // co(op); co(" "); co(v);
        if (op == 1)
        {
            numbers[v]++;
        }
        else
        {
            bool present = true;
            vl temp = numbers;
            ll k = 0;
            while (v > 0)
            {
                ll need = 1;
                ll w = k;
                if (isodd(v))
                {
                    while (need != 0 && w >= 0)
                    {
                        if (temp[w] >= need)
                        {
                            temp[w] -= need;
                            need = 0;
                            break;
                        }
                        else
                        {
                            need -= temp[w];
                            temp[w] = 0;
                            w--;
                            need <<= 1;
                        }
                    }
                    if (need != 0)
                    {
                        present = false;
                    }
                }
                v >>= 1;
                k++;
            }
            if (present)
            {
                co("YES"); co(nl);
            }
            else
            {
                co("NO"); co(nl);
            }
        }
    }
}
