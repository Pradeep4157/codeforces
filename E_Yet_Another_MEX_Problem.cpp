#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    weight of array b is the count of number of elements > mex (b)

    so now for every i we need to find what is the max mex among all the subarray that are formed towards the left
    of index i

    looks simple becaue for every index max will be when l=0 because lets say that all the max elements are formed till
    some index  x > 0 then even if we consider l as 0 all those elements are still included

    now for every index i we need mex till that index and count of elements in the left that are greater than that
    mex


    to find the mex of the array we can keep set of elements from 1 to n and whatever element comes we just remove
    that from the set and the first element of the set is the mex of the current array

    BUT HOW DO WE FIND COUNT OF ELEMENT > MEX

    using a multiset ??

        now we have all the elements stored in the multiset we just apply upper bound in the multiset

        we will get the index of elements > mex of the current array

        and ans = size-index


        when will ans==0:
            it will be either when set is empty or upper bound is pointing outside the multiset which are both
            the same cases


        WRONG :( 

        because taking the longest is not always beneficial because if we do not consider some of the left 
        elements then they wont be included in calculating the mex as well

        so how do we decide which subarray to take ?

        

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
        set<int> st;
        for (int i = 0; i <= n; i++)
        {
            st.insert(i);
        }
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        multiset<int> ms;
        for (int i = 0; i < n; i++)
        {
            st.erase(arr[i]);
            ms.insert(arr[i]);
            int mex = *st.begin();
            auto it = ms.upper_bound(mex);
            if (it == ms.end())
            {
                // then all the elements are there
                cout << 0 << " ";
            }
            else
            {
                int index = distance(ms.begin(), it);
                int size = ms.size();
                cout << size - index << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}
