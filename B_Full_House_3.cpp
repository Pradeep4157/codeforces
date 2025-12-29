#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<int, int> mp;
    for (int i = 0; i < 7; i++)
    {
        int card;
        cin >> card;
        mp[card]++;
    }
    int first = -1, second = -1;
    for (auto a : mp)
    {
        if (a.second >= 3)
        {
            first = a.first;
        }
    }
    for (auto a : mp)
    {
        if (a.second >= 2 && a.first != first)
        {
            second = a.first;
        }
    }
    if (first == -1 || second == -1)
    {
        cout << "No" << endl;
    }
    else
        cout << "Yes" << endl;
}
