#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++)
        cin >> q[i];
    unordered_map<int, pair<int, int>> mp1, mp2;
    for (int i = 0; i < n; i++)
    {
        int person = i + 1;
        int bibnumber = q[i];
        int staringat = p[i];
        mp1[person] = {bibnumber, staringat};
        mp2[bibnumber] = {person, staringat};
    }

    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        int person = i + 1;
        int bipnumberofperson = mp2[person].first;
        int index = mp2[person].second;
        int bipnumber = mp1[index].first;
        res[i] = bipnumber;
    }
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
