#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    there are n coins..

    k as well..

    there's a bag where we place coins..

    k actions we perf..

    in each  op we put any coin that  we have currently..

    if the sum of denominations in the bag becomes even then

    the cat takes all the coins..

    for all k from 1..n give ans max ans for each..

    if we have all evens then 0 for all

    else we take one odd and rest even ..

    if we take another odd then sum is even again

    and the cat will take all the coins

    so max odd + max even at every pos..

    so after all the even + odd odd is done the ans is 0 for everything..


    so first we take an odd number then all the evens..

    after this we have taken all the evens , now

    for all the remaining indexes we will try to use the

    prev positions to maximize this index..

    if i am at an index < n - 1 && there are atleast 2 prev values

    then i can take the last 2 values and move i+=2..








*/
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        priority_queue<int> pq;
        multiset<int> ms;
        int max_odd = -1;
        for (auto a : arr)
        {
            if (a & 1)
            {
                max_odd = max(max_odd, a);
                ms.insert(a);
            }
            else
                pq.push(a);
        }

        if (max_odd == -1)
        {
            // then just return 000
            for (int i = 0; i < n; i++)
            {
                cout << 0 << " ";
            }
            cout << endl;
            continue;
        }
        // atleast one odd we have..
        if (pq.size() == 0)
        {
            // then all odds..
            for (int i = 0; i < n; i++)
            {
                if (i % 2 == 0)
                    cout << max_odd << " ";
                else
                    cout << 0 << " ";
            }
            cout << endl;
            continue;
        }
        // now we have atleast one odd and odd even..

        // so index will def be >=2..
        vector<int> res(n, 0);
        int i = 0;
        if (max_odd != -1)
        {
            // something can be done..
            res[0] = max_odd;
            i++;
            while (i < n)
            {
                if (pq.empty())
                    break;
                int top = pq.top();
                pq.pop();
                res[i] = top;
                res[i] += res[i - 1];
                i++;
            }
        }

        while (i < n)
        {
            // if this is the last index.. we just write the max odd.

            if (i == n - 1)
            {

                i++;
            }
            else
            {
                // we have some more indexes..
                // so we will just write the last 2 values..
                res[i] = res[i - 2];
                res[i + 1] = res[i - 1];
                i += 2;
            }
        }
        for (auto a : res)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
