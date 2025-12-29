#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> arr(n), arr2(m);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int j = 0; j < m; j++)
            cin >> arr2[j];

        if (n == 1)
        {
            cout << "YES" << endl;
            continue;
        }
        sort(arr2.begin(), arr2.end());
        int alone = arr2[0];
        arr[0] = min(arr[0], alone - arr[0]);
        bool possible = 1;
        for (int i = 1; i < n - 1; i++)
        {
            int comp = alone - arr[i];
            if (comp <= arr[i] && comp >= arr[i - 1])
                arr[i] = comp;
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                possible = false;
                break;
            }
        }

        if (possible)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO " << endl;
    }
    return 0;
}