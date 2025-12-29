#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so we choose a pref ..

    take any x we want and make

    all of them distinct..

    so one thing is sure that we are

    not going to prefix which includes

    two same arr[i] because that will

    change nothing..


    for occurences of arr[i] we will

    change at max till next occurence

    of arr[i] - 1 ..

    once a number is changed can it

    be same again ?


    i dont think so ..

    because its prefix we will select

    prev eles... as well..

    so in a map  we will keep

    all the indexess...

    and then ..

    for every arr[i] we will keep changing..

    till we reach.. max occuring freq - 1


    i dont think we even need to iterate..


    01020511

    010001

    we can store these in a set..

    so we keep a map we keep iterating till

    we get an element that is already

    present in the map ..

    now we do res ++

    allowed ++

    if that element freq exceeds allowed

    then we do allowed ++





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
        map<int, int> mp;
        int allowed = 1;
        int res = 0;
        int index = -1;
        for (int i = 0; i < n; i++)
        {
            int a = arr[i];
            if (mp.find(a) != mp.end())
            {
                res++;
                mp.clear();
            }
            mp[a]++;
        }
        cout << res << endl;
    }
    return 0;
}
