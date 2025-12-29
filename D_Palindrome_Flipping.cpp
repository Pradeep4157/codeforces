#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
    2 binary strings are given..

    l , r  this l..r should be palindrome..

    flip all the bits..

    finally we have to make s == t ...

    in at max 2n of the above op...

    if impossible return -1..

    n<=100 ..

    to flip a char i need at max two adj chars..

    n > 4


  so the goal is transform s - > 0000 in n moves and from there to t in <=n moves..

    how do we make all 4 len substrings to 0000..



    1010101
    0100101
    0111101
    0000101
    0000010
    0001110
    0000000
    1110000
    0010000
    0101000
    0101110
    0100000

    0101010




    for every 4 len substr in s we are converting that to t in at max 6 op allowed is 8..

    now the cause for exceeding k is last 1/2/3 chars that are left these can take

    6 op..

    which exceeds k .

    if last substring len is 3 its enough that we make it all 0..

    for 2 also all the operations are 2 op only so that is also enough..

    for 1 len is where we get problem because it takes 1 extra op..

    for this  case only 2 op is req.. either make it 0 or make it 1..

    01
    so the extra k is being caused because of the last remaining elements..

    when can we do..

    when last 3 are there we can convert to 0.. && also we can convert them back..

    same for last 2 elements as well..

    becuase it might take at max 3 steps ..

    && remaining also take at max 3 steps..

    so min is like 6 3 + 3 = 6 for zero conversion && after that also i can do that..

    the only problem is 1 len that is rem that too 5 because in remaining i will have enough ones saved to use it here..

    for len 5 we can do diff case..

    here last char will be changed to 0 only if t[n-1] is also zero..

    so if last char is not same then we will take 3 (for first 4 chars) + 3( for last char to zero) + 3 (for first 4 char again..)

    and for other case also at max 9 op ...

    this should work...








*/
vector<string> patterns = {"1000", "0100", "0010", "0001", "1100", "1010", "1001", "0110", "0101", "0011", "1110", "1011", "1101",
                           "0111", "1111"};
vector<vector<int>> res;
void pat0(int i, bool valid)
{
    // 1000->1110->0000

    if (valid)
    {
        // then 0..t
        res.push_back({i, i + 2});
        res.push_back({i + 1, i + 2});
    }
    else
    {
        // then s..0
        res.push_back({i + 1, i + 2});
        res.push_back({i, i + 2});
    }
}
void pat1(int i, bool valid)
{
    // 0100->0111->0000
    if (valid)
    {
        // 00..t
        res.push_back({i + 1, i + 3});
        res.push_back({i + 2, i + 3});
    }
    else
    {
        res.push_back({i + 2, i + 3});
        res.push_back({i + 1, i + 3});
    }
}
void pat2(int i, bool valid)
{
    // 0010->1110->0000
    vector<vector<int>> arr = {{i, i + 1}, {i, i + 2}};
    if (valid)
    {
        for (int j = arr.size() - 1; j >= 0; j--)
        {
            res.push_back(arr[j]);
        }
    }
    else
    {
        for (auto a : arr)
        {
            res.push_back(a);
        }
    }
}
void pat3(int i, bool valid)
{
    // 0001->0111->0000
    vector<vector<int>> arr = {{i + 1, i + 2}, {i + 1, i + 3}};
    if (valid)
    {
        for (int j = arr.size() - 1; j >= 0; j--)
        {
            res.push_back(arr[j]);
        }
    }
    else
    {
        for (auto a : arr)
        {
            res.push_back(a);
        }
    }
}
void pat4(int i, bool valid)
{
    //  1100->0000
    vector<vector<int>> arr = {{i, i + 1}};
    if (valid)
    {
        for (int j = arr.size() - 1; j >= 0; j--)
        {
            res.push_back(arr[j]);
        }
    }
    else
    {
        for (auto a : arr)
        {
            res.push_back(a);
        }
    }
}
void pat5(int i, bool valid)
{
    // 1010->0100->0111->0000
    vector<vector<int>> arr = {{i, i + 2}, {i + 2, i + 3}, {i + 1, i + 3}};
    if (valid)
    {
        for (int j = arr.size() - 1; j >= 0; j--)
        {
            res.push_back(arr[j]);
        }
    }
    else
    {
        for (auto a : arr)
        {
            res.push_back(a);
        }
    }
}

