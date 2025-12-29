#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    abs value of sum of elements of diff array should be min...

    rem sum will  be same..

    if i use bi as 0 ..

    if bi is at the end..

    then i will use  bi as 0..

    so the total sum should be as close to 0 as possible..


    only case where i can do something is when x is 0 or end ..

    at any other place its useless because it will get subtracted again..

    if there is no - 1 then we just return the array..

    else we can just write the first eleement ..

    in that x..

    cause that is only getting extra..

    also the last ele ..

    it is meaningless to do  if it is at 1..n -2 .

    but if its at 0 then also no need.

    if -1 is at n -1 then make it arr[0]



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

        bool found = false;
        int index = -1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == -1)
            {
                found = 1;
                index = i;
            }
        }
        if (found == false)
        {
            int sum = 0;
            for (int i = 1; i < n; i++)
            {
                sum += (arr[i] - arr[i - 1]);
            }
            cout << abs(sum) << endl;
            for (auto a : arr)
                cout << a << " ";
            cout << endl;
        }
        else
        {
            int curr = 0;
            if (index == n - 1)
            {
                // then only we will do..
                if (arr[0] != -1)
                    curr += arr[0];
                arr[index] = curr;
            }
            if (arr[0] == -1)
            {
                if (arr[n - 1] != -1)
                    arr[0] = arr[n - 1];
            }
            for (int i = 0; i < n; i++)
                if (arr[i] == -1)
                    arr[i] = 0;
            int sum = 0;
            for (int i = 1; i < n; i++)
            {
                sum += (arr[i] - arr[i - 1]);
            }
            cout << abs(sum) << endl;
            for (auto a : arr)
                cout << a << " ";
            cout << endl;
        }
    }
    return 0;
}
