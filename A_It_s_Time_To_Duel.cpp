#include <bits/stdc++.h>
#define int long long
using namespace std;

int_fast32_t main()
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
        if (n <= 2)
        {
            if (arr[0] == arr[1])
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
            continue;
        }
        char next = 'w';
        bool ok = 1;
        if (arr[0] == 0)
        {
            if (arr[1] == 0)
                ok = false;
            for (int i = 1; i < n - 1; i++)
            {
                if (arr[i] == 0 && arr[i + 1] == 0)
                    ok = false;
            }
        }
        else
        {
            bool found = false;
            for (int i = 1; i < n; i++)
            {
                if (arr[i] == 0)
                    found = true;
            }
            if (found == false)
                ok = 0;
            else if (arr[1] == 0 && arr[2] == 0)
                ok = false;
            for (int i = 2; i < n - 1; i++)
            {
                if (arr[i] == 0 && arr[i + 1] == 0)
                    ok = false;
            }
        }
        if (ok)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
