#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    odd indexes are a and even is b..

    ababa

    ababa
    aabab
    aabba

    so i will have some rem a and rem b..

    which can be used in the question marks..

    now ..

    initially i have n + 1 /  2  a's and n/2 b's

    just subtract the already used ones..

    and then from ababa...

    start checking if curr string is poss..

    add it in a dq ig..

    now when its not a ?

    you have the answer if front and back both are not this char then return false..

    else pop one of them..

    now for ? :

        it can be front or back..

        if both are same we can proceed :

        we can still pop any ?

        because if we have option of both then there is another ?

        ababa
        ?b?ab
        abab
        ?bab
        ?aba

        abab

        abab
        baba
        abba
        baab

        ababab

        first check if removing chars both should be >= 0..

        maybe the logic is that at positions where remaining len is even we cant put

        two same things ..

        lets say that when i have a ? i dont do any thing and move on..

        now after all these ? subarray end there is some char..


    so the problem is when we have actual[i] != actual[j]

    we need to fill this position..

    there are 2 options..

    abababa

    abab
    abba
    ababa

    at even positions it cant be two b's

    it can only happen at odd positions..

    for even positions..

    ababa

    abaab
    abab

    only even position where a can happen twice is 0 when n is odd.

    else


*/
string actual;
int n;
vector<vector<int>> dp;
bool recursion(int i, int j, string &s)
{
    bool ok = true;
    deque<char> dq;
    bool odd = 1;
    for (auto a : actual)
        dq.push_back(a);
    int a_count = 0, b_count = 0;
    for (auto a : actual)
    {
        if (a == 'a')
            a_count++;
        else
            b_count++;
    }
    for (int i = 0; i < n; i++)
    {

        if (abs(a_count - b_count) > 1)
        {
            return false;
        }
        if (s[i] == 'a')
            a_count--;
        else if (s[i] == 'b')
            b_count--;
        else
        {
            if ((i + 1 < n))
            {
                if (s[i + 1] == 'b' || a_count > b_count)
                    a_count--;
                else
                    b_count--;
            }
        }

        if (abs(a_count - b_count) > 1)
        {
            return false;
        }
    }
    return 1;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {

        cin >> n;
        string s;
        cin >> s;
        actual.clear();

        for (int i = 0; i < n; i++)
        {
            if (i & 1)
                actual += 'b';
            else
                actual += 'a';
        }
        bool res = (recursion(0, n - 1, s));
        cout << ((res) ? "YES" : "NO") << endl;
    }
    return 0;
}
