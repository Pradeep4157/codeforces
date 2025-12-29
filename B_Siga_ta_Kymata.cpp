#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    p is given, x is given..

    i need to convert s to x in 5 operations ..

    to do so  i will select l , r same index doesnt make any sense because we need

    to set some si  == 1


    at the end wherever xi == 1  we need to make si == 1

    so what is impossible ..

    if the ends are 1 then it is impossible..

    any i between if i want to change...

    if it is min / max of the array then also it is impossible..

    else we can convert using taking the whole array ..


    since we can have extra ones so it doesnt matter if i

    change or add extra ones..

    can first or last element be set 1 . .

    no because i that can be changed should be within

    l and r and pi shouldnt be min or max of the permutation..

    if xi is 1 then si should also be 1 ..


    if xi is 0.. then si can be anything...

    if si is 0 that does that mean xi  should also be 0

    so maybe we need to take ranges carefully..


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
        string x;
        cin >> x;
        bool ok = 1;
        if (x[0] == '1' || x[n - 1] == '1')
            ok = false;
        for (int i = 1; i < n - 1; i++)
        {
            if (x[i] == '1' && (arr[i] == 1 || arr[i] == n))
                ok = false;
        }
        int mini = 0, maxi = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 1)
                mini = i + 1;
            if (arr[i] == n)
                maxi = i + 1;
        }
        if (ok == false)
        {
            cout << -1 << endl;
        }
        else
        {
            if (mini > maxi)
                swap(mini, maxi);
            cout << 5 << endl;
            cout << mini << " " << maxi << endl;
            cout << 1 << " " << mini << endl;
            cout << 1 << " " << maxi << endl;
            cout << mini << " " << n << endl;
            cout << maxi << " " << n << endl;
        }
    }
    return 0;
}
