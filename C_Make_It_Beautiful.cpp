#include <bits/stdc++.h>
#define int long long
using namespace std;
int powerOf2(int n)
{
    int result = 1;
    while (n > 0)
    {
        result *= 2;
        n--;
    }
    return result;
}

void find(int a, unordered_map<int, vector<int>> &mp, int index)
{
    int empty = 0;
    while (a)
    {
        if (!(a & 1))
        {
            mp[empty].push_back(index);
        }
        empty++;
        a >>= 1;
    }
    while (empty < 100)
    {
        mp[empty].push_back(index);
        empty++;
    }
}
int findbeauty(int a)
{
    int res = 0;
    while (a)
    {
        if (a & 1)
            res++;
        a >>= 1;
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
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.rbegin(), arr.rend());
        vector<int> og(arr.begin(), arr.end());
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            find(arr[i], mp, i);
        }

        bool ok = 1;
        int res = 0;
        for (int power = 0; power < 100; power++)
        {
            int dreamele = powerOf2(power + 1) - 1;
            vector<int> &indexes = mp[power];
            for (auto a : indexes)
            {
                int already = powerOf2(power) - 1;
                int req = dreamele - already;
                if (req > k)
                {
                    ok = false;
                    break;
                }
                k -= req;
                int newele = powerOf2(power + 1) - 1;
                newele -= already;
                arr[a] += newele;
            }
            if (ok == false)
                break;
        }
        for (int i = 0; i < n; i++)
        {
            res += max(findbeauty(arr[i]), findbeauty(og[i]));
        }
        cout << res << endl;
    }
    return 0;
}
