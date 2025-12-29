#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
    1 3 3  3 2



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
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int i = max_element(arr.begin(), arr.end()) - arr.begin();
        bool ok = 1;
        while (true)
        {
            if (arr[i] == 1)
                break;
            bool curr = 0;
            int next = -1;
            if (i + 1 < arr.size())
            {
                if (arr[i + 1] == arr[i] - 1)
                {
                    curr = 1;
                    next = i;
                    arr.erase(arr.begin() + i);
                }
            }
            if (i - 1 >= 0)
            {
                if (arr[i - 1] == arr[i] - 1)
                {

                    curr = 1;
                    next = i - 1;
                    arr.erase(arr.begin() + i);
                }
            }
            if (curr == 0)
            {

                // cout << i << endl;
                ok = false;
                break;
            }
            else
                i = next;
        }
        cout << ((ok) ? "YES" : "NO") << endl;
    }
    return 0;
}
