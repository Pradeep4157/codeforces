#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    if n is 1 he cant do anything..

    sell 2 books and buy a new book ...

    if the current book is not the volume that he wanted..

    ok so order doesnt matter so we will take all the things that we have

    from 1..x..

    then we will have some extra books..

    we will use them to create next volumes.







*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
    {
        int n;
        cin >> n;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;
            mp[ele]++;
        }
        int books_left = n;
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (books_left == 0)
            {

                break;
            }
            if (mp.count(i))
            {
                // we have this book..
                // so we will read one of this..
                books_left--;
            }
            else
            {
                // we will have to sell 2 to get this one..
                if (books_left < 2)
                {

                    break;

                } // we dont have enough..
                books_left -= 2;
            }

            res++;
        }
        cout << res << endl;
    }
    return 0;
}
