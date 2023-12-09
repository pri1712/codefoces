#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#define ci(n) cin>>n;
#define nl '\n';
typedef std::pair<int, int> pp;
typedef long long ll;
typedef std::vector<ll> vl;
typedef std::vector<int> vi;
typedef std::unordered_map<int, int> unmap;
typedef std::unordered_set<int> unset;
typedef std::unordered_set<char> unsetc;
using namespace std;
int mod = 1e9 + 7;
bool ok(int tot, int dignum)
{
    if (tot >= 0 && tot <= 9 * dignum)
    {
        return true;
    }
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
    string mini, maxi;
    int m, s;
    ci(m);
    ci(s);
    if (s == 0 && m >= 2)
    {
        cout << -1 << " " << -1 << nl;
        return 0;
    }
    if (s == 0)
    {
        if (m == 1)
        {
            cout << 0 << " " << 0 << nl;
            return 0;
        }
        else
        {
            cout << -1 << " " << -1 << nl;
            return 0;
        }
    }
    if (s > 9 * m)
    {
        cout << -1 << " " << -1 << nl;
        return 0;
    }
    for (int i = 0; i < m; i++)
    {
        int cur = min(s, 9); //if s>9 put 9 as want max.
        s -= cur;
        maxi += (cur + '0');
    }
    if (s > 0)
    {
        cout << -1 << " " << -1 << nl;
        return 0;
    }
    //got the maxi string.
    for (int i = m - 1; i >= 0; i--)
    {
        mini += maxi[i];
    }
    int i;
    for (i = 0; mini[i] == '0'; i++);

    mini[i]--, mini[0]++;
    //cout << a << " " << b << endl;
    cout << mini << " " << maxi << nl;
    return 0;
}