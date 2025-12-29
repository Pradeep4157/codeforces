#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    they play some xor game..

    at odd turns ajisai can swap ai,bi same for mai..

    at the end ajisai's score is a xorr, mai's score is b xorr.

    here ai,bi <= 1...

    so for this case..

    if ajisai wants to win..

    she needs odd number  of ones..

    else if she cant get odd number of ones.. then

    if mai also does not have odd number of ones..

    then both tie..

    one more tie case is that when both of them have

    odd ones..

    this is only poassible when n is odd ?

    no this can also happend when n is even...

    now will ajisai try to take some ones to win..

    no because no matter what she does at the end if the

    if mai's odd are done then she will have to take even more

    to make her odd which makes mai's total still even only..

    so ajisai's only goal is to make odd ones..

    that's all ..

    so if both of them have odd ones its a tie..

    and also if both of them have even ones and the places are there

    then also tie..

    else :

        only one has odd..

        they have to defend their odds..

        so..

        if the places from which they can take >= opp

        then win else loose..

    if both have odd or even it doesnt matter because no matter

    what swap they do they will still have the same moded sum..


    else the odd ones will have to defend their ones..



    if mai is loosing that means she has even ones. .

    so she need odd swps so if second is even then second --


    when the parity is same no matter what you do the parity

    of both is going to be same only...

    fijeaiowefjioawejfio








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
        vector<int> arr(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        int aji = 0, mai = 0;
        for (auto a : arr)
            if (a == 1)
                aji++;
        for (auto a : b)
            if (a == 1)
                mai++;
        if (aji % 2 == mai % 2)
        {

            cout << "Tie" << endl;
        }
        else
        {
            // now only one will win..

            if (aji % 2)
            {
                // now aji has to defend..
                int first = 0, second = 0;
                for (int i = 0; i < n; i += 2)
                {
                    if (arr[i] != b[i])
                    {
                        first++;
                    }
                }
                for (int i = 1; i < n; i += 2)
                {
                    if (arr[i] != b[i])
                        second++;
                }

                if (first >= second)
                    cout << "Ajisai" << endl;
                else
                    cout << "Mai" << endl;
            }
            else
            {

                int first = 0, second = 0;
                for (int i = 0; i < n; i += 2)
                {
                    if (arr[i] != b[i])
                    {
                        first++;
                    }
                }
                for (int i = 1; i < n; i += 2)
                {
                    if (arr[i] != b[i])
                        second++;
                }

                if (first <= second)
                    cout << "Mai" << endl;
                else
                    cout << "Ajisai" << endl;
            }
        }
    }
    return 0;
}
