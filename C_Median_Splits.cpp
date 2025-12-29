#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
bool recursion2(int start, vector<int> &nums, int k)
{
    multiset<int> st;
    multiset<int>::iterator medianIt;
    bool possible = false;
    for (int i = start; i < n - 1; i++)
    {
        int num = nums[i];
        st.insert(num);

        if (st.size() == 1)
        {
            medianIt = st.begin(); // first element is the median
        }
        else
        {
            if (num < *medianIt)
            {
                if (st.size() % 2 == 0)
                {
                    // size was odd before insert; now even => median shifts left
                    --medianIt;
                }
            }
            else
            {
                if (st.size() % 2 == 1)
                {
                    // size was even before insert; now odd => median shifts right
                    ++medianIt;
                }
            }
        }
        int median = *medianIt;
        if (median <= k)
        {
            return true;
        }
    }
    return false;
}
bool recursion1(vector<int> &nums, int k)
{
    multiset<int> st;
    multiset<int>::iterator medianIt;
    bool possible = false;
    for (int i = 0; i < n - 2; i++)
    {
        int num = nums[i];
        st.insert(num);

        if (st.size() == 1)
        {
            medianIt = st.begin(); // first element is the median
        }
        else
        {
            if (num < *medianIt)
            {
                if (st.size() % 2 == 0)
                {
                    // size was odd before insert; now even => median shifts left
                    --medianIt;
                }
            }
            else
            {
                if (st.size() % 2 == 1)
                {
                    // size was even before insert; now odd => median shifts right
                    ++medianIt;
                }
            }
        }
        int median = *medianIt;
        if (median <= k)
        {
            possible |= recursion2(i + 1, nums, k);
            if (possible)
                break;
        }
    }
    return possible;
}
bool recursion3(int end, vector<int> &nums, int k)
{
    multiset<int> st;
    multiset<int>::iterator medianIt;
    bool possible = false;
    for (int i = n - 1; i > end; i--)
    {
        int num = nums[i];
        st.insert(num);
        if (st.size() == 1)
        {
            medianIt = st.begin(); // first element is the median
        }
        else
        {
            if (num < *medianIt)
            {
                if (st.size() % 2 == 0)
                {
                    // size was odd before insert; now even => median shifts left
                    --medianIt;
                }
            }
            else
            {
                if (st.size() % 2 == 1)
                {
                    // size was even before insert; now odd => median shifts right
                    ++medianIt;
                }
            }
        }
        int median = *medianIt;
        if (median <= k)
        {
            return true;
        }
    }
    return false;
}
bool recursion11(vector<int> &nums, int k)
{
    multiset<int> st;
    multiset<int>::iterator medianIt;
    bool possible = false;
    // 1st partition
    for (int i = 0; i < n - 2; i++)
    {
        int num = nums[i];
        st.insert(num);

        if (st.size() == 1)
        {
            medianIt = st.begin(); // first element is the median
        }
        else
        {
            if (num < *medianIt)
            {
                if (st.size() % 2 == 0)
                {
                    // size was odd before insert; now even => median shifts left
                    --medianIt;
                }
            }
            else
            {
                if (st.size() % 2 == 1)
                {
                    // size was even before insert; now odd => median shifts right
                    ++medianIt;
                }
            }
        }
        int median = *medianIt;
        if (median <= k)
        {
            possible |= recursion3(i + 1, nums, k);
            if (possible)
                break;
        }
    }
    return possible;
}
int_fast32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> n >> k;

        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        bool res = recursion1(nums, k); // 1st and 2nd partition
        res |= recursion11(nums, k);    // 1st and 3rd partition
        reverse(nums.begin(), nums.end());
        res |= recursion1(nums, k); // 3rd and 2nd partition
        if (res)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}