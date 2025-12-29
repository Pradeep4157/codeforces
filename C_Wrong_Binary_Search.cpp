#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    x is something that i will definitely find in the permutation

    so in the  binary string if s[i] is 1 it should be stable
    else it should not be stable

    so the values  need to  sorted so that
        when we are at a ranom index > i right should be decreased
        that will happen only when arr[index]>arr[i]

        and when index<i left=mid+1 that will happen when
        arr[index]<arr[i]

    so the logic is that if i have a single zero then its impossible

    else i will just swap the current ele with its greater ele


    should i always hold no matter what m is or is it

    plan:
        if s[i]==1;
        just fill the ele

        else s[i]=ele+1;

        s[i+1]=ele
        i++


        so for continous 0's subarray reverse all of them
        and return



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
        map<int, int> zeroes;
        int i = 0;
        bool ok = 1;
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
            if (j - i == 0)
            {
                ok = false;
                break;
            }
            zeroes[i] = j;
            i = j + 1;
        }
        if (ok == false)
        {
            cout << "NO" << endl;
            continue;
        }
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            arr[i] = i + 1;
        }
        cout << "YES" << endl;
        i = 0;
        while (i < n)
        {
            if (s[i] == '1')
            {
                cout << arr[i] << ' ';
                i++;
                continue;
            }
            // here i will have to reverse this
            int end = zeroes[i];
            for (int j = end; j >= i; j--)
            {
                cout << arr[j] << ' ';
            }
            i = end + 1;
        }
        cout << endl;
    }
    return 0;
}
