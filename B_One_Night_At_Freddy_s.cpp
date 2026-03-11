#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
    n,m,l is given..

    m anima something is there..

    they will scare me haha..

    night is of l seconds..

    every anima.. has some danger dj..

    intially they are 0..

    every sec any one of the animas will be danger++

    we have some n time stamps at which we can

    make some anima's danger = 0..

    overall danger is the max danger among all animas..

    after l sec if any has danger > x then we lose ..

    min x such that i win..

    so if n == l then res is 0

    because every sec whoever inc its danger i can make them 0..

    one strat which monsters / animas can do is evenly keep

    giving danger..

    lets say i have n time stamps..

    they will mostly equally distibute danger among n + 1

    monsters..

    because i can only destroy n monsters..

    else if < n monsters are there..

    a lot of factors :

    1) last second that  i have..

    2) n > m || n == m || n < m

    3)

    maybe we can simulate..

    so we will at max take n + 1 monsters..

    and then we need min at every second so we inc that and add

    it back..

    also max at some sec so we make that as zero..

    multiset should do..

    after the last second it is going to put all its chips

    in the max monster..




*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, l;
        cin >> n >> m >> l;
        set<int> st;
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;
            maxi = max(maxi, ele + 1);
            st.insert(ele);
        }
        multiset<int> ms;

        m = min(m, n + 1);

        for (int i = 0; i < m; i++)
        {
            ms.insert(0);
        }
        int left = n + 1;
        for (int i = 1; i <= l; i++)
        {
            auto it = ms.begin();
            int ele = *it;
            ms.erase(it);
            ms.insert(ele + 1);
            // now if this sec we have a chance, we will elim the max monster..
            if (st.count(i))
            {
                auto it1 = prev(ms.end());
                ms.erase(it1);
                ms.insert(0);
                left--;
                // now if we have more monsters than left then we stop updating the min monster right now..
                int size = ms.size();
                if (size > left && (!ms.empty()))
                {
                    auto it = ms.begin();
                    ms.erase(it);
                }
            }
        }
        int res = *ms.rbegin();
        cout << res << endl;
    }
    return 0;
}
