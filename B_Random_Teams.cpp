#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    classic greedy maximization problem:
        here to maximize the res i will keep 1 player in n-1 teams in the last team i will put players-teams-1
        and the answer=players-(teams-1)-1!

        and to minimize the result:
            equally distribute the participants in all the teams so that the factorial is at minimum


    10 4
    for mini 2 2 2 4
    6+ 1+ 1+ 1= 9
    2 2 3 3
    1+ 1+ 3+ 3


    so the mistake that is being made is that i am adding all the extra players in a single team which
    increases the min answer

    instead i should give each of those extra players to some team


*/
int factorial(int n)
{
    if (n == 0)
        return 0;
    return (n * (n + 1)) / 2;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int players, teams;
    cin >> players >> teams;
    int maxi = factorial(players - teams);
    int mini = 0;
    int playersperteam = players / teams;
    int teams1 = teams - (players % teams);
    int teams2 = teams - teams1;
    mini += factorial(playersperteam - 1) * teams1;
    mini += factorial(playersperteam) * teams2;
    cout << mini << " " << maxi << endl;
    return 0;
}
