#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    is si = 1 :
        some subarray of len i where max ele..

        is i .

    else:
        for all subarrays of len i :
    max ele shouldnt be i ..

    if s1 = 0 :

        then it is impossible because 1 len

        would be the no itself so it cant be saved..


    else if s1 = 1:
        place 1 anywhere it will satisfy . .


    similar case is with n :
        is sn = 0 :
            then also it is impossible because

            there's only one subarray and

            in that afc .. n is maxx..


    if i keep  the array sorted :

        then for all i where si is 1 :
            max case is acheived because :

                from 0.. i :

                    this number is max :

        but for si = 0 :

            only 1 case where max is acheived is :

                from   1.. i

        we can just swap it with the next 1 that is

        present..

        and if there isnt any 1 present then ok

        is false and return false

    this method although ensures that si = 0 :

        doesnt get any max ele ..

            but in some cases it makes si = 1:

                not max in any subarray

        i dont need to swap till last index used > i
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
        string s;
        cin >> s;
        vector<int> indexes;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                indexes.push_back(i);
            }
        }
        bool ok = 1;
        int size = indexes.size();
        if (s[0] == '0' || s[n - 1] == '0')
            ok = false;
        if (ok == false)
        {
            cout << -1 << endl;
            continue;
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++)
            res[i] = i + 1;
        int index = 0;
        for (int i = 0; i < n; i++)
        {

            // now index> i
            if (s[i] == '1')
                continue;
            else
            {

                if (indexes[index] > i)
                    continue; // no need of swap ..

                while (index < size && indexes[index] <= i)
                    index++;
                if (index == size)
                {
                    // we dint get any ..
                    ok = false;
                    break;
                }
                // now we can swap ..
                swap(res[i], res[indexes[index]]);
            }
        }
        if (ok == false)
            cout << -1 << endl;
        else
        {
            for (auto a : res)
                cout << a << " ";
            cout << endl;
        }
    }
    return 0;
}
