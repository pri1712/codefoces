#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
//#define pair <int,int> pi;
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
    //sort and take values from start and the end
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        //cout << n;
        int num = 2 * n;
        //cout << num << endl;
        int arr[num];
        for (int i = 0; i < num; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + num); //num is the last index.
        vector<pair<int, int>> points;
        int i = 0;
        int j = num - 1;
        while (i < j)
        {
            points.push_back({arr[i], arr[j]});
            i++;
            j--;
        }//coords
        int pathlen = 0;
        for (int i = 1; i < n; i++)
        {
            int distx = abs(points[i - 1].first - points[i].first);
            int disty = abs(points[i - 1].second - points[i].second);
            pathlen += distx + disty;
        }
        cout << pathlen << endl;
        for (auto it : points)
        {
            cout << it.first << " " << it.second << endl;
        }
    }
    return 0;
}