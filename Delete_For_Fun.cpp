#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

        circular bs is given..

        k is starting index..

        all chars must be del..

        so after we del a char.

        next del will be one of adj..

        && if i & 1 score += c

        else score -= c ..

        now rem score should be +ve

        so we can see it as maximization..

        problem..


        if imp.. return -1

        else return sequence..

        do we have choices..

        or is it def..

        it doesnt depend on index..

        but on move..

        so first is def..


        then we have 2 choices..

        maybe sometimes del 0 is beneficial ?

        if - then maybe we def del..

        else do we del  0 in  pos move ?

        00101010


        something should be def..

        i can have a deque..

        right one i will push from end..

        left one at front..

        then for each move..

        if i choose to remove ..

        one thing is sure that i will try

        to use 1 at odd times..

        that is enough ??

        if at odd both are 1..

        then just use any one of them..


        we cant decide  blindly because after every deletion res must be pos..

        choices matter...

        let say left,right == 1 1





*/
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
        string s;
        k--;
        cin >> s;
        deque<int> dq;
        int res = (s[k] == '1') ? 1 : 0;
        int move = 2;

        dq.push_front((k - 1 + n) % n);
        dq.push_back((k + 1) % n);
        bool ok = 1;
        vector<int> ans;
        ans.push_back(k + 1);
        while (move <= n)
        {
            int left = dq.front();
            int right = dq.back();

            if (move % 2 == 0)
            {
                // i will try to remove a zero..
                // it doesnt matter which one..
                if (s[left] == '0')
                {
                    dq.pop_front();
                    int l = (left - 1 + n) % n;
                    dq.push_front(l);
                    ans.push_back(left + 1);
                }
                else if (s[right] == '0')
                {
                    dq.pop_back();
                    int r = (right + 1) % n;
                    dq.push_back(r);
                    ans.push_back(right + 1);
                }
                else
                {
                    // now both are ones..

                    // we will remove any one..

                    // maybe left..
                    dq.pop_front();
                    int l = (left - 1 + n) % n;
                    dq.push_front(l);
                    res--;
                    ans.push_back(left + 1);
                }
            }
            else
            {
                // now whatever gies..
                if (s[left] == '1')
                {
                    dq.pop_front();
                    int l = (left - 1 + n) % n;
                    dq.push_front(l);
                    res++;
                    ans.push_back(left + 1);
                }
                else if (s[right] == '1')
                {
                    dq.pop_back();
                    int r = (right + 1) % n;
                    dq.push_back(r);
                    res++;
                    ans.push_back(right + 1);
                }
                else
                {
                    // now anyone..
                    dq.pop_front();
                    int l = (left - 1 + n) % n;
                    dq.push_front(l);
                    ans.push_back(left + 1);
                }
            }
            if (res <= 0)
            {
                ok = false;
                break;
            }
            move++;
        }
        if (res <= 0)
            ok = false;
        if (ok == false)
            cout << -1 << endl;
        else
        {
            for (auto a : ans)
                cout << a << " ";
            cout << endl;
        }
    }
    return 0;
}
