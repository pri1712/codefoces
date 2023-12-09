#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
typedef std::pair<int, int> pp;
typedef long long ll;
typedef std::vector<ll> vl;
typedef std::vector<int> vi;
typedef std::unordered_map<int, int> unmap;
typedef std::unordered_set<int> unset;
typedef std::unordered_set<char> unsetc;
using namespace std;
int n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n;
    ll tot = 0;
    string res = "";
    for (int i = 0; i < n; i++)
    {
        int a, g;
        cin >> a >> g;
        if (tot + a <= 500)
        {
            res += 'A';
            tot += a;
        }
        else
        {
            res += 'G';
            tot -= g;
        }
    }
    cout << res << endl;
}