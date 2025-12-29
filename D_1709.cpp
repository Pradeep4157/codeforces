#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    vector<int> indexes;
    int n = s.size();
    for (int i = 0; i < n - 2; i++)
    {
        if (s[i] == 'k' && s[i + 1] == 'e' && s[i + 2] == 'p')
            indexes.push_back(i);
    }
    if (indexes.empty())
    {
        cout << -1 << endl;
    }
    else
    {
        int left = 0;
        int right = indexes[0] + 2;
        int maxi = right - left;
        int size = indexes.size();
        for (int i = 0; i < size - 1; i++)
        {
            int currwindow = indexes[i + 1] + 2 - indexes[i];
            if (currwindow > maxi)
            {
                maxi = currwindow;
                left = indexes[i];
                right = indexes[i + 1] + 1;
            }
        }
        
        // for last kepa
        int curr = n - indexes[size - 1];
        if (curr > maxi)
        {
            left = indexes[size - 1];
            right = n - 1;
        }
        for (int i = left; i <= right; i++)
        {
            cout << s[i];
        }
        return 0;
    }
    return 0;
}
