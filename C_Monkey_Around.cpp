#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so initially B is empty and what are the doing ?

    1) filling adding a permutation of length k

    or

    2) performing a left shift


    so how are we getting the permutation :

    1) if the current first element of the current permutation is 1 then the next permutation will start when b[i]<=b[i-1]

    but what if  1 2 3 5 1 2 3 4 yes it will work here also !!

    2) current permutation starts from some integer k then we go till we find k - 1

    and then write 2 k times

    the error we made was that the whole b rotates not only some permutation that we want to :

    so now we find the rotations we need to do after putting this permutation in the b array

    how do we do that it depends on the rotations that we are going to do after this if after all that if the current permutation is 1,2,.... k then ok else

    we add some here

    how do we know that :
        first element = (current_first_element + rotations)% size_of_permutation;

        push n first_element - 1 time in the ans array

        also n+=(first_element - 1)

        and continue

        AGAIN WRONG :(

        so we have some current_first_element that should be there and due to the next rotations it would have been lost now we need that back !

            how do we get that ?

                current_first_element = (first_element + rotations)%size

                if current_first_element == 0 - > size

                now we need to get first_element from current_first_element :

                we can do this using while loop

                    while(current_first_element!=first_element){
                        current_first_element++;
                        current_first_element%=size;
                        if(current_first_element == 0 ) current_first_element = size
                        along with this we will also keep pushing 2
                    }
*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("monkey_around_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    int index = 1;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; i++)
            cin >> b[i];
        cout << "Case #" << index++ << ": ";
        int i = 0;
        vector<vector<int>> res;
        while (i < n)
        {
            if (b[i] == 1)
            {
                // we go till arr[i]<=arr[i-1]
                int j = i + 1;
                while (j < n && b[j] == b[j - 1] + 1)
                {
                    j++;
                }

                res.push_back({1, 1, j - i});
                i = j;
                // no left cycle shifts required
            }
            else
            {
                int j = i + 1;
                while (j < n && b[j] != b[i] - 1)
                {
                    j++;
                }
                res.push_back({1, b[i], j - i + 1});
                i = j + 1;
            }
        }
        reverse(res.begin(), res.end());
        vector<vector<int>> ans;
        int rotations = 0;
        for (int i = 0; i < res.size(); i++)
        {
            int first_element = res[i][1];
            int size1 = res[i][2];
            int current_first_element = (1 + rotations) % size1;
            current_first_element = (current_first_element == 0) ? size1 : current_first_element;

            while (current_first_element != first_element)
            {
                current_first_element++;
                rotations++;
                current_first_element %= size1;
                if (current_first_element == 0)
                    current_first_element = size1;
                ans.push_back({2});
            }
            ans.push_back({1, size1});
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (auto a : ans)
        {
            for (auto b : a)
                cout << b << " ";
            cout << endl;
        }
    }
    return 0;
}