void pat6(int i, bool valid)
{
    // 1001->1111->0000
    vector<vector<int>> arr = {{i + 1, i + 2}, {i, i + 3}};
    if (valid)
    {
        for (int j = arr.size() - 1; j >= 0; j--)
        {
            res.push_back(arr[j]);
        }
    }
    else
    {
        for (auto a : arr)
        {
            res.push_back(a);
        }
    }
}
void pat7(int i, bool valid)
{
    // 0110->0000

    vector<vector<int>> arr = {{i + 1, i + 2}};
    if (valid)
    {
        for (int j = arr.size() - 1; j >= 0; j--)
        {
            res.push_back(arr[j]);
        }
    }
    else
    {
        for (auto a : arr)
        {
            res.push_back(a);
        }
    }
}
void pat8(int i, bool valid)
{
    // 0101->0010->1110->0000

    vector<vector<int>> arr = {{i + 1, i + 3}, {i, i + 1}, {i, i + 2}};
    if (valid)
    {
        for (int j = arr.size() - 1; j >= 0; j--)
        {
            res.push_back(arr[j]);
        }
    }
    else
    {
        for (auto a : arr)
        {
            res.push_back(a);
        }
    }
}
void pat9(int i, bool valid)
{
    // 0011->0000
    vector<vector<int>> arr = {{i + 2, i + 3}};
    if (valid)
    {
        for (int j = arr.size() - 1; j >= 0; j--)
        {
            res.push_back(arr[j]);
        }
    }
    else
    {
        for (auto a : arr)
        {
            res.push_back(a);
        }
    }
}
void pat10(int i, bool valid)
{
    // 1110->0000

    vector<vector<int>> arr = {{i, i + 2}};
    if (valid)
    {
        for (int j = arr.size() - 1; j >= 0; j--)
        {
            res.push_back(arr[j]);
        }
    }
    else
    {
        for (auto a : arr)
        {
            res.push_back(a);
        }
    }
}
void pat11(int i, bool valid)
{
    // 1011->1000->1110->0000

    vector<vector<int>> arr = {{i + 2, i + 3}, {i + 1, i + 2}, {i, i + 2}};
    if (valid)
    {
        for (int j = arr.size() - 1; j >= 0; j--)
        {
            res.push_back(arr[j]);
        }
    }
    else
    {
        for (auto a : arr)
        {
            res.push_back(a);
        }
    }
}

void pat12(int i, bool valid)
{
    // 1101->0001->1111->0000

    vector<vector<int>> arr = {{i, i + 1}, {i, i + 2}, {i, i + 3}};
    if (valid)
    {
        for (int j = arr.size() - 1; j >= 0; j--)
        {
            res.push_back(arr[j]);
        }
    }
    else
    {
        for (auto a : arr)
        {
            res.push_back(a);
        }
    }
}

