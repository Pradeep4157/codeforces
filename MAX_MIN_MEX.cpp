#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    what is the max mex that is possible..

    that can be found..

    first will always be 0..

    second i need 1 third i need 2 fourth

    i need 3...

    so start from a number and wherever it goes we will have those many

    so basically sorting and finding the mex..

    now some subarrays  will follow this..

    now how many can i  form through these ?

    for mexes > 1 ans is n + if mex > 2 + 1

    and then multiply it with no of mexes that i found with this mex..

    now still it can be more..

    because remaining elements can be rearranged..

    how do i find rem elements..

    so there are some sequence that lead to diff


    can we bf..

    so in the 2nd traversal we will store all the mexes where curr mex is max..

    and also store all of them in map ..

    and then for each subarray..

    first of rem ele  = mp.size() - max_mex..

    and then iterate from smallest to largest and if there is more than 1 ele

    then do rem ++ ..

    do rem = max(resm 1)


    and then multiply this with no  of ways you can rearrage first max mex

    which is ways = max_mex

    if max_mex is more than 2 then wasy ++ ..





*/
const int mod = 998244353;

int power(int a, int b, int mod)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (int)((1LL * res * a) % mod);
        a = (int)((1LL * a * a) % mod);
        b >>= 1;
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
        int n;
        cin >> n;
        vector<int> fact(n + 10, 1);
        for (int i = 1; i < fact.size(); i++)
        {
            fact[i] = i;
            if (i)
                fact[i] *= fact[i - 1];
            fact[i] %= mod;
        }
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());
        map<int, int> mp;
        for (auto a : arr)
        {
            mp[a]++;
        }
        set<int> st;
        for (auto a : arr)
            st.insert(a);
        int max_mex = 1;
        int curr_mex = 1;
        int count = 1;
        for (int i = 1; i < n; i++)
        {
            if ((arr[i] - arr[i - 1]) == 1)
            {
                curr_mex++;
            }
            else
            {
                // it is not continuing..
                curr_mex = 1;
            }
            if (curr_mex > max_mex)
            {
                max_mex = curr_mex;
                count = 1;
            }
            else if (curr_mex == max_mex)
            {
                count++;
            }
        }

        // now we have all the counts..

        if (max_mex == 1)
        {
            // ans is factorial of no of dis elements..
            /*


            */
            int res = 0;
            int numerator = fact[n];
            for (auto a : mp)
            {
                numerator /= fact[a.second];
            }

            cout << numerator << endl;
            continue;
        }
        curr_mex = 1;
        vector<pair<int, int>> subarrays;
        for (int i = 1; i < n; i++)
        {
            if ((arr[i] - arr[i - 1]) == 1)
            {
                curr_mex++;
            }
            else if ((arr[i] - arr[i - 1]) == 0)
                continue;
            else
            {
                // it is not continuing..
                curr_mex = 1;
            }
            if (curr_mex > max_mex)
            {
                max_mex = curr_mex;
                count = 1;
            }
            else if (curr_mex == max_mex)
            {
                subarrays.push_back({arr[i] - curr_mex + 1, arr[i]});
                count++;
            }
        }

        int res = 0;

        int per_window = power(2, max_mex - 1, mod);

        for (auto a : subarrays)
        {
            int rem = n - max_mex;
            rem = fact[rem]; // this is numerator..

            int curr = (per_window * rem) % mod;
            curr %= mod;
            res += curr;
            res %= mod;
        }
        cout << res << endl;
    }
    return 0;
}
