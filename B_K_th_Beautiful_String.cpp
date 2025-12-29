#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
    there are only two b's and remaining are a's


    at every step the total combinations that are going to be made=size*(size-1)/2

    so we just need size variable and count of b's

    playerspersegment=total/size

    when i do k/playerspersegment , i get to know in which segment k is

    if b is 1 and k is at the last segment:
        fill this as b and break

    if b is 2 and k is at last or second last segment then fill this as b and bcount--

    how is k going to change after this?
        after this operation k will have to be one of the playerperteam so k%=playersperteam

    after this if size>=1 then keep filling them with a


    WHAT ACTUALLY HAPPENS:
        how does k change??

        for n distinct permutations k should be among them

        and after this k should be  among letter remaining! so we reduce k to k% ( letters remaining !)

        here all char arent distinct

        so we need to calculate letters remaining  factorial and then divide the same letter combinations factorial that it made


        and maybe later i will have to multiply with inv factorial of a and b instead of dividing it with factorial of a and b


        this is not how k gets compressed although it gets compressed to one of those but the value of k
        is still not correct



        ITS WRONG:

        because we just not have to compress k to factorial[n-i-1] but place at its exact position
        where it should be

        if it belongs to some first char permutation its fine because it is already at its correct position

        but if it belongs to some other char apart from this we need to remove the top char permutations
        so that k places at its correct permutation in that charecter



        and how do we test that whether k is of this permutation:

            it would be less than all possible permutations if use this char




        these all will give wrong answer :(

        why because mod will give some wrong terms and all that

        but here there was an observation that we could have made for the 2 b's first we will track the position

        of the first b , that is the left one , then once we get that we will get the right one

        HOW WILL WE GET THE LEFT ONE ?

        using the formual n-1-i , here i starts n - 2 and goes on till the strings we have passed is about to exceed

        k or not

        once we are in that segment first we put b at this index and then

        HOW WILL WE GET THE RIGHT ONE ?

        now we are in this segment and we just need to subtract k - numbers that we skipped till now

        and what ever result we get we just place b at index + dist + 1 position

        remaining all will be just a's



*/

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        k--;
        int index = n - 2;
        int passed = 0;
        while (true)
        {
            int stringstopass = n - 1 - index;
            if (stringstopass + passed <= k)
            {
                passed += stringstopass;
                index--;
            }
            else
                break;
        }
        string s(n, 'a');
        s[index] = 'b';
        int rem = n - index - 1;
        s[index + rem - (k - passed)] = 'b';

        cout << s << endl;
    }
    return 0;
}
