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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        bool inc = true;
        int i = 0, j = n - 1;
        while (i <= j)
        {
            if (inc)
            {
                if (arr[i] > arr[j])
                {
                    cout << "R";
                    j--;
                }
                else
                {
                    cout << "L";
                    i++;
                }
                inc = false;
            }
            else
            {
                if (arr[i] > arr[j])
                {
                    cout << "L";
                    i++;
                }
                else
                {
                    cout << "R";
                    j--;
                }

                inc = true;
            }
        }
        cout << endl;
    }
    return 0;
}
