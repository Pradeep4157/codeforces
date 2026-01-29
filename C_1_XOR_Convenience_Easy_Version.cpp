#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so in this so i*j == x and this x we can put it on the left side..

    if n is some 2^n - 1 then we can do this 6,5,4,3,2,1,7

    but for rem cases :



*/
bool is_valid(vector<int> &arr)
{
    bool valid = 1;
    int n = arr.size();
    for (int i = 1; i < n - 1; i++)
    {
        bool found = false;
        for (int j = i + 1; j < n; j++)
        {
            if ((arr[j] ^ (i + 1)) == arr[i])
            {
                found = 1;
                break;
            }
        }
        if (found == false)
        {
            valid = false;
            break;
        }
    }
    return valid;
}
bool power_of_TWO(int n)
{
    return n > 0 && (n & (n - 1)) == 0;
}
bool power_of_two_1(int n)
{
    return n > 0 && (n & (n + 1)) == 0;
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

        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            arr[i] = i + 1;
        }

        vector<int> res(n);
        int index = n - 1;
        set<int> st;
        for (int i = 1; i <= n; i++)
        {
            st.insert(i);
        }
        while (index >= 0)
        {
            int right = index;
            res[index--] = *st.begin();
            st.erase(st.begin());

            while (true)
            {

                int number = ((index + 1) ^ res[right]);
                if (st.count(number))
                {
                    res[index--] = number;
                    st.erase(number);
                }
                else
                    break;
            }
        }
        for (auto a : res)
            cout << a << " ";
        cout << endl;
        
        // do
        // {

        //     if (is_valid(arr))
        //     {
        //         cout << "hehehehe : ";
        //         for (auto a : arr)
        //             cout << a << " ";
        //         cout << endl;
        //     }
        // } while (next_permutation(arr.begin(), arr.end()));
    }
    return 0;
}
