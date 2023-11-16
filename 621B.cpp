#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
typedef long long ll;
typedef std::vector<ll> vl;
typedef std::vector<int> vi;
//#include <map>
using namespace std;
int n;
const int maxi = 200000;
int freq[maxi][2];
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
    unordered_map<ll, ll> sum;
    unordered_map<ll, ll> diff;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        sum[x + y]++;
        diff[x - y]++;
    }
    ll count = 0;
    for (auto it : sum)
    {
        count += ((it.second - 1) * (it.second) / 2);
    }

    for (auto it : diff)
    {
        count += ((it.second - 1) * (it.second) / 2);
    }
    cout << count << endl;
    return 0;
}