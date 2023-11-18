#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
typedef long long ll;
typedef std::vector<ll> vl;
typedef std::vector<int> vi;
typedef std::unordered_map<int, int> unmap;
typedef std::unordered_set<int> unset;
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
    ll l, r;
    cin >> l >> r;
    cout << "YES" << endl;
    for (ll i = 0; i < (r - l + 1) / 2; i++)
    {
        ll fr = (l + i + i);
        ll sc = (l + i + i + 1);
        cout << fr << " " << sc << endl;
    }
    return 0;
}