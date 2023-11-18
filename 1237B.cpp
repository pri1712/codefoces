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
    cin >> n;
    vi enter(n + 1, 0);
    vi exit(n + 1, 0);
    vi t(n + 1, 0);
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> enter[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> exit[i];
        t[exit[i]] = i;
    }
    vi c(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        c[i] = t[enter[i]]; //extracting times for each car.
    }
    //unset overtake;
    int maxi = -1;
    for (int i = 1; i <= n; i++)
    {
        if (c[i] > maxi)
            maxi = c[i];
        else
            count++;
    }
    cout << count << endl;
    return 0;
}