void pat13(int i, bool valid)
{
    // 0111->0000
    vector<vector<int>> arr = {{i + 1, i + 3}};

    if (valid)
    {
        for (int j = arr.size() - 1; j >= 0; j--)
        {
            res.push_back(arr[j]);
        }
    }
    else
    {
        for (auto a : arr)
        {
            res.push_back(a);
        }
    }
}
void pat14(int i, bool valid)
{

    // 1111->0000
    vector<vector<int>> arr = {{i, i + 3}};
    if (valid)
    {
        for (int j = arr.size() - 1; j >= 0; j--)
        {
            res.push_back(arr[j]);
        }
    }
    else
    {
        for (auto a : arr)
        {
            res.push_back(a);
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        res.clear();
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        int i = 3;
        while (i < n)
        {
            string curr = s.substr(i - 3, 4);
            int start = i - 3;
            for (int j = 0; j < patterns.size(); j++)
            {
                if (curr == patterns[j])
                {
                    if (j == 0)
                    {
                        pat0(start, 0);
                    }
                    else if (j == 1)
                    {
                        pat1(start, 0);
                    }
                    else if (j == 2)
                    {
                        pat2(start, 0);
                    }
                    else if (j == 3)
                    {
                        pat3(start, 0);
                    }
                    else if (j == 4)
                    {
                        pat4(start, 0);
                    }
                    else if (j == 5)
                    {
                        pat5(start, 0);
                    }
                    else if (j == 6)
                    {
                        pat6(start, 0);
                    }
                    else if (j == 7)
                    {
                        pat7(start, 0);
                    }
                    else if (j == 8)
                    {
                        pat8(start, 0);
                    }
                    else if (j == 9)
                    {
                        pat9(start, 0);
                    }
                    else if (j == 10)
                    {
                        pat10(start, 0);
                    }
                    else if (j == 11)
                    {
                        pat11(start, 0);
                    }
                    else if (j == 12)
                    {
                        pat12(start, 0);
                    }
                    else if (j == 13)
                    {
                        pat13(start, 0);
                    }
                    else if (j == 14)
                    {
                        pat14(start, 0);
                    }
                    s[i] = '0', s[i - 1] = '0', s[i - 2] = '0', s[i - 3] = '0';
                }
            }
            i += 4;
        }
        i -= 4;
        string last = t.substr(n - 4, 4);
        // here we are converting last 4 chars of s to 0000
        if (i != n - 1)
        {
            i++;
            // now we will store the rem chars..
            string last;
            while (i < n)
            {
                last += t[i];
                i++;
            }
            i = n - 1;
            string curr = s.substr(i - 3, 4);
            int start = i - 3;

            for (int j = 0; j < patterns.size(); j++)
            {

                if (curr == patterns[j])
                {

                    if (j == 0)
                    {
                        pat0(start, 0);
                    }
                    else if (j == 1)
                    {
                        pat1(start, 0);
                    }
                    else if (j == 2)
                    {
                        pat2(start, 0);
                    }
                    else if (j == 3)
                    {
                        pat3(start, 0);
                    }
                    else if (j == 4)
                    {
                        pat4(start, 0);
                    }
                    else if (j == 5)
                    {
                        pat5(start, 0);
                    }
                    else if (j == 6)
                    {
                        pat6(start, 0);
                    }
                    else if (j == 7)
                    {
                        pat7(start, 0);
                    }
                    else if (j == 8)
                    {
                        pat8(start, 0);
                    }
                    else if (j == 9)
                    {
                        pat9(start, 0);
                    }
                    else if (j == 10)
                    {
                        pat10(start, 0);
                    }
                    else if (j == 11)
                    {
                        pat11(start, 0);
                    }
                    else if (j == 12)
                    {
                        pat12(start, 0);
                    }
                    else if (j == 13)
                    {
                        pat13(start, 0);
                    }
                    else if (j == 14)
                    {
                        pat14(start, 0);
                    }
                    s[i] = '0', s[i - 1] = '0', s[i - 2] = '0', s[i - 3] = '0';
                }
            }
            // now s is totally 0000... first we will convert last rem chars to 4
            // now first add leading zeros to last..
            while (last.size() < 4)
            {
                last = '0' + last;
            }
            // now we have what we need..
            // we will change 0000 to whatever it is ..
            // so boolean will be true..
            curr = last;
            for (int j = 0; j < patterns.size(); j++)
            {
                if (curr == patterns[j])
                {
                    if (j == 0)
                    {
                        pat0(start, 1);
                    }
                    else if (j == 1)
                    {
                        pat1(start, 1);
                    }
                    else if (j == 2)
                    {
                        pat2(start, 1);
                    }
                    else if (j == 3)
                    {
                        pat3(start, 1);
                    }
                    else if (j == 4)
                    {
                        pat4(start, 1);
                    }
                    else if (j == 5)
                    {
                        pat5(start, 1);
                    }
                    else if (j == 6)
                    {
                        pat6(start, 1);
                    }
                    else if (j == 7)
                    {
                        pat7(start, 1);
                    }
                    else if (j == 8)
                    {
                        pat8(start, 1);
                    }
                    else if (j == 9)
                    {
                        pat9(start, 1);
                    }
                    else if (j == 10)
                    {
                        pat10(start, 1);
                    }
                    else if (j == 11)
                    {
                        pat11(start, 1);
                    }
                    else if (j == 12)
                    {
                        pat12(start, 1);
                    }
                    else if (j == 13)
                    {
                        pat13(start, 1);
                    }
                    else if (j == 14)
                    {
                        pat14(start, 1);
                    }
                }
            }
        }

        // now 000.. t

        i = 3;
        while (i < n)
        {
            string curr = t.substr(i - 3, 4);
            int start = i - 3;
            for (int j = 0; j < patterns.size(); j++)
            {
                if (curr == patterns[j])
                {
                    if (j == 0)
                    {
                        pat0(start, 1);
                    }
                    else if (j == 1)
                    {
                        pat1(start, 1);
                    }
                    else if (j == 2)
                    {
                        pat2(start, 1);
                    }
                    else if (j == 3)
                    {
                        pat3(start, 1);
                    }
                    else if (j == 4)
                    {
                        pat4(start, 1);
                    }
                    else if (j == 5)
                    {
                        pat5(start, 1);
                    }
                    else if (j == 6)
                    {
                        pat6(start, 1);
                    }
                    else if (j == 7)
                    {
                        pat7(start, 1);
                    }
                    else if (j == 8)
                    {
                        pat8(start, 1);
                    }
                    else if (j == 9)
                    {
                        pat9(start, 1);
                    }
                    else if (j == 10)
                    {
                        pat10(start, 1);
                    }
                    else if (j == 11)
                    {
                        pat11(start, 1);
                    }
                    else if (j == 12)
                    {
                        pat12(start, 1);
                    }
                    else if (j == 13)
                    {
                        pat13(start, 1);
                    }
                    else if (j == 14)
                    {
                        pat14(start, 1);
                    }
                }
            }
            i += 4;
        }

        cout << res.size() << endl;

        for (auto a : res)
        {
            for (auto b : a)
            {
                int curr = b + 1;
                curr = max(0LL, curr);
                curr = min(curr, n);
                cout << curr << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
