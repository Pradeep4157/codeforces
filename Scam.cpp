#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    array is given..

    each is pos or - 1..

    guarenteed that first is not -1 .

    if ai is not -1 then that person

    has voted ai ..

    else he considers some j < i with aj not -1.

    still dont know who does he vote..

    ok so from the prefix if there is some

    v which is max then this -1 will vote

    him else he wont vote anyone..

    ok so array can be rearranged..

    -1 values will be at their places..

    only known values can be rearranged..

    some greedy is


    i would try to put all the x's in the front

    obv..

    now after this ..

    once x's are finished..

    we also need to ensure that

    we try to put the values that have least

    occured till now..

    so pq+ max x...

    so we need min as well as max..

    so not pq but set of pair will do

    now at every step..

    if it is a -1 ..

    now we check the end of the set..

    and inc the amount of that ..

    do we do it blindly i dont think so. .

    because if two st elements have the same

    freq then we wont inc ..


    so we take the top 2 elements..

    and if the freq is same..

    we just push them and continue..

    else we inc the top freq and push them back..

    now for remaining elements..

    if we have some x's left then we would want

    to inc x ..

    before all of this we wil first only lay

    down the x's in the arr..

    and then simulate the process till i

    and then from i + 1 onwards we will do this

    pq method..

    now if -1 case is same as above

    if st.size is 1 inc the back ele..

    else check..

    if max inc.

    else continue..

    now for non - 1 ele...

    if x is left we still push it st size will still

    be 1 only..

    else ..

    we dont have x left..

    so what do we do ..

    we inc.. the

    i can store rem elements in min heap with turn numbers

    and whatever elements turn number is min will be at top

    after i use if ele doesnt have more we dont push it in pq.

    else we inc turn and push..


    so for -1 it doesnt depend on

    so in the question we arent supposed to count the -1s that we get

    along the way..

    they can be stored in a diff map..

    else it is just simulation

    where we try to inc x as much as we can by moving using it as front

    as possible..

    if emp..

        then we use same min heap turn based approach to choose which ele

        to take


    now when -1 is there ..

    then the same approach..





*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {

        int n, x;
        cin >> n >> x;

        int count = 0;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];

            if (arr[i] == x)
                count++;
        }

        // now we need map

        map<int, int> mp;
        map<int, int> extra;
        for (auto a : arr)
            mp[a]++;

        // now we alse need set..

        set<pair<int, int>> st;
        if (count == 0)
        {
            // no way this nigga wins..
            cout << "No" << endl;
            continue;
        }

        // now we have some people voting for him.

        // first we will store the turn of other candidates..
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto a : mp)
        {
            if (a.first != x && a.first != -1)
            {

                pq.push({0, a.first});
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == -1)
            {
                // we first check are we alone..
                if (st.empty())
                {
                    continue;

                    // theres no one to vote..
                }
                else if (st.size() == 1)
                {

                    // then only our x is there...

                    extra[x]++;
                }
                else
                {
                    // we have more candidates..

                    // maybe..
                    auto it = st.end();
                    it--;
                    auto first = *it;
                    auto it1 = prev(it);

                    auto second = *it1;
                    if (first.first == second.first)
                    {
                        // no one gets any vote..

                        continue;
                    }
                    else
                    {
                        // first one gets the vote..
                        extra[first.second]++;
                    }
                }
            }
            else
            {
                // so now for woke candidates..

                // we will try to inc x only ..

                if (count > 0)
                {
                    // then we just inc x..
                    if (st.empty())
                    {
                        st.insert({1, x});
                        count--;
                        continue;
                    }

                    // we are trying to inc freq of x..
                    auto it = st.end();
                    it--;
                    auto p = *it;
                    st.erase(it);
                    p.first++;
                    st.insert(p);
                    count--;
                }
                else
                {
                    // we need some looser candidatee..

                    auto top = pq.top();
                    pq.pop();
                    // this is the weakest candidate..
                    // we will use this..

                    int candidate = top.second;
                    int timesused = top.first;
                    st.erase({timesused, candidate});
                    // now we will update it ..

                    st.insert({timesused + 1, candidate});

                    // now maybe in future we can still use this nigga...

                    if (mp[candidate] > (timesused + 1))
                    {
                        // then only we can use this..

                        pq.push({timesused + 1, candidate});
                    }
                    // else this candidate has served as much as he could..
                }
            }
        }
        // now after all the voting..

        // if theres only one candidate..

        if (st.size() == 1)
        {
            // we won!!
            cout << "Yes" << endl;
        }
        else
        {
            // maybe we have lost / tied.
            int xfreq = extra[x];
            for (auto a : st)
            {
                if (a.second == x)
                {
                    xfreq += a.first;
                }
            }

            int topfreq = 0, top2freq = 0, first = -1, second = -1;
            for (auto a : st)
            {
                int currfreq = a.first + extra[a.second];
                if (currfreq > topfreq)
                {

                    top2freq = topfreq;
                    second = first;
                    topfreq = currfreq;
                    first = a.second;
                }
                else if (currfreq > top2freq)
                {
                    top2freq = currfreq;
                    second = a.second;
                }
            }

            if (topfreq == top2freq)
            {
                // tie its useless..

                cout << "No" << endl;
            }
            else
            {
                // now maybe x is winner !!

                if (first == x)
                {
                    cout << "Yes" << endl;
                }
                else
                    cout << "No" << endl;
            }
        }
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
    }
    return 0;
}
