#include <bits/stdc++.h>

using namespace std;
/*
        OBSERVATIONS:

        y mod x to be even they need to be of same parity


        for any x and y rem to be odd ..

        y%x == 0 or 2 or 4 or ..  z < x

        x*a + even_number = y

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
        vector<int> odd, even;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int first = -1, second = -1;
        for (int i = 0; i < min(n, 701); i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if ((arr[j] % arr[i]) % 2 == 0)
                {
                    first = arr[i];
                    second = arr[j];
                }
            }
        }
        if (first == -1)
        {
            for (int i = 701; i < min(1401, n); i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if ((arr[j] % arr[i]) % 2 == 0)
                    {
                        first = arr[i];
                        second = arr[j];
                    }
                }
            }
        }
        if (first == -1)
        {
            for (int i = 1401; i < min(2101, n); i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if ((arr[j] % arr[i]) % 2 == 0)
                    {
                        first = arr[i];
                        second = arr[j];
                    }
                }
            }
        }
        if (first == -1)
        {
            for (int i = 2101; i < min(2801, n); i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if ((arr[j] % arr[i]) % 2 == 0)
                    {
                        first = arr[i];
                        second = arr[j];
                    }
                }
            }
        }
        if (first == -1)
        {
            for (int i = 2801; i < min(3501, n); i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if ((arr[j] % arr[i]) % 2 == 0)
                    {
                        first = arr[i];
                        second = arr[j];
                    }
                }
            }
        }
        if (first == -1)
        {
            for (int i = 3501; i < min(4201, n); i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if ((arr[j] % arr[i]) % 2 == 0)
                    {
                        first = arr[i];
                        second = arr[j];
                    }
                }
            }
        }
        if (first == -1)
        {
            for (int i = 4201; i < min(4901, n); i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if ((arr[j] % arr[i]) % 2 == 0)
                    {
                        first = arr[i];
                        second = arr[j];
                    }
                }
            }
        }
        if (first == -1)
        {
            cout << -1 << endl;
        }
        else
            cout << first << " " << second << endl;
    }
    return 0;
}
