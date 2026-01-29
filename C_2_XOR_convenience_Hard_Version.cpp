#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/

bool is_valid(vector<int> &arr)
{
    bool valid = 1;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
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
int right_number(int n)
{
    return n >> 1;
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
        int number = 1;
        for (int i = 1; i <= n; i++)
        {
            st.insert(i);
            if (power_of_two_1(i))
                number = i;
        }

        while (index >= 0)
        {
            int right = index;
            res[index--] = number;
            number = right_number(number);
            if (number == 0)
                break;
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
        do
        {

            if (is_valid(arr))
            {
                cout << "hehehehe : ";
                for (auto a : arr)
                    cout << a << " ";
                cout << endl;
            }
        } while (next_permutation(arr.begin(), arr.end()));
        for (auto a : res)
            cout << a << " ";
        cout << endl;
        if (is_valid(res))
        {
            for (auto a : res)
                cout << a << " ";
            cout << endl;
        }
        else
            cout << -1 << endl;
    }

    return 0;
}
