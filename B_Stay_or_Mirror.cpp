#include<bits/stdc++.h>
#define int long long
using namespace std;
/*
PROBLEM:
    permutations is given..

    array of same size needs to be created.. 

    each i : 

        ai = pi or ai = 2n - pi 

    inversions needs to be minimized..

        OBSERVATIONS:
    
    n <= 5*1e3 .. 

    for n == 1 : 
        the inversions is 0 .. 

    same is for i ==  n - 1

    if we focus on operations.. 

        the range of numbers can be .. 

            from 1...n .... 2n-1 

    if i change any ai it has no effect on 

    any j > i like the inversion count of arr[j]

    wont change becuase of this .. 

    so if we start from last.. 

        
    for any i inversions till that index is : 

        inversion till j > i such that val[j]<val[i]
        
        so we can do dp[val[j]]+1;

        this is true but still this is just 

        no of inversions of val[i] what about 

        inversion of other indexes > i 

        do i need to add them here as well ?


        i think so.. 

        i cant simply add best inversion till 

        dp[i + 1] because we arent certain that 

        i + 1 considers this j as mirrored or normal..

        what if i get j == i + 1 

            for arr[i] == 1 : 

                what can happen to this .. 

                    res contribution from this ele is either elements before this becuase in all of them this is definitely there... 

                    else elements after this because this will become greatest element and all elements after this will 

*/
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t; 
    while(t--){

    }
    return 0;
}
