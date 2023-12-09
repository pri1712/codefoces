#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#define ci(n) cin>>n;
typedef std::pair<int, int> pp;
typedef long long ll;
typedef std::vector<ll> vl;
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
    int n;
    ci(n);
    if (n % 2 == 0)
    {
        cout << -1 << endl;
        return 0;
    }
    vl a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
        b[i] = i;
    }
    for (auto it : a)
    {
        cout << it << " ";
    }
    cout << endl;
    for (auto it : b)
    {
        cout << it << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        c[i] = (a[i] + b[i]) % n;
    }
    for (auto it : c)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}