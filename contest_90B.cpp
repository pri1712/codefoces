#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
//#include <map>
using namespace std;
typedef long long ll;
const int maxi = 100;
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> res(n, 1);
    vector<vector<int>> idx (maxi + 1);
    for (int i = 0; i < n; i++)
    {
        idx[arr[i]].push_back(i); //storing the indexes of the elements
    }
    int k = 2;
    for (int num = 1; num <= maxi; num++)
    {
        if (idx[num].size() >= 2)
        {
            //more than 2 elements of this type.
            res[idx[num][0]] = k;
            k++;
            if (k > 3)
                break ; //only 2 and 3 needed in the condition 1 and 2
        }
    }
    if (k <= 3)
    {
        cout << -1 << endl;
    }
    else
    {
        for (auto it : res)
            cout << it << " ";
        cout << endl;
    }
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
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;

}