#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    min is min diff one of the k strings..

    if i have to reduce that ..

    some prefix should be repeated x times such that len == n..

    so among the 26 chars i choose a char..

    and then there are some points where it repeats..

    so for these 2 points..

    i will have to first see whether j + 1 ..n the size is same as i +1..j - 1

    if yes then check whether some char is there that is same from here

    for k and h if yes then add them

    so ig its dp..

    so at every pos i select one of the chars..

    if i choose to take this ..


    i can put anything..

    so i select some j for i and then from j + 1.. end of the array

    size should be same and if any char is same then i use that..

    so next is the part where the next pattern starts..

    so the pattern should be 0..next - 1,next..2*next -1...2*next...3*next -1..





*/
vector<int> all_factors(int n)
{
    vector<int> divs;

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            divs.push_back(i);
            if (i != n / i)
                divs.push_back(n / i);
        }
    }

    sort(divs.begin(), divs.end());
    return divs;
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
        vector<vector<int>> arr(n, vector<int>(26));
        for (int i = 0; i < k; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < n; j++)
            {
                int curr = s[j] - 'a';
                arr[j][curr]++;
            }
        }

        int max_patter = LLONG_MAX;
        string res;
        vector<int> factors = all_factors(n);
        for (auto len : factors)
        {

            if (n % len)
                continue;

            // we can form something..
            string curr;
            int curr_index = 0;
            bool can_make = 1;

            while (curr_index < len)
            {

                bool found = false;
                for (int i = 0; i < 26; i++)
                {

                    // i want to add this char at this pos..
                    // we will check whether this is present in every pattern or not.
                    bool ok = 1;
                    for (int j = curr_index; j < n; j += len)
                    {

                        if (arr[j][i] == 0)
                        {

                            ok = false;
                            break;
                        }
                    }
                    // if ok is true then we add this char heree..

                    if (ok == 1)
                    {

                        found = 1;
                        curr += (i + 'a');

                        break;
                    }
                }
                if (found == false)
                {

                    can_make = false;
                    break;
                }

                curr_index++;
            }
            if (can_make)
            {

                res = curr;
                break;
            }
        }
        string temp = res;

        while (res.size() < n)
        {
            res += temp;
        }
        cout << res << endl;
    }
    return 0;
}
