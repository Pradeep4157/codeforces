#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    only edge case that we found so far is that the freq of max element that is greater than 0 shouldn't be 1

    now if max element is 2 then we can place it at n-1th position or n-2 th position what about other cases

    what are the options that we have when freq[max element] == 3 ?

        we will have to place it at n - 3 th position

        no other position is going to satisfy ?

            lets check if we keep it at any position x before n - 3 then it will definitely have more elements
            after this including this exceeding the required freq

            and what about if i keep it some position x ahead of n - 3 then from max prefix we will recover n - i

            elements and that's it we wont get anything from suffix because all the elements to the right of this

            will be lesser than max element so we wont get shit from there

            so is this it ?

                there is only 1 case when freq of max element is not 2 and for freq == 2 there are 2 possibilities



    ANOTHER OBSERVATION :
        THERE IS NO NEED TO FILL THE ARRAY WILL VALUES THAT ARE NOT IN THE ARRAY

        THE MISSING POSITIONS CAN BE FILLED WITH ANY OF THE OCCURING ELEMENTS AND THAT WOULD NOT HARM THE CASE
        IN ANY WAY



    now how am i going to fill the array

    just calculate how much does the current arr[i] needs put that arr[i] at arr[i]-needs

    then after all this filling just fill the remaining elements with 1

    but is this needs going to be true always?

    lets say 4 needs 2 , 3 needs 2 , 1 needs 4


    its not that simple

    OK SO THE PROBLEM IS SIMPLE AF :
        we give the suffix array to 1 and prefix is for all the remaining elements

    ok so the only edge case that is not possible is that max element that needs to occur once

    because that last index is used by 1 for suffix filling

    ok all the other cases are done

    first we fill the last index of the array with 1 and then subtract mp[1]-=n
    and then we start traversing through the array and keep filling the indexes with the element's
    freq times and keep increasing the index

*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int freqoflast = 0;
        int n;
        cin >> n;
        vector<int> arr(n);
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] > 0)
            {
                freqoflast = arr[i];
                mp[i + 1] = arr[i];
            }
        }
        if (freqoflast == 1)
        {
            cout << -1 << endl;
            continue;
        }
        // else it is always possible

        vector<int> res(n);
        res[n - 1] = 1;
        // now keep filling all the elements
        mp[1] -= n;
        if (mp[1] == 0)
            mp.erase(1);
        int index = 0;
        for (auto a : mp)
        {
            int freq = a.second;
            while (freq)
            {
                freq--;
                res[index] = a.first;
                index++;
            }
        }
        res[n - 1] = 1;
        for (auto a : res)
            cout << a << ' ';
        cout << endl;
    }
    return 0;
}
