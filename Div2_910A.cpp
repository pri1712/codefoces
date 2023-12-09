#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
typedef long long ll;
typedef std::vector<ll> vl;
typedef std::vector<int> vi;
typedef std::unordered_map<int, int> unmapii;
typedef std::unordered_map<char, int> unmapci;
typedef std::unordered_set<int> unset;
typedef std::unordered_set<char> unsetc;
using namespace std;
//unmapci mp;
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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        //int countofa = 0;
        int countofb = 0;
        for (int i = 0; i < n; i++)
        {
            //cin >> s[i];
            if (s[i] == 'B')
                countofb++;
        }
        if (countofb == k)
        {
            cout << 0 << endl;
        }
        else if (countofb > k)
        {
            //number of B is more thus need to convert to A.
            cout << 1 << endl;
            int bcount = 0;
            int i = 0;
            int req = countofb - k;
            while (bcount < req)
            {
                if (s[i] == 'B')
                    bcount++;
                i++;
            }
            cout << i << " " << 'A' << endl;

        }
        else
        {
            int reqB = k - countofb;
            cout << 1 << endl;
            int i = 0;
            int acount = 0;
            while (acount < reqB)
            {
                if (s[i] == 'A')
                {
                    acount++;
                }
                i++;
            }
            cout << i << " " << 'B' << endl;
        }
        //mp.clear();
    }
    return 0;
}