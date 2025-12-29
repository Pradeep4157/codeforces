#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    if its greater then push back..

    else if lesser push front..

    when it is equal we dont know yet..

    ab
    abc
    here also i will want to push it to the back..

    so even the len is greater than also i will push back..



    abb
    abba
    cba

    abbaabb





*/
bool find(string first, string second)
{

    string temp1 = first + second;
    string temp2 = second + first;
    for (int i = 0; i < temp2.size(); i++)
    {
        if (temp1[i] < temp2[i])
            return true;
        else if (temp1[i] > temp2[i])
            return false;
    }
    return false;
}
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
        vector<string> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        string res;
        res = arr[0];
        for (int i = 1; i < n; i++)
        {
            bool isgreater = find(res, arr[i]);
            if (isgreater)
                res += arr[i];
            else
                res = arr[i] + res;
        }
        cout << res << endl;
    }
    return 0;
}
