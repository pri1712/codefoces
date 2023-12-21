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
    int n, m;
    ci(n); ci(m);
    //the middle node cant be in the M nodes bw which no road.
    unset st;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        ci(x); ci(y);
        st.insert(x); st.insert(y);
    }
    int centre = -1;
    for (int i = 1; i <= n; ++i)
    {
        if (st.find(i) == st.end())
        {
            centre = i;
            break;
        }
    }
    co(n - 1); co(nl);
    for (int i = 1; i <= n; ++i)
    {
        if (i == centre)
        {
            continue;
        }
        co(centre); co(" "); co(i);
        co(nl);
    }
    r0;
}