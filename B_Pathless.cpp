#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n >> s;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int sum = accumulate(arr.begin(), arr.end(), 0LL);
        if (sum > s)
        {
            sort(arr.begin(), arr.end());
            for (auto a : arr)
                cout << a << " ";
            cout << endl;
        }
        else if (sum == s)
        {
            cout << -1 << endl;
        }
        else
        {
            if (sum == s - 1)
            {
                // impossible
                sort(arr.begin(), arr.end());
                int oneindex = 1, twoindex = 2;
                for (int i = 0; i < n; i++)
                {
                    if (arr[i] == 1)
                    {
                        oneindex = i;
                        break;
                    }
                }
                for (int i = 0; i < n; i++)
                {
                    if (arr[i] == 2)
                    {
                        twoindex = i;
                        break;
                    }
                }
                swap(arr[oneindex], arr[twoindex]);
                for (auto a : arr)
                    cout << a << " ";
                cout << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}
