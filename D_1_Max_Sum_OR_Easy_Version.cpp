#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    a consists of ele from l to r

    b also is same as a
    we need to maximize sum(a|b)

    first of all if i have 2^n then i will swap 2^n with (2^n)-1
    BECAUSE THAT MAXIMIZES THE BIT COUNTS

    OUR MAIN GOAL SHOULD BE TO FILL THE BEST BITS NOT FILLED BY CURRENT
    NUMBER

    SO IF THE RIGHT IS (2^N)-1 WE JUST REVERSE THE ARRAY

    AND EVERY  BIT IS FILLED AND WE GET (R)*(R-1)


    what about the other cases

    if the number is 2^n:
        then last two gets swapped then we go from right-2 till 1

        and keep filling 1 ...whatever we reach

    what about last case:
        for all the other cases the best which we can do is that
        we fill the bits such it equals nearest 2^ -1

*/

int nextpoweroftwominus1(int n)
{
    if (n <= 1)
        return 1;
    int msb = 63 - __builtin_clzll(n);

    long long candidate = (1LL << (msb + 1)) - 1;

    if (candidate < n)
    {

        candidate = (1LL << (msb + 2)) - 1;
    }
    return candidate;
}
vector<int> getallpoweroftwominusone(int n)
{
    vector<int> result;
    int val = 1;

    while (val <= n)
    {
        result.push_back(val);
        val = (val << 1) + 1;
    }

    return result;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int left, right;
        cin >> left >> right;
        if (right == 0)
        {
            cout << 0 << endl;
            cout << 0 << endl;
            continue;
        }
        set<int> st;
        for (int i = 0; i <= right; i++)
        {
            st.insert(i);
        }
        vector<int> arr(right + 1, -1);
        vector<int> target = getallpoweroftwominusone(right);
        int last = nextpoweroftwominus1(right);
        target.push_back(last);
        for (int i = right; i >= 0; i--)
        {
            if (arr[i] != -1)
            {
                // already filled

                continue;
            }
            for (int j = target.size() - 1; j >= 0; j--)
            {
                int req = target[j] ^ i;
                if (st.count(req))
                {
                    arr[i] = req;
                    arr[req] = i;
                    st.erase(i);
                    st.erase(req);
                    break;
                }
                if (arr[i] == -1)
                {
                    arr[i] = i;
                    st.erase(i);
                }
            }
        }
        int sum = 0;
        for (int i = 0; i <= right; i++)
        {
            sum += (arr[i] | i);
        }
        cout << sum << endl;
        for (auto a : arr)
            cout << a << " ";
        cout << endl;
        continue;
    }
    return 0;
}
