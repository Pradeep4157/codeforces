#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    there are n prod..

    price of each is pi..

    each prod has some functions

    some we need to find if there is  a prod that is superior to another..

    so pi >= pj..

    jth prod should have all the functions of ith prod..

    and also either pi > pj || jth has more function since it already has same prods..


*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<pair<int, multiset<int>>> arr;
    for (int i = 0; i < n; i++)
    {
        int pi;
        cin >> pi;
        int ci;
        cin >> ci;
        multiset<int> curr;
        for (int j = 0; j < ci; j++)
        {
            int ele;
            cin >> ele;
            curr.insert(ele);
        }
        arr.push_back({pi, curr});
    }
    // for (auto a : arr)
    // {
    //     cout << a.first << ":";
    //     for (auto b : a.second)
    //         cout << b << " ";
    //     cout << endl;
    // }
    bool ok = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            // now check the condition..
            int pi = arr[i].first;
            int pj = arr[j].first;
            // 1st condition check..
            if (pi < pj)
                continue;
            multiset<int> &first = arr[i].second;
            multiset<int> &second = arr[j].second;
            bool found = false;
            // 2nd condition check..
            for (auto k : first)
            {
                // all should be there..
                if ((!second.count(k)))
                {
                    found = 1;
                }
            }
            if (found == 1)
                continue;
            if (pi > pj)
            {

                ok = 1;
                break;
            }
            // else j should have more than i ..
            int size_1 = first.size();
            int size_2 = second.size();
            if (size_2 > size_1)
            {
                ok = 1;
                break;
            }
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}
