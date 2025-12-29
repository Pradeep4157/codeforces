#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> findallprimedivisors(int n)
{
    vector<int> result;
    for (int i = 2; i * i <= n; ++i)
    {
        while (n % i == 0)
        {
            result.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
    {
        result.push_back(n);
    }
    return result;
}

int_fast32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, k;
        cin >> x >> y >> k;
        int common = __gcd(x, y);
        // there is nothing common that needs to be removed
        if (common == 1)
        {
            vector<int> first = findallprimedivisors(x);
            vector<int> second = findallprimedivisors(y);
            sort(first.begin(), first.end());
            sort(second.begin(), second.end());
            int size1 = first.size(), size2 = second.size();
            if (first[size1 - 1] > k || second[size2 - 1] > k)
            {
                cout << -1 << endl;
                continue;
            }
            // it is possible
            // try to combine
            int res = 1;
            int i = 0;
            while (i < size1)
            {
                res++;
                int product = 1;
                while (i < size1 && product <= k)
                {
                    product *= first[i];
                    i++;
                }
                if (i == size1 && product > k)
                    res++;
            }
            i = 0;
            while (i < size2)
            {
                res++;
                int product = 1;
                while (i < size2 && product <= k)
                {
                    product *= second[i];
                    i++;
                }
                if (i == size2 && product > k)
                    res++;
            }
            cout << res << endl;
        }
        else
        {
            vector<int> zero = findallprimedivisors(common);
            vector<int> firstf = findallprimedivisors(x);
            vector<int> secondf = findallprimedivisors(y);
            unordered_map<int, int> mp1, mp2;
            for (auto a : firstf)
                mp1[a]++;
            for (auto a : secondf)
                mp2[a]++;
            for (auto a : zero)
            {
                mp1[a]--;
                if (mp1[a] == 0)
                    mp1.erase(a);
                mp2[a]--;
                if (mp2[a] == 0)
                    mp2.erase(a);
            }
            vector<int> first, second;
            for (auto a : mp1)
            {
                int freq = a.second;
                int number = a.first;
                while (freq > 0)
                {
                    freq--;
                    first.push_back(number);
                }
            }
            for (auto a : mp2)
            {
                int freq = a.second;
                int number = a.first;
                while (freq)
                {
                    freq--;
                    second.push_back(number);
                }
            }
            sort(first.begin(), first.end());
            sort(second.begin(), second.end());

            int starti = 0, startj = 0;
            int size0 = zero.size(), size1 = first.size(), size2 = second.size();
            // impossible check
            if (first[size1 - 1] > k || second[size2 - 1] > k)
            {
                cout << -1 << endl;
                continue;
            }
            int res = 0;
            while (starti < size1)
            {
                res++;
                int product = 1;
                while (starti < size1 && product <= k)
                {
                    product *= first[starti];
                    starti++;
                }
                if (starti == size1 && product > k)
                    res++;
            }
            while (startj < size2)
            {
                res++;
                int product = 1;
                while (startj < size2 && product <= k)
                {
                    product *= second[startj];
                    startj++;
                }
                if (startj == size2 && product > k)
                    res++;
            }
            cout << res << endl;
        }
    }
    return 0;
}
