#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    we can put anything in these but the sorting should cost min reversals..

    ???10 we need to reverse the front part..

    ???01???01

    0000100001
    0000000011


    ????10???01
    0001000001
    000000011

    1??10?
    10010


    last part i can put 1...

    else will i always put 0 ?

    1??1?0?
    1111101

    when there are some ? and the left part is a 1 that means this part is going back..

    else if right part is 0 then also this part is going left...

    else if left is zero then no need of rev here..






*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        bool zero_found = false;
        int n = s.size();
        vector<pair<int, int>> subarrays;
        int right = 0;
        while (right < n)
        {
            while (right < n && s[right] != '?')
                right++;
            int left = right;
            while (right < n && s[right] == '?')
                right++;
            right--;
            subarrays.push_back({left, right});
            right++;
        }

        for (auto a : subarrays)
        {
            int left = a.first;
            int right = a.second;
            // i will put zero only if left is zero
            bool left_zero = false;
            if (left == 0 || s[left - 1] == '0')
                left_zero = 1;
            if (left_zero)
            {
                for (int i = left; i <= right; i++)
                {
                    s[i] = '0';
                }
                continue;
            }
            // i will one only if right is end or right is 1..
            bool right_one = true;
            if (right == n - 1 || s[right + 1] == '1')
                right_one = 1;
            if (right_one)
            {
                for (int i = left; i <= right; i++)
                {
                    s[i] = '1';
                }
                continue;
            }
            // now left is not zero and right is not one..
            //  so we need to reverse it anyways put anything..
        }
        cout << s << endl;
    }
    return 0;
}
