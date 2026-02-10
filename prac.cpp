#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so the question is that we can swap any 2 elements, instead of cost being 1 the cost = dist + dist - 1 where

    dist is the distance between those 2 indexes.

    so we can start iterating from the left side and if the (d[i] - i) > 0 then we can store it in set so that

    we use it to help future elements that need this index and if this element can be swapped with them.

    why because we might need to erase elements in between and in array it will take O(n)

    now for the other case where (d[i] - i) < 0 :

        for these element there should be some helper element in the  left side which can be swapped with this element

        else it is impossible because all the left elements cannot help it and this element also wants to stay at some

        left index.

        else if we get some element on the left side which can  help this index then we swap them erase that index

        from set and add the swap cost.

    NOTE :
        we are storing mirror index in the set because the set sorts in ascending order and we need closest element so

        storing with mirror will give closest left elements.

        also we will be using lower bound to find the index from which we need help because normal traversal will take O(n).





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
        {
            cin >> arr[i];
        }
        bool ok = true;
        set<int> helper_indexes;
        int total_cost = 0;
        for (int i = 0; i < n; i++)
        {

            int mirror_index = n - 1 - i;
            // here we need help..
            if ((arr[i] - i - 1) < 0)
            {

                // this element should be somewher from 0...where_it_should_be
                int where_it_should_be = arr[i] - 1;
                int curr_mirror_index = n - 1 - where_it_should_be;

                // now we find whether there is some index in helper from 0...where_it_should_be such that we can swap that..
                auto it = helper_indexes.lower_bound(curr_mirror_index);

                if (it == helper_indexes.end())
                {
                    // no one can help..
                    ok = false;
                    break;
                }
                else
                {
                    bool found = false;
                    for (; it != helper_indexes.end(); it++)
                    {
                        // now we check whether this element can be swapped ..
                        int mirror_index = *it;
                        int actual_index = n - 1 - mirror_index;
                        if ((arr[actual_index] - 1 - i) >= 0)
                        {
                            // then we can swap these two elements..
                            swap(arr[actual_index], arr[i]);
                            helper_indexes.erase(it);
                            // now cost addition..
                            int dist = i - actual_index;
                            total_cost += dist + dist - 1;
                            found = 1;
                            break;
                        }
                    }
                    if (found == false)
                    {
                        ok = false;
                        break;
                    }
                }
            }
            // we also check if the swapped / unswapped can help any future element..
            if ((arr[i] - i - 1) > 0)
            {
                // then it can help future elements..
                helper_indexes.insert(mirror_index);
            }
        }
        if (ok == false)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << total_cost << endl;
            for (auto a : arr)
                cout << a << " ";
            cout << endl;
        }
    }
    return 0;
}
