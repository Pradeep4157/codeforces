#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so we select some k teleports from which his friends can

    meet him ..

    so the teleports should be placed such that first takes the

    max time to reach ...

    looks like a bs problem where for every distance

    i see whether it is possible to place all the k between

    the people such that the dist >= mid ..

    if possible then we try some higher dist..
    else lower dist ..


    how do  we place things ..

    for ai , ai+ 1

    start = ai + mid

    end = ai - mid

    if end >= start we can place some ..

    we can also place befoer a0 , 0

    and also after an-1,x

*/
int k;
int n;
int x;
pair<bool, vector<int>> find(int mid, vector<int> &arr)
{
    int tempk = k;
    int i = 0;
    vector<int> res;
    int currstart = 0;
    int currend = arr[0] - mid;
    while (currstart <= currend)
    {
        if (tempk == 0)
            break;
        tempk--;
        res.push_back(currstart);
        currstart++;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (tempk == 0)
            break;
        int first = arr[i];
        int second = arr[i + 1];
        int start = first + mid;
        int end = second - mid;
        while (start <= end)
        {
            if (tempk == 0)
                break;
            tempk--;
            res.push_back(start);
            start++;
        }
    }
    currstart = arr[n - 1] + mid;
    currend = x;
    while (currstart <= currend)
    {
        if (tempk == 0)
            break;
        tempk--;
        res.push_back(currstart);
        currstart++;
    }
    if (tempk)
    {
        return {0, res};
    }
    else
        return {1, res};
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {

        cin >> n >> k >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());
        vector<int> res(k, 0);

        int mintime = 0;
        int low = 0, high = x;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            pair<bool, vector<int>> curr = find(mid, arr);
            if (curr.first == 1)
            {

                res = curr.second;
                low = mid + 1;
                mintime = mid;
            }
            else
                high = mid - 1;
        }
        if (mintime == 0)
        {
            for (int i = 0; i < k; i++)
                res[i] = i;
        }
        for (auto a : res)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
