#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


        should i find the useless sets

        if i do that then i can use them to make variations

        if this useless sets count is greater than 1 then it is possible


        there is no useless sets because all the elements are
        between 1 and m



        i just need to  know for 3 ways:
            when cant be there 3 ways:
                i need 2 useless sets without which also i
                can form the whole array
                if i find them i can make without them and including
                them
*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<map<int, int>> arr(n);
        map<int, int> mp;
        map<int, int> mp1;
        int useless = 0;
        for (int i = 0; i < n; i++)
        {
            int size;
            cin >> size;
            bool useful = 0;
            for (int j = 0; j < size; j++)
            {
                int ele;
                cin >> ele;
                mp[ele]++;
                arr[i][ele]++;
            }
        }
        bool ok = 1;
        for (int i = 1; i <= m; i++)
        {
            if (mp.find(i) == mp.end())
            {
                ok = false;
                break;
            }
        }
        for (auto a : arr)
        {
            bool useful = 0;
            for (auto b : a)
            {
                int number = b.first;
                int freq = b.second;
                int req = mp[number];
                if (freq >= req)
                {
                    useful = 1;
                    break;
                }
            }
            if (useful == 0)
            {
                useless++;
            }
        }
        if (useless < 2)
            ok = false;
        cout << ((ok) ? "YES" : "NO") << endl;
    }
    return 0;
}
