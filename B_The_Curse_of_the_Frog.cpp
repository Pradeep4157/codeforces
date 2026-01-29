#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    we can jump from k to any place from k to k + ai ..

    there are n types of jumps..

    so we will have to pay the price at lcm of all the bi's..

    else the remaining steps we can use something..

    so we will try to use the best for these bi steps and just divide it by x ..

    if from 1..bi sum is <= 0 then impossible..


    we keep using the max jump bi - 1 times then use some other jump where bj != bi


    i just take the best number and find the number of _ in its way to reach x ..

    now if i can fill these dashes with any other number then the no of dashes decrease..

    the only dashes that i need to fill are the lcm ones else i can fill with some other number..



*/
int updateLCM(int currentLCM, int nextNumber)
{
    return (currentLCM / __gcd(currentLCM, nextNumber)) * nextNumber;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<vector<int>> arr(n);
        int lcm = 1;
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            int first, second, third;
            cin >> first >> second >> third;
            maxi = max(maxi, first);
            lcm = updateLCM(lcm, second);
            arr[i].push_back(first);
            arr[i].push_back(second);
            arr[i].push_back(third);
        }
        int spaces = first / maxi;
        cout << lcm << endl;
    }
    return 0;
}
