#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
//#include <map>
using namespace std;
typedef long long ll;
int maxi;
int mini;
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
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int maxi = arr[0];
    int mini = arr[0];
    int maxid = 0;
    int minid = 0;
    int len = -1;
    int i = 0;
    int j = 1;
    // int diff = 0;
    while (j < n) {
        if (mini >= arr[j]) {
            mini = arr[j];
            minid = j;
        }
        if (maxi <= arr[j]) {
            maxi = arr[j];
            maxid = j;
        }

        int diff = maxi - mini;

        if (diff > 1) {
            i = maxid > minid ? minid + 1 : maxid + 1;
            mini = arr[i], maxi = arr[i];
            minid = i, maxid = i;
            continue;
        }

        len = max(len, j - i + 1);
        j++;

    }
    cout << len << endl;
    return 0;
}