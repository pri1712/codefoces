#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
//#include <map>
using namespace std;
int n;
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
    cin >> n;
    ll sum = 0;
    int last = 0;
    // string fr, sc = "";
    vector<ll> fr;
    vector<ll> sc;
    for (int i = 0; i < n; i++)
    {
        ll cur;
        cin >> cur;
        sum += cur;
        last = cur;
        if (cur > 0)
        {
            fr.push_back(cur);
        }
        else if (cur < 0)
        {
            sc.push_back(cur * -1);
        }

    }
    if (sum > 0)
    {
        cout << "first" << endl;
        return 0;
    }
    else if (sum < 0)
    {
        cout << "second" << endl;
        return 0;
    }
    else
    {
        if (fr == sc)
        {
            if (last > 0)
                cout << "first";
            else
                cout << "second";
        }
        else
        {
            int i = 0, j = 0;
            while (i < (int)fr.size() && j < (int)sc.size())
            {
                if (fr[i] == sc[j])
                {
                    i++;
                    j++;
                }
                else
                {
                    if (fr[i] > sc[i])
                    {
                        cout << "first";
                        return 0;
                    }
                    else
                    {
                        cout << "second";
                        return 0;
                    }
                    break;
                }
            }
        }
    }
    return 0;
}