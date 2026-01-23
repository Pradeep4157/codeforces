#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    the goal is to save 0..k-2..

    the max mex that i can save is k-1..

    every time i select a window of size k..

    so the error was that we can increase the mex value ..

    is that the only mistake ..

    there are 2 options :

        for every k sized array if the mex == k + 1..

        then we remove the biggest element

        else :
            we remove the extra number..

    at the end there is going to be k - 1 elements..

    if i focus on the part where the mex < k - 1..

        then i can see whether any array can be converted from x ... x + y ..

        so in this case there is going to be elements removed which will be mostly from the left / right

        ends so that new elements come in and increase the mex..

        mostly if i get mex answer  == k + 1 :

            then  it is def that we keep removing the max element and at the end the elements

            left = 0,1,2,3....k-2

        else :

            there is chance that we remove





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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        set<int> st;
        for (int i = 0; i < n; i++)
        {
            if (st.count(arr[i]))
                continue;
            else
            {
                st.insert(arr[i]);
            }
        }
        int res = 0;
        for (int i = 0; i < k - 1; i++)
        {
            if (!st.count(i))
                break;
            res++;
        }
        cout << res << endl;
    }
    return 0;
}