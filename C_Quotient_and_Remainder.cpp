#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    two arrays are given..

    k as well..

    ok so we select y < x <= k

    then qi = x / y if there remove..

    also ri = x mod y should also be there..

    so in r only values from 0.. y - 1 can be removed..

    and values from 1..k can be removed from q..

    all the values from k + 1 .. whatever are useless..

    only this thing is def..

    so now what all can i pair..

    ri * qi <= k  then they can be paired..

    ok so y ! = qi because then qi can never be

    acheived..

    also ..

    is qi + 1 == y is what we will choose always ?


    so qi + 1 is the min y && y*ri + qi is the

    min x possible..

    i think it is always better to  pair biggest

    ri with smallest qi

    because

    (qi + 1 )*ri + qi (eq1)is the min value that we can

    get..

    which satisfies both the case..

    also eq 1 should be <=k  so we will have to minimize

    the eqn..

    so for that ri there is no better qi



*/
int k;
bool possible(int qi, int ri)
{

    int res = (qi + 1) * ri + (qi);
    return (res <= k);
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
        cin >> n >> k;
        priority_queue<int> maxi;
        priority_queue<int, vector<int>, greater<int>> mini;
        for (int i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;
            maxi.push(ele);
        }
        for (int i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;
            mini.push(ele);
        }
        int res = 0;
        while (true)
        {
            if (mini.empty() || maxi.empty())
                break;
            // else we have some to combine..
            int ri = maxi.top();
            maxi.pop();
            int qi = mini.top();
            mini.pop();
            // now we will see whether we can combine..

            if (possible(qi, ri))
            {
                res++;
            }
            else
            {
                mini.push(qi);
            }
        }
        cout << res << endl;
    }
    return 0;
}
