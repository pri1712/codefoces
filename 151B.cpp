#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#define ci(n) cin>>n
#define co(n) cout<<n
#define nl '\n'
#define r0 return 0
#define LLMAX LLONG_MAX
#define all(x) (x).begin(), (x).end()
typedef std::pair<int, int> pp;
typedef long long ll;
typedef std::vector<ll> vl;
typedef std::vector<std::pair<int, int>> vp;
typedef std::vector<int> vi;
typedef std::unordered_map<int, int> unmap;
typedef std::unordered_set<int> unset;
typedef std::unordered_set<char> unsetc;
using namespace std;
int mod = 1e9 + 7;
bool ispizza(string& s)
{
    for (int i = 1; i < (int)s.size(); ++i)
    {
        if (s[i] < s[i - 1])
            continue;
        else
            return false;
    }
    return true;
}


bool istaxi(string& s)
{
    for (int i = 1; i < (int)s.size(); ++i)
    {
        if (s[i] == s[i - 1])
            continue;
        else
            return false;
    }
    return true;
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
    int n;
    ci(n);
    //no of friends.
    vector<string> pizzav, taxiv, girlv;
    unordered_set<string> pizza, taxi, girl;//store names those who have max
    ll numpizza = 0, numtaxi = 0, numgirl = 0;//max counts of pizza taxi and girls
    while (n--)
    {
        int m;
        ci(m);//no of numbers in phone book.
        string name;
        ci(name);
        ll pizzacount = 0, taxicount = 0, girlcount = 0;//count of each per name.
        for (int j = 0; j < m; j++)
        {
            string num;
            ci(num);
            string numcor = "";
            for (int i = 0; i < (int)num.size(); i++)
            {
                if (num[i] == '-')
                    continue;
                else
                    numcor += num[i];
            }
            // co(numcor); co(":"); co(name); co(nl);
            if (ispizza(numcor))
            {
                pizzacount++;
            }
            else if (istaxi(numcor))
                taxicount++;
            else
                girlcount++;
            if (pizzacount > numpizza)
            {
                numpizza = pizzacount;
                pizza.clear();
                pizza.insert(name);
            }
            else if (pizzacount == numpizza)
            {
                pizza.insert(name);
            }
            if (taxicount > numtaxi)
            {
                numtaxi = taxicount;
                taxi.clear();
                taxi.insert(name);
            }
            else if (taxicount == numtaxi)
            {
                taxi.insert(name);
            }
            if (girlcount > numgirl)
            {
                numgirl = girlcount;
                girl.clear();
                girl.insert(name);
            }
            else if (girlcount == numgirl)
            {
                girl.insert(name);
            }
        }
    }
    co("If you want to call a taxi, you should call: ");
    if (taxi.size() == 1)
    {
        auto it = taxi.begin();
        co(*it); co(".");
        co(nl);
    }
    else
    {
        for (auto it = taxi.begin(); it != taxi.end(); ++it)
        {
            taxiv.push_back(*it);
        }
        for (int t = (int)taxiv.size() - 1; t > 0; t--)
        {
            co(taxiv[t]);
            co(",");
        }
        co(taxiv[0]);
        co(".");
        co(nl);
    }
    co("If you want to order a pizza, you should call: ");
    if (pizza.size() == 1)
    {
        auto it = pizza.begin();
        co(*it); co(".");
        co(nl);
    }
    else
    {
        for (auto it = pizza.begin(); it != pizza.end(); ++it)
        {
            pizzav.push_back(*it);
        }
        for (int p = (int)pizzav.size() - 1; p > 0; p--)
        {
            co(pizzav[p]);
            co(",");
        }
        co(pizzav[0]);
        co(".");
        co(nl);
    }
    co("If you want to go to a cafe with a wonderful girl, you should call: ");
    if (girl.size() == 1)
    {
        auto it = girl.begin();
        co(*it); co(".");
        co(nl);
    }
    else
    {
        for (auto it = girl.begin(); it != girl.end(); ++it)
        {
            girlv.push_back(*it);
        }
        for (int g = (int)girlv.size() - 1; g > 0; g--)
        {
            co(girlv[g]);
            co(",");
        }
        co(girlv[0]);
        co(".");
        co(nl);
    }
    r0;
}