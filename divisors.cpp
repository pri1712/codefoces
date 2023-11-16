#include <bits/stdc++.h>
#include <algorithm>
//#include <map>
#define maxi 1010100
#define mod 1073741824
using namespace std;
typedef long long ll;
int arr[maxi];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int a, b, c;
    cin >> a >> b >> c;
    memset(arr, 0, sizeof(arr));
    ll m = a * b * c;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = i; j <= m ; j += i)
        {
            arr[j]++; //number of divisors for every number j
        }
    }
    ll sum = 0;
    for (int i = 1; i <= a; ++i)
    {
        for (int j = 1; j <= b; ++j)
        {
            for (int k = 1; k <= c ; ++k)
            {
                ll cur = i * j * k;
                sum += arr[cur];
                sum %= mod;
            }
        }
    }
    cout << sum;
    return 0;
}