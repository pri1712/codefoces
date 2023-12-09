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
    vl arr(n + 1);
    ll maxi = -1;
    int ind = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if (arr[i] > maxi)
        {
            maxi = arr[i];
            ind = i;
        }
    }
    ll scmaxi = -1;
    int scind = 0;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == maxi)
            continue;
        if (arr[i] > scmaxi)
        {
            scmaxi = arr[i];
            scind = i;
        }
    }
    // cout << scmaxi << " " << ind - scind << endl;
    ll res = maxi;
    if (scind > ind)
    {
        //second max lies to the righgt.
        int j = ind + 1;
        while (j >= 1)
        {
            res++;
            j--;
            //res++;
        }
        res += abs(ind - scind - 1);
        cout << res << endl;
    }
    else
    {
        int j = ind + 1;
        while (j <= n)
        {
            j++;
            res++;
            //cout << res << endl;
            //j++;
            //res++;
        }
        res += abs(ind - scind - 1);
        cout << res << endl;
    }
    return 0;
}