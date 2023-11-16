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
    int n, m;
    cin >> n >> m;
    int a[n][m];
    int b[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> b[i][j];
            a[i][j] = 1;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; j++)
        {
            if (b[i][j] == 0)
            {
                for (int k = 0; k < m; k++)
                {
                    a[i][k] = 0; //same cols 0
                }
                for (int k = 0; k < n; k++)
                    a[k][j] = 0; //making same rows 0
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            bool y = 0;
            for (int k = 0; k < m; k++)
            {
                y |= a[i][k];
            }
            for (int k = 0; k < n; k++)
            {
                y |= a[k][j]; //same cols 0
            }
            if (y != b[i][j])
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j == m - 1)
            {
                cout << a[i][j] << endl;
            }
            else
                cout << a[i][j] << " ";
            //a[i][j] = 1;
        }
    }
    return 0;


}