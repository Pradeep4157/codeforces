#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    one of the 2 ends is going to be const ig..

    because if we take both of them

    then they just reverse and appear at the ends

    again..

    if n - 1 is const then i will have to make sure

    arr[n - 1] is at first so

    but here there is choice factor that whether i keep last char

    as it is / first char as it is..

    on the basis of that left and right will shift..

    this will be recursion..

    we can only create left side of palindrome..

    i have first half, second half..

    now i select a subsequence of first half reverse it and add it to the front of the


    so i keep pointers on both the array right pointer on n - 1 in first

    array and left pointer on 0 in second..

    now i keep moving left++ and right-- till they are same

    now the moment they are not same..

    i will have to move the subarray of right from index + 1...right to the front

    of the first array..

    and after this move right to that index..

    if that index is after this index

    then not possible ..

    else move there again do left++,right-- and continue..




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
        n *= 2;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        set<int> st;
        deque<int> second_half, first_half;
        for (int i = n - 1; i >= 0; i--)
        {
            if (!st.count(arr[i]))
            {
                st.insert(arr[i]);
                second_half.push_front(arr[i]);
            }
            else
            {
                first_half.push_front(arr[i]);
            }
        }
        vector<int> first, second;
        n /= 2;
        for (auto a : first_half)
            first.push_back(a);
        for (auto a : second_half)
            second.push_back(a);
        // for (auto a : first)
        //     cout << a << " ";
        // cout << endl;
        // for (auto a : second)
        //     cout << a << " ";
        // cout << endl;
        bool ok = 1;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[first[i]] = i;
        }
        int right = n - 1;
        int left = 0;
        vector<pair<int, int>> reverses;
        while (true)
        {
            if (left >= n || right < 0)
                break;

            // now if they are same move to the next thing..
            if (first[right] == second[left])
            {
                left++;
                right--;
                continue;
            }
            // now we need to find second[left], if its on right maybe it might have come here after reversing..
            int index = mp[second[left]];
            if (index > right)
            {
                right--;
                left++;
                continue;
            }
            // now we found somewhere left so till there we will addd to front of the array..
            reverses.push_back({index + 1, right});
            right = index;
        }

        vector<bool> vis(n, false);
        vector<int> actual_first;
        for (auto a : reverses)
        {
            int end = a.second;
            int start = a.first;
            for (int i = end; i >= start; i--)
            {
                actual_first.push_back(first[i]);
                vis[i] = 1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (vis[i])
                continue;
            actual_first.push_back(first[i]);
        }
        reverse(actual_first.begin(), actual_first.end());
        for (int i = 0; i < n; i++)
        {
            if (actual_first[i] != second[i])
            {
                ok = false;
                break;
            }
        }

        cout << (ok ? "Yes" : "No") << endl;
    }

    return 0;
}
