#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    only possible when f(x) is single number..

    900
    f(x) = 9 f(f(x)) = 9

    so we will have to make f(x) as single number..

    so we keep till the sum of these numbers are not exceeding 9

    12

    it shouldnt have leading zeroes..

    so you cannot delete the first element..

    else all you can delete..




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
        vector<pair<int, int>> arr;
        int index = 0;

        while (n)
        {
            int last = n % 10;
            arr.push_back({last, index});
            n /= 10;
            index++;
        }
        sort(arr.begin(), arr.end());
        int size = arr.size();
        int res = 1;
        int curr_sum = 0;

        for (auto a : arr)

        {
            if (a.second == size - 1)
                curr_sum += a.first;
        }

        for (int i = 0; i < size; i++)
        {
            if (arr[i].second == size - 1)
                continue;
            curr_sum += arr[i].first;
            if (curr_sum > 9)
                break;
            res++;
        }
        int ans = size - 1;
        curr_sum = 0;
        int second_changes = 1;
        // now we will change the first char..
        for (int i = 0; i < size; i++)
        {
            pair<int, int> a = arr[i];

            if (a.second == size - 1)
            {
                arr[i].first = 1;
                curr_sum += 1;
            }
        }
        int not_change = 0;

        for (int i = 0; i < size; i++)
        {
            pair<int, int> a = arr[i];
            if (a.second == size - 1)
                continue; // we have already changed this..
            else
            {

                // either we dont change this..
                curr_sum += a.first;
            }
            if (curr_sum > 9)
                break;
            not_change++;
        }
        ans = 1 + (size - 1 - not_change);

        res = size - res;
        res = min(res, ans);

        cout << res << endl;
    }
    return 0;
}
