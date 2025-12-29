#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        if (n & 1)
        {
            int count = 0;
            // first we will check the places where a[i]==b[i];
            for (int i = 0; i < n; i++)
            {
                if (a[i] == b[i])
                    count++;
            }
            if (count != 1)
            {
                cout << -1 << endl;
                continue;
            }
            // check whether b[i] is already mapped to a[i]
            unordered_map<int, int> mp;
            bool possible = 1;
            for (int i = 0; i < n; i++)
            {
                // 52% sure
                if (mp.find(b[i]) == mp.end())
                {
                    mp[a[i]] = b[i];
                }
                else
                {
                    // the only mapping that i can find is from b[i] to a[i]
                    int second = mp[b[i]];
                    if (second != a[i])
                    {
                        possible = false;
                        break;
                    }
                }
            }
            if (possible == false)
            {
                cout << -1 << endl;
                continue;
            }
            // first keeping a[i]==b[i] term at the centre
            int mid = n / 2;
            vector<pair<int, int>> res;
            if (a[mid] != b[mid])
            {
                // need to place equal element at the centre
                for (int i = 0; i < n; i++)
                {
                    if (a[i] == b[i])
                    {
                        int centrea = a[mid];
                        int centreb = b[mid];
                        int curr = a[i];
                        a[mid] = curr;
                        b[mid] = curr;
                        a[i] = centrea;
                        b[i] = centreb;
                        res.push_back({i, mid});
                        break;
                    }
                }
            }
            // making mirror elements equal
            unordered_map<int, int> bs;
            for (int i = 0; i < n; i++)
            {
                bs[b[i]] = i;
            }

            for (int i = 0; i < n; i++)
            {
                int currindex = bs[a[i]];
                int mirror = n - i - 1;
                if (currindex != mirror)
                {
                    res.push_back({mirror, currindex});
                    int acurr = a[currindex];
                    int amirror = a[mirror];
                    int bcurr = b[currindex];
                    int bmirror = b[mirror];
                    a[mirror] = acurr;
                    a[currindex] = amirror;
                    b[mirror] = bcurr;
                    b[currindex] = bmirror;
                    bs[bcurr] = mirror;
                    bs[bmirror] = currindex;
                }
            }
            cout << res.size() << endl;
            for (auto a : res)
            {
                cout << a.first + 1 << " " << a.second + 1 << endl;
            }
        }
        else
        {
            int count = 0;
            // checking whether no a[i]==b[i]
            for (int i = 0; i < n; i++)
            {
                if (a[i] == b[i])
                {
                    count++;
                }
            }
            if (count != 0)
            {
                cout << -1 << endl;
                continue;
            }
            // check whether b[i] is already mapped to a[i]
            unordered_map<int, int> mp;
            bool possible = 1;
            for (int i = 0; i < n; i++)
            {
                // 52% sure
                if (mp.find(b[i]) == mp.end())
                {
                    mp[a[i]] = b[i];
                }
                else
                {
                    // the only mapping that i can find is from b[i] to a[i]
                    int second = mp[b[i]];
                    if (second != a[i])
                    {
                        possible = false;
                        break;
                    }
                }
            }
            if (possible == false)
            {
                cout << -1 << endl;
                continue;
            }
            // making mirror elements equal
            unordered_map<int, int> bs;
            int mid = n / 2;
            vector<pair<int, int>> res;
            for (int i = 0; i < n; i++)
            {
                bs[b[i]] = i;
            }

            for (int i = 0; i < n; i++)
            {
                int currindex = bs[a[i]];
                int mirror = n - i - 1;
                if (currindex != mirror)
                {
                    res.push_back({mirror, currindex});
                    int acurr = a[currindex];
                    int amirror = a[mirror];
                    int bcurr = b[currindex];
                    int bmirror = b[mirror];
                    a[mirror] = acurr;
                    a[currindex] = amirror;
                    b[mirror] = bcurr;
                    b[currindex] = bmirror;
                    bs[bcurr] = mirror;
                    bs[bmirror] = currindex;
                }
            }
            cout << res.size() << endl;
            for (auto a : res)
            {
                cout << a.first + 1 << " " << a.second + 1 << endl;
            }
        }
    }
    return 0;
}
    