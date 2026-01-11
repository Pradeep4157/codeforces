#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    for every i from 1..x/2

    x2i - 1 ,x2i must be equal

    for 1: 1,2
    for 2: 3,4
    for 3: 5,6
    for 4: 7,8

    and all the number should appear only twice that will be some ai,ai+1 nowhere else..

    so some 2 pointer to find the occurences

    right,right + 1 should be same if not

    move left till here this is not a valid window..

    or

    if the number is already there in this window

    then move left till this number is no longer present..


    so first check if right != right - 1..

    then remove all these map things..
    move right++
    make left = right
    and continue.
    now mp[arr[right]]++;
    move left till mp[arr[right]] == 1..

    now you have a valid window check it with max

    and update in case...

*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int left = 0, right = 1;
    map<int, int> mp;
    int res = 0;
    while (right < n)
    {
        if (arr[right] != arr[right - 1])
        {
            // here although right is not equal to right - 1 but there's a case that right - 1 == right - 2.

            if (right - 2 >= 0 && arr[right - 1] == arr[right - 2])
            {
                mp.clear();
                left = right - 2;
                right--;
                continue;
            }
            mp.clear();
            left = right;
            right++;
            continue;
        }

        // now we have same char..
        mp[arr[right]] += 2;
        if (mp.find(arr[right]) != mp.end() && mp[arr[right]] > 2)
        {

            while (mp[arr[right]] > 2 && left <= right)
            {
                if (mp[arr[left]] > 0)
                    mp[arr[left]]--;
                left++;
            }
        }
        // now we have valid window..
        int curr = right - left + 1;

        res = max(res, curr);
        right += 2;
    }
    cout << res << endl;

    return 0;
}
