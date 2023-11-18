#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
typedef long long ll;
typedef std::vector<ll> vl;
typedef std::vector<int> vi;
typedef std::unordered_map<int, int> unmap;
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
    string s;
    cin >> s;
    int len = (int)s.size();
    ll sum = 0, res;
    int count = 0;
    res = (1 << len) - 2;
    for (ll i = (int)s.size() - 1 ; i >= 0; i--, count++)
    {
        if (s[i] == '7')
        {
            sum += (1 << count);
        }
    }
    cout << res + sum + 1 << endl;
    return 0;
}