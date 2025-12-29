#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
    SO WE NEED TO DETERMINE THE SUBARRAYS THAT ARE GOOD

    if some element's freq%k==0 then res++

    lets say arr=1,1,1
    k=1
    ans=3
    we cant have 2 sized

    1,2,1,2
    1
    2
    1
    2
    1,2
    2,1
    1,2

    if some ele%k then we can make subarray of that
    lets say k=2 and freq(arr[i])=4
    we need to  add at least 2

    if there's any element in the array whose freq%k is not zero
    then ans =0 because they need to be in any multiset

    there is a max limit on how many elements can i put in the current
    array=> freq(arr[i])/k
    i can put lesser than or equal  to that
    after adding arr[right] if it exceeds

    what is the formula to calculate:
        we keep left and right
        and keep adding size to the overall res



*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i]]++;
        }
        bool ok = true;
        for (auto a : mp)
        {

            if (a.second % k)
            {

                ok = false;
                break;
            }
        }
        if (ok == false)
        {
            cout << 0 << endl;
            continue;
        }
        int left = 0, right = 0;
        map<int, int> currfreq;
        int res = 0;
        while (right < n)
        {
            int ele = arr[right];
            int freq = mp[ele];
            currfreq[ele]++;
            int curr = currfreq[ele];
            int limit = mp[ele] / k;
            if (curr > limit)
            {
                // cout << left << ":" << right << endl;
                while (left < right)
                {
                    currfreq[arr[left]]--;
                    left++;
                    if (arr[left - 1] == ele)
                        break;
                }
            }
            // cout << left << ":" << right << endl;
            res += (right - left + 1);
            right++;
        }
        cout << res << endl;
    }
    return 0;
}
