#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
//#include <map>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    vector<vector<char>> sea (n, std::vector<char> (n, '#'));
    if (ceil(pow(n, 2) / 2) < k)
    {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i + j) % 2 == 0 && k > 0) //even indices
            {
                sea[i][j] = 'L';
                k--;

            }
            else
                sea[i][j] = 'S';

        }
    }
    if (k != 0)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == n - 1)
                {
                    cout << sea[i][j] << endl;
                }
                else
                    cout << sea[i][j];
            }
        }
    }
    return 0;
}