#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so to make all charecters same :

    either the string will be 000.. or 111...

    so to change a char at index i

    if we are planning to change it from the  left side then

    operations = elements before that + 1 + elements before that

    same is if we plan to change all the rights first

    so if we plan to change all to zeroes for every i where there 's 1

    we can do  res = min ( res , suffix [ next one ] + prefix [i] ,
    suffix [ i ] + prefix [ prev one])

    same for zero

    we dont need prefix and suffix again && again

    we can make a fucntion that will always do it for '1' and call

    the func twice with swapped values


    its not elements before this , but elements between this and

    prevone or nextone





*/

int find(string s)
{
    int n = s.size();

    vector<int> prefix(n), suffix(n);
    int prevone = -1;
    for (int i = 0; i < n; i++)
    {

        if (s[i] == '1')
        {
            int prevele = i - prevone - 1;
            prefix[i] = 2 * prevele + 1;
            prevone = i;
        }
    }
    int nextone = n;
    for (int i = n - 1; i >= 0; i--)
    {

        if (s[i] == '1')
        {

            int eleafter = nextone - i - 1;

            suffix[i] = 2 * eleafter + 1;

            nextone = i;
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {

        sum += prefix[i];
        prefix[i] = sum;
    }

    sum = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        sum += suffix[i];
        suffix[i] = sum;
    }

    prevone = -1;
    int res = LLONG_MAX;
    for (int i = 0; i < n; i++)
    {

        if (s[i] == '1')
        {
            // we either try to format all the ele after this

            int prevop = 0;
            if (prevone != -1)
                prevop += prefix[prevone];

            int nextop = suffix[i];
            res = min(res, prevop + nextop);
            prevone = i;
        }
    }
    nextone = -1;
    for (int i = n - 1; i >= 0; i--)
    {

        if (s[i] == '1')
        {
            int nextop = 0;
            if (nextone != -1)
            {
                nextop += suffix[nextone];
            }
            int prevop = prefix[i];
            res = min(res, prevop + nextop);
            nextone = i;
        }
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
        int n;
        cin >> n;
        string s;
        cin >> s;
        map<char, int> mp;
        for (auto a : s)
            mp[a]++;

        if (mp.size() == 1)
        {
            cout << 0 << endl;
            continue;
        }
        int res1 = find(s);

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                s[i] = '1';
            else
                s[i] = '0';
        }
        int res2 = find(s);

        cout << min(res1, res2) << endl;
    }
    return 0;
}
