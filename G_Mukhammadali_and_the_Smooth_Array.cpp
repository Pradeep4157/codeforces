#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:



    the final array shouldnt be striclty inc.. 

    just non - dec.. 

    in the traversals.. 

    we keep pushing the eles.. untill they are >=last ele .. 

    if the ele is somewhere in between then.. 

    we either push this ele in there and add the cost from that upper bound till end and make them all equal to arr[i]

    else make arr[i] == to the greatest and push it at the end.. 

    even if the costs are same.. 

    maybe it would be better to make it smaller ig .. 

    because later on also there might be comparsions which might make us think that we are not loosing anything but we could have made the peak

    smaller.. 

    


                        


            


    
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
        vector<int> arr(n), c(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
        }

    }
    return 0;
}
