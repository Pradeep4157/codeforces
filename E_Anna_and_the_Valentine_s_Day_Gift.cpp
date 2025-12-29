#include <bits/stdc++.h>
#define int long long
using namespace std;
bool trailingzeroes(int n)
{
    string s = to_string(n);
    int size = s.size();
    if (s[size - 1] == '0')
        return 1;
    else
        return 0;
}
int zerocount(int n)
{
    string s = to_string(n);
    int size = s.size();
    int res = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        if (s[i] != '0')
            break;
        res++;
    }
    return res;
}
int countbits(int n)
{
    string s = to_string(n);
    return (int)s.size();
}
int_fast32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int bits = 0;
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            if (trailingzeroes(arr[i]))
            {
                temp.push_back(zerocount(arr[i]));
            }
            int currbits = countbits(arr[i]);
            bits += currbits;
        }
        int j = 0;
        int size = temp.size();
        bool anna = 1;
        sort(temp.rbegin(), temp.rend());
        while (j < size)
        {
            if (anna)
            {

                anna = false;
                bits -= temp[j];
            }
            else
            {
                anna = 1;
            }
            j++;
        }
        if (bits >= m + 1)
            cout << "Sasha\n";
        else
            cout << "Anna\n";
    }
    return 0;
}
