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
        {
            cin >> arr[i];
        }
        int left = 0, right = 0;
        vector<pair<int, int>> ranges(n);
        bool ok = 1;
        vector<int> ones;
        for (int i = 0; i < n; i++)
            cin >> ranges[i].first >> ranges[i].second;
        // impossible check
        vector<pair<int, int>> valid_range(n);
        for (int i = 0; i < n; i++)
        {
            int currleft = ranges[i].first;
            int currright = ranges[i].second;
            if (arr[i] == -1)
                right++;
            else if (arr[i] == 1)
            {
                left++;
                right++;
            }
            int maxleft = max(left, currleft);
            int minright = min(right, currright);
            if (maxleft > minright)
            {
                ok = false;
                break;
            }
            left = max(left, currleft);
            right = min(right, currright);
            valid_range[i].first = left;
            valid_range[i].second = right;
        }

        if (ok == false)
        {
            cout << -1 << endl;
            continue;
        }
        stack<int> st;
        left = 0, right = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == -1)
            {
                st.push(i);
                int currleft = ranges[i].first;
                int currright = ranges[i].second;
                while (currleft > right)
                {
                    st.pop();
                    right++;
                    left++;
                }
            }
            else
            {
                if (arr[i] == 1)
                {
                    left++;
                    right++;
                }
                int currleft = ranges[i].first;
                int currright = ranges[i].second;
                while (currleft > right)
                {
                    right++;
                    left++;
                    st.pop();
                }
            }
        }
        while (!st.empty())
        {
            int index = st.top();
            st.pop();
            arr[index] = 0;
        }
        for (int i = 0; i < n; i++)
            if (arr[i] == -1)
                arr[i] = 1;
        for (auto a : arr)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
