#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    so rabbits are present in every empty pot

    a rabbit wont jump only if one of the 2 conditions are satisfied:
        either opposite rabbit is looking to jump

        OR

        there is rabbit already

        if there is 2 or more continous blocks where flowers are present then rabbit
        can jump there
        so we will try to not make them face towards that side


        but if there is single cell surrounded by this config then it is
        impossible

        only edge case:
            if this is the first cell
            then we need to check whether the just beside one is more than one
            or not
            same for last cell

        if the size of empty cells is > 1 :
         we dont care



        so i have listed the definitely false  cases
        but still i need to prove that some combination exists


        now i need to do this from last and first

        i need to find first more than one size empty from size-1

        and


        i need to ifnd first more than one size empty from 0

        if both of them are even then it is possible else it is not possible


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
        if (n == 1)
        {
            cout << "YES" << endl;
            continue;
        }
        map<int, int> lr, rl;
        vector<pair<int, int>> empty;
        int i = 0;
        // creating flowers
        while (i < n)
        {
            while (i < n && s[i] == '0')
                i++;
            if (i == n)
                break;
            int j = i;
            while (j < n && s[j] == '1')
                j++;
            j--;
            lr[i] = j;
            rl[j] = i;
            i = j + 1;
        }
        i = 0;
        // creating empty ones
        while (i < n)
        {
            while (i < n && s[i] == '1')
                i++;
            if (i == n)
                break;
            int j = i;
            while (j < n && s[j] == '0')
                j++;
            j--;

            empty.push_back({i, j});
            i = j + 1;
        }
        bool ok = 1;
        int size = empty.size();
        if (size == 0)
        {
            cout << "YES" << endl;
            continue;
        }
        i = 0;
        vector<int> helper;
        for (; i < empty.size(); i++)
        {
            pair<int, int> a = empty[i];
            int left = a.first;
            int right = a.second;
            if (right - left >= 1)
            {
                continue;
            }
            // we have both the choices
            if (i > 0 && i < size - 1 && rl.count(left - 1) && lr.count(right + 1))
            {
                int prevstart = rl[left - 1];
                int prevend = left - 1;
                int nextstart = right + 1;
                int nextend = lr[nextstart];
                if (nextend - nextstart >= 1 && prevend - prevstart >= 1)
                {
                    // there is no choice
                    ok = false;
                    break;
                }
                // but this aint enough

                if (nextend - nextstart >= 1)
                {
                    // the only help is prev elee
                    if (helper.empty())
                    {
                        ok = false;
                        break;
                    }
                    else{

                        // it merged with prev rabbit 
                        helper.clear();

                        // and helper cleared because no other rabbit can help  
                        //him 
                    }
                }
                if (prevend - prevstart >= 1 )
                {
                    // the only help is next ele
                    i += 2;
                }
            }
            // either we are at end

            if (i == size - 1 && rl.count(left - 1) && right != n - 1)
            {
                // we depend on left ones
                int prevstart = rl[left - 1];
                int prevend = left - 1;
                if (prevend - prevstart >= 1 && right != n - 1)
                {
                    ok = false;
                    break;
                }
            }
            if (i == 0 && lr.count(right + 1) && left != 0)
            {
                // we depend on right ones
                int nextstart = right + 1;
                int nextend = lr[nextstart];
                if (nextend - nextstart >= 1)
                {
                    // they can jump
                    ok = false;
                    break;
                }
            }
            
        }

        vector<int> f, second;
        bool firstgot = 0, secondgot = 0;
        for (int i = 0; i < size; i++)
        {
            auto a = empty[i];
            int left = a.first;
            int right = a.second;
            if (right - left >= 1 || right == n - 1)
            {
                firstgot = 1;
                break;
            }
            else
                f.push_back(1);
        }
        for (int i = size - 1; i >= 0; i--)
        {
            auto a = empty[i];
            int left = a.first;
            int right = a.second;

            if (right - left >= 1 || left == 0)
            {
                secondgot = 1;
                break;
            }
            else
                second.push_back(1);
        }
        int s1 = f.size();
        int s2 = second.size();
        if (firstgot == false)
        {
            // if we are at the left border
            auto a = empty[0];
            if (a.first != 0 && (s1 & 1) && a.second != n - 1)
            {
                ok = false;
            }
        }
        if (secondgot == false)
        {
            auto a = empty[size - 1];
            if (a.second != n - 1 && (s2 & 1) && a.first != 0)
            {
                ok = false;
            }
        }
        cout << ((ok) ? "YES" : "NO") << endl;
    }
    return 0;
}
