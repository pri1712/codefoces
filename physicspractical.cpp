#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int i = 0;
    int j = 0;
    sort(arr, arr + n);
    int ans = 0;
    while (j < n)
    {
        if (arr[i] * 2 >= arr[j])
        {
            ans = max(ans, j - i + 1);
            j++;
        }
        else
        {
            i++;
        }
    }
    cout << n - ans << endl;
    return 0;

}