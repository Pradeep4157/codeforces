#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    i select some k

    and then for all the array ele..

    choose some x>=k and make ai = ai mod x..

    so ai becomes 0.. x -1

    so all becomes identical ig they are saying

    same..

    lower bound is def min of arr

    u can select that and select all x == arr[i]

    and make all of them 0..

    what is the upper bound.

    when i choose min + 1 i need to be able to make

    all the remaining ele == min ..

    because min will never change..

    for any arr[i]

    the k that i choose

    i can make eles from arr[i] - k ....0

    bs can be done..



*/
bool poss(vector<int> &arr, int curr, int mini)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int currposs = arr[i] - curr;
        if (currposs < mini && arr[i] != mini)
        {

            return false;
        }
    }
    return true;
}

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

        int min_req = *min_element(arr.begin(), arr.end());
        int res = min_req;
        int low = min_req, high = *max_element(arr.begin(), arr.end());
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (poss(arr, mid, min_req))
            {
                res = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        cout << res << endl;
    }

    return 0;
}
