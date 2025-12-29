#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
        ONCE VISITING AN ODD ONE HE CAN COLLECT ALL THE EVEN ONES AND
        AFTER THAT HE WILL TAKE TOP K/2 ODD ONES




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
        vector<int> odd, even;
        for (int i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;
            if (ele & 1)
                odd.push_back(ele);
            else
                even.push_back(ele);
        }
        if (odd.empty())
        {
            cout << 0 << endl;
            continue;
        }
        int res = accumulate(even.begin(), even.end(), 0LL);
        sort(odd.rbegin(), odd.rend());
        int size = odd.size();
        for (int i = 0; i < (size + 1) / 2; i++)
        {
            res += odd[i];
        }
        cout << res << endl;
    }
    return 0;
}
