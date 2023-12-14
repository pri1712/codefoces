#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#define ci(n) cin>>n;
#define co(n) cout<<n;
#define nl '\n';
#define r0 return 0;
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int bcount = 0;
    int scount = 0;
    int ccount = 0;
    string s;
    ci(s);
    for (auto it : s)
    {
        if (it == 'B')
            bcount++;
        else if (it == 'S')
            scount++;
        else if (it == 'C')
            ccount++;
    }
    // co(bcount);
    // co(scount);
    // co(ccount);
    ll nb, ns, nc;
    ci(nb);
    ci(ns);
    ci(nc);
    ll pb, ps, pc;
    ci(pb);
    ci(ps);
    ci(pc);
    ll r;
    ci(r);
    ll count = 0;
    if (bcount == 0)
        nb = 0;
    if (scount == 0)
        ns = 0;
    if (ccount == 0)
        nc = 0;
    //need t0 maximize the number of burgers.
    while (nb || ns || nc)
    {
        if (nb < bcount)
        {
            r -= pb * (bcount - nb);
            nb = bcount;
        }
        if (ns < scount)
        {
            r -= ps * (scount - ns);
            ns = scount;
        }
        if (nc < ccount)
        {
            r -= pc * (ccount - nc);
            nc = ccount;
        }
        if (r < 0)
            break;
        else
        {
            nb -= bcount;
            nc -= ccount;
            ns -= scount;
            count++;
        }
    }
    if (r > 0)count += r / (bcount * pb + scount * ps + ccount * pc);
    co(count);
    co(nl;)
    r0;
}