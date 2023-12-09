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
    int n, k, l, r, sall, sk;
    cin >> n >> k >> l >> r >> sall >> sk;
    vector<int> res(n);
    int tsk = sall - sk;
    for (int i = 0; i < k; i++)
    {
        res[i] = sk / k;
        if (sk % k != 0)
        {
            res[i]++;
            sk--;
        }
    }
    if (n != k)
    {
        for (int i = k; i < n; i++)
        {
            res[i] = (tsk) / (n - k);
            if (tsk % (n - k) != 0)
            {
                res[i]++;
                tsk--;
            }
        }
    }
    for (auto it : res)
        cout << it << " ";
    return 0;
}