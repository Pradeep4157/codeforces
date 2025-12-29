#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
signed main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        set<int> good;
        for (int i = 0; i < k; i++)
        {
            int index;
            cin >> index;
            index--;
            good.insert(index);
        }
        int res = 0;
        if (m == 1)
        {
            cout << 1 << endl;
            continue;
        }
        for (int i = 0; i < (1 << n); i++)
        {
            vector<int> arr(n, 1);
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                    arr[j] = 2;
            }
            bool alice = 1;
            while (arr.size() > 1)
            {

                if (alice)
                {
                    alice = 0;
                    int bestindex = -1;
                    int bestres = LLONG_MIN;
                    for (auto a : good)
                    {
                        if (a > arr.size())
                            continue;
                        int curr = 0;
                        if (arr[a] == 2)
                            curr--;
                        for (int j = a + 1; j < arr.size(); j++)
                        {
                            if (good.count(j))
                            {
                                if (arr[j] == 2)
                                {
                                    curr++;
                                }
                                if (j + 1 < arr.size() && arr[j + 1] == 2)
                                    curr--;
                            }
                        }
                        if (curr >= bestres)
                        {
                            bestres = curr;
                            bestindex = a;
                        }
                    }
                    arr.erase(arr.begin() + bestindex);
                }
                else
                {
                    alice = 1;
                    int bestres = LLONG_MIN;
                    int bestindex = -1;
                    for (auto a : good)
                    {
                        if (a > arr.size())
                            continue;
                        int curr = 0;
                        if (arr[a] == 1)
                            curr--;
                        for (int j = a + 1; j < arr.size(); j++)
                        {
                            if (good.count(j))
                            {
                                if (arr[j] == 1)
                                    curr++;
                                if (j + 1 < arr.size() && arr[j + 1] == 1)
                                    curr--;
                            }
                        }
                        if (curr >= bestres)
                        {
                            bestres = curr;
                            bestindex = a;
                        }
                    }
                    arr.erase(arr.begin() + bestindex);
                }
            }
            res = (res + arr[0]) % MOD;
        }
        cout << res % MOD << endl;
    }
}