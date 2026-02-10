#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    in the zero we will try to put in odd indexes..

    but when :

        right end is adj to one we will not put there ..



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
        string s;
        cin >> s;
        vector<pair<int, int>> arr;
        int right = 0;
        while (right < n)
        {
            while (right < n && s[right] == '1')
                right++;
            if (right == n)
                break;
            int left = right;
            while (right < n && s[right] == '0')
                right++;
            right--;
            arr.push_back({left, right});
            right++;
        }

        // now we put in between..
        int res = 0;
        for (auto a : s)
            if (a == '1')
                res++;
        for (auto a : arr)
        {
            int start = a.first;
            int end = a.second;
            int size = end - start + 1;

            if (start != 0)
                size--;
            if (end != n - 1)
                size--;

            size = max(size, 0LL);
            int curr = 0;
            if (size == 1)
                curr = 1;
            else

            {

                int curr_left = 1;

                while (curr_left < size)
                {
                    curr++;
                    curr_left += 3;
                }

                if (curr_left == size)
                    curr++;
            }
            res += curr;
        }
        cout << res << endl;
    }
    return 0;
}
