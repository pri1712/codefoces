#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;
typedef vector<pair<ll, ll>> vpl;
typedef unordered_map<int, int> unmap;
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
    int d;
    cin >> n >> d;
    vpl arr(n);
    for (int i = 0; i < n; i++)
    {
        //money , friendship factor
        cin >> arr[i].ff >> arr[i].ss;
    }
    sort(all(arr));
    int i = 0;
    int j = 0;
    ll maxi = 0;
    ll cur = 0;
    for (auto it : arr)
    {
        maxi = max(maxi, it.ss);
    }
    while (j < (int)arr.size())
    {
        if (abs(arr[j].ff - arr[i].ff) < d)//max in the array - min in the array.
        {
            cur += arr[j].ss;
            j++;
            maxi = max(maxi, cur);
        }
        else
        {
            maxi = max(maxi, cur);
            cur -= arr[i].ss;
            i++;
        }
    }
    cout << maxi << endl;
    return 0;
}