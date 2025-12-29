#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    ok so we cant do anything for the subarrays that are already formed in the given array .

    so these are the things that i need to take care of :

    1 ) they should not form palindrome among themselves for this i just need 3 numbers && i will just keep repeating them 1 2 3 1 2 3 1 2 3 1 2 3

    2 ) they should not form palindrom with already array :

        for this there are various cases :
            like if we get >=3 numbers that have not occured in the array then we will just print them again and again till k is finished .

        else :


    so first we try to  find non occuring elements we just need 3

    after finding these if the res.size() == 3 , then we keep repeating

    else

        if res size is 1 :
            we need two numbers if arr[i] != arr[i+1] we push these two and break

        else if res size is 2 :
            we need one number we push the first number in the array


        the more they are
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
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        set<int> st(arr.begin(), arr.end());
        vector<int> res;
        for (int i = 1; i <= n; i++)
        {
            if (!st.count(i))
            {
                res.push_back(i);
            }
            if (res.size() == 3)
                break;
        }
        if (res.size() == 0)
        {
            // this is the case when all the numbers are occuring only once
            // just take the first 3 numbers

            for (int i = 0; i < 3; i++)
                res.push_back(arr[i]);
        }
        if (res.size() == 1)
        {
            // we need two numbers
            for (int i = n - 2; i >= 0; i--)
            {
                if (arr[i] != arr[i + 1])
                {
                    res.push_back(arr[i]);
                    res.push_back(arr[i + 1]);
                    break;
                }
            }
        }
        if (res.size() == 2)
        {
            res.push_back(arr[0]);
        }
        // now we keep repeating
        int index = 0;
        vector<int> ans;
        while (k)
        {
            k--;
            ans.push_back(res[index]);
            index++;
            index %= 3;
        }
        for (auto a : ans)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
