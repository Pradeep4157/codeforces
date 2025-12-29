#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    f(x) = |ai - x|

    min & max of array is Infinity ...



*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        int mini = 1e9, maxi = -2;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            maxi = max(arr[i], maxi);
            mini = min(arr[i], mini);
        }
        vector<int> res(n);
        vector<int> temp;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == maxi || arr[i] == mini)
            {
                res[i] = -1;
            }
            else
            {
                mp[arr[i]]++;
            }
        }
        mp[mini]++;
        mp[maxi]++;
        map<int, int> mp1;
        for (auto a : mp)
        {
            temp.push_back({a.first});
        }
        sort(temp.begin(), temp.end());
        int size = temp.size();
        for (int i = 1; i < size - 1; i++)
        {
            int curr = temp[i];
            int prev = temp[i - 1];
            int next = temp[i + 1];
            // first diff btwn curr && prev
            int elementsbefore = curr - prev - 1;
            // now we can take after mid..
            elementsbefore = (elementsbefore) / 2;
            // these are what curr can take
            mp1[curr] += elementsbefore;
            int elementsafter = next - curr - 1;

            elementsafter = (elementsafter + 1) / 2;

            // these are what curr can take ..
            mp1[curr] += elementsafter;
            mp1[curr]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == maxi || arr[i] == mini)
            {
                continue;
            }
            else
            {
                res[i] = mp1[arr[i]];
            }
        }
        for (auto a : res)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
