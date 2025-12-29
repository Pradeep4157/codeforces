#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


        first we will mark the safe ones using 2 pointer approach where if the current

        is 0 then we will move left or 1 we will move right else we will move both of them

        now after this we will mark all the  remaining ones with +


        now + are secured now what all is going to be ? and what  all are going

        to be - and +


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
        string s;
        cin >> s;
        vector<char> res(n);
        int left = 0, right = n - 1;
        if (n == k)
        {
            for (int i = 0; i < n; i++)
            {
                cout << '-';
            }
            cout << endl;
            continue;
        }
        int index = 0;
        while (left <= right && index < k)
        {
            if (s[index] == '0')
            {
                left++;
            }
            else if (s[index] == '1')
                right--;
            else
            {
                left++;
                right--;
            }
            index++;
        }
        for (int i = left; i <= right; i++)
        {
            res[i] = '+';
        }

        left = 0, right = n - 1;
        index = 0;
        while (left <= right && index < k)
        {
            if (s[index] == '0')
            {
                res[left] = '-';
                left++;
            }
            else if (s[index] == '1')
            {
                res[right] = '-';
                right--;
            }
            else
            {
                if (left == right)
                {
                    res[left] = '-';
                    left++;
                    right--;
                }
            }
            index++;
        }
        for (int i = 0; i < n; i++)
        {
            if (res[i] == '-' || res[i] == '+')
                continue;
            else
                res[i] = '?';
        }
        for (auto a : res)
            cout << a;
        cout << endl;
    }
    return 0;
}
