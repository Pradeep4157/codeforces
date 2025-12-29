#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    its just that the operations need not be consective

    11001
    1 , 5 , 2

    10011001
    1,4,n,5

    110011
    1,n,2,n-1,

    so the bigger one keeps eating the smaller ones


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
        string s;
        cin >> s;
        int i = 0;
        vector<int> arr;
        while (i < n)
        {
            while (i < n && s[i] == '0')
                i++;
            if (i == n)
                break;
            int j = i;
            while (j < n && s[j] == '1')
                j++;
            j--;
            arr.push_back(j - i + 1);
            i = j + 1;
        }
        bool ok = 1;
        sort(arr.rbegin(), arr.rend());
        if (!arr.empty())
        {
            int first = arr[0];
            if (arr.size() == 1 && (first == 2 || first == 3))
                ok = false;
        }
        if (ok)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
