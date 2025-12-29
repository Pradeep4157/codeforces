#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    how do we find l and r ?


    we have 40 queries :

    and i think in a single go we will ask for both p and a

    because then only we will know the diff

    so i think first we will find l and then we will find r


    using binary search

    how ?

    for l we will have some mid

    we will ask for 1 1 mid  && 2 1 mid

    if both of them are same then l starts somewhere to  the

    right side

    similarly for r also we will ask for

    1 mid n && 2 mid n

    now if the sums are same then high = mid - 1

    else low = mid + 1


    so here the approach of bs is correct to find l but it itself takes 28 queries so we cant do  the same to find r

    how do we find r in only 1 query ?




*/
int na(int left, int right)
{
    cout << 1 << " " << left << " " << right << endl;
    int sum;
    cin >> sum;
    return sum;
}
int ma(int left, int right)
{
    cout << 2 << " " << left << " " << right << endl;
    int sum;
    cin >> sum;
    return sum;
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
        // now first we try to find l
        int left = 1, right = n;
        int low = 1, high = n;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int first = na(1, mid);
            int second = ma(1, mid);
            if (first == second)
            {
                // then range is somewhere in the right
                low = mid + 1;
            }
            else
            {
                left = mid;
                high = mid - 1;
            }
        }
        int masum = ma(1, n);
        masum -= (n * (n + 1)) / 2;
        right = left + masum - 1;
        cout << "! " << left << " " << right << endl;
    }
    return 0;
}