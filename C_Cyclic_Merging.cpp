#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    so circle is given..

    adj will replace by max(x,y)

    cost is also max(x,y)

    so we need to convert all ele

    to 1 with min op..


    so what is def..

    first i will try to compress the

    elements whose max is min..


    in the overall result..

    an element can contribute only

    when in the path between

    itself and the lower element there

    is no bigger element..





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
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n - 1; i++)
        {
            int mini = min(arr[i], arr[i + 1]);
            int maxi = max(arr[i], arr[i + 1]);
            pq.push({maxi, mini});
        }
        int currmini = min(arr[0], arr[n - 1]);
        int currmaxi = max(arr[0], arr[n - 1]);

        pq.push({currmaxi, currmini});
        int res = 0;
        while (pq.size() > 1)
        {
            pair<int, int> top = pq.top();
            // cout << top.first << ":" << top.second << endl;
            pq.pop();
            int curr = max(top.first, top.second);
            // cout << curr << endl;
            res += curr;
        }
        cout << res << endl;
    }
    return 0;
}
