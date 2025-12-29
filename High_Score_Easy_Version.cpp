#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    since in this part n == m so either all are paired

    with each other else if a number from a is not paired

    then another number from b is also not paired

    and every would want to pair with the biggest possible


*/
int find(vector<pair<int, int>> arr, vector<pair<int, int>> b)
{
    int first = arr.size() - 1;
    int second = b.size() - 1;
    int res = 0;
    while (first >= 0 && second >= 0)
    {
        // whether this can combine or not
        int firstele = arr[first].first;
        int firstfreq = arr[first].second;
        int j = second;
        while (j >= 0)
        {
            while (b[j].second == 0 || b[j].first == firstele)
                j--;
            if (j < 0)
                break;
            int minfreq = min(firstfreq, b[j].second);
            b[j].second -= minfreq;
            firstfreq -= minfreq;
            int currsecond = b[j].first;

            res += (firstele * minfreq);
            res += (currsecond * minfreq);
            if (firstfreq == 0)
                break;
        }
        // now second needs to go back till it is non zero

        while (second >= 0)
        {
            if (b[second].second == 0)
                second--;
            else
                break;
        }
        first--;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> arr, b;
        vector<int> temp1, temp2;
        for (int i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;
            temp1.push_back(ele);
        }
        for (int i = 0; i < m; i++)
        {
            int ele;
            cin >> ele;
            temp2.push_back(ele);
        }
        sort(temp1.begin(), temp1.end());
        sort(temp2.begin(), temp2.end());
        int i = 0;
        while (i < temp1.size())
        {
            int j = i;
            while (j < n && temp1[j] == temp1[i])
                j++;
            j--;
            arr.push_back({temp1[i], j - i + 1});
            i = j + 1;
        }
        i = 0;
        while (i < n)
        {
            int j = i;
            while (j < n && temp2[j] == temp2[i])
                j++;
            j--;
            b.push_back({temp2[i], j - i + 1});
            i = j + 1;
        }
        sort(arr.begin(), arr.end());
        sort(b.begin(), b.end());
        int res = find(arr, b);
        res = max(res, find(b, arr));

        cout << res << endl;
    }

    return 0;
}